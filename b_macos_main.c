// we don't need much here
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <mach-o/dyld.h>
#include <OpenGL/gl.h>
#include <dlfcn.h>
#include "betray.h"

#include "macos/c-ocoa/nsapplication.c"
#include "macos/c-ocoa/nswindow.c"
#include "macos/c-ocoa/nscolor.c"
#include "macos/c-ocoa/nsprocessinfo.c"
#include "macos/c-ocoa/nsmenu.c"
#include "macos/c-ocoa/nsmenuitem.c"
#include "macos/c-ocoa/nsscreen.c"
#include "macos/c-ocoa/nsarray.c"
#include "macos/c-ocoa/nsobject.c"
#include "macos/c-ocoa/nsview.c"
#include "macos/c-ocoa/nsopenglpixelformat.c"
#include "macos/c-ocoa/nsopenglcontext.c"
#include "macos/c-ocoa/nsstring.c"
#include "macos/c-ocoa/nsdate.c"
#include "macos/c-ocoa/nsevent.c"
#include "macos/c-ocoa/uifont.c"

bool terminated = false;
uint32_t windowCount = 0;

// we gonna construct objective-c class by hand in runtime, so wow, so hacker!
//@interface AppDelegate : NSObject<NSApplicationDelegate>
//-(NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender;
//@end
//@implementation AppDelegate
//-(NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender
//{
//	terminated = true;
//	return NSTerminateCancel;
//}
//@end
NSUInteger applicationShouldTerminate(id self, SEL _sel, id sender)
{
	printf("requested to terminate\n");
	terminated = true;
	return 0;
}

//@interface WindowDelegate : NSObject<NSWindowDelegate>
//-(void)windowWillClose:(NSNotification*)notification;
//@end
//@implementation WindowDelegate
//-(void)windowWillClose:(NSNotification*)notification
//{
//	(void)notification;
//	assert(windowCount);
//	if(--windowCount == 0)
//		terminated = true;
//}
//@end

id betray_opengl_context_default;
id betray_opengl_context_current;
id betray_content_view;
id betray_window;

uint betray_screen_screen_resolution_x = 0;
uint betray_screen_screen_resolution_y = 0;

uint betray_user_id;
uint betray_scroll_axis_id = -1;
uint betray_mouse_device_id = -1;
uint betray_mouse_pointer_id = -1;
uint betray_keyboard_device_id = -1;

extern uint betray_plugin_user_allocate();
extern uint betray_plugin_input_device_allocate(uint user_id, char *name);
extern uint betray_plugin_pointer_allocate(uint user_id, uint device_id, uint button_count, float x, float y, float z, float *origin, char *name, boolean draw);
extern uint betray_plugin_axis_allocate(uint user_id, uint device_id, char *name, BAxisType type, uint axis_count);
extern void betray_plugin_axis_set(uint id, float axis_x, float axis_y, float axis_z);
extern void betray_plugin_callback_main(BInputState *input);
extern void betray_reshape_view(uint x_size, uint y_size);
extern void betray_action(BActionMode mode);
extern void betray_time_update();

void betray_device_init()
{
    betray_user_id = betray_plugin_user_allocate();
    betray_mouse_device_id = betray_plugin_input_device_allocate(0, "Mouse");
    betray_keyboard_device_id = betray_plugin_input_device_allocate(0, "Keyboard");
    betray_mouse_pointer_id = betray_plugin_pointer_allocate(betray_user_id, betray_mouse_device_id, 3, 0.0, 0.0, -1, NULL, "Mouse", FALSE);
    betray_scroll_axis_id = betray_plugin_axis_allocate(0, betray_mouse_device_id, "Scroll", B_AXIS_SCORLL, 2);
}

void windowWillClose(id self, SEL _sel, id notification)
{
	printf("window will close\n");
	assert(windowCount);
	if(--windowCount == 0)
		terminated = true;
}


//extern boolean b_win32_init_display_opengles2(uint size_x, uint size_y, boolean full_screen, uint samples, char *caption, boolean *sterioscopic);

boolean b_init_display_opengl(uint size_x, uint size_y, boolean full_screen, uint samples, char *caption, boolean *sterioscopic)
{
    uint i;
	SEL allocSel = sel_registerName("alloc");
    SEL initSel = sel_registerName("init");
    SEL releaseSel = sel_registerName("release");
    //NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    /*
    Class NSAutoreleasePoolClass = objc_getClass("NSAutoreleasePool");
    id poolAlloc = ((id (*)(Class, SEL))objc_msgSend)(NSAutoreleasePoolClass, allocSel);
    id pool = ((id (*)(id, SEL))objc_msgSend)(poolAlloc, initSel);
    */

	nsapplication_t nsapp = nsapplication_sharedApplication();
	nsapplication_setActivationPolicy(nsapp, 0);

	//AppDelegate * dg = [[AppDelegate alloc] init];
	Class NSObjectClass = objc_getClass("NSObject");
	Class AppDelegateClass = objc_allocateClassPair(NSObjectClass, "AppDelegateOR", 0);
    Protocol* NSApplicationDelegateProtocol = objc_getProtocol("NSApplicationDelegate");
	bool resultAddProtoc = class_addProtocol(AppDelegateClass, NSApplicationDelegateProtocol);
//	assert(resultAddProtoc);
	SEL applicationShouldTerminateSel = sel_registerName("applicationShouldTerminate:");
	bool resultAddMethod = class_addMethod(AppDelegateClass, applicationShouldTerminateSel, (IMP)applicationShouldTerminate, NSUIntegerEncoding "@:@");
	assert(resultAddMethod);
	id dgAlloc = ((id (*)(Class, SEL))objc_msgSend)(AppDelegateClass, allocSel);
	id dg = ((id (*)(id, SEL))objc_msgSend)(dgAlloc, initSel);

	SEL autoreleaseSel = sel_registerName("autorelease");
	((void (*)(id, SEL))objc_msgSend)(dg, autoreleaseSel);

	nsapplication_setDelegate( nsapp, dg );

	// only needed if we don't use [NSApp run]
	//[NSApp finishLaunching];
	nsapplication_finishLaunching( nsapp );

	//id menubar = [[NSMenu alloc] init];
	nsmenu_t menubar = nsmenu_init( nsmenu_alloc() );
	nsmenu_autorelease( menubar );

	//id appMenuItem = [[NSMenuItem alloc] init];
	nsmenuitem_t appMenuItem = nsmenuitem_init( nsmenuitem_alloc() );
	nsmenuitem_autorelease( appMenuItem );

	//[menubar addItem:appMenuItem];
	nsmenu_addItem( appMenuItem );

	//[NSApp setMainMenu:menubar];
	nsapplication_setMainMenu( menubar );

	//id appMenu = [[NSMenu alloc] init];
	nsmenu_t appMenu = nsmenu_init( nsmenu_alloc() );
	nsmenu_autorelease( appMenu );

	//id appName = [[NSProcessInfo processInfo] processName];
	nsprocessinfo_t processInfo = nsprocessinfo_processInfo();
	nsstring_t appName = nsprocessinfo_processName(processInfo);

	//id quitTitle = [@"Quit " stringByAppendingString:appName];
	nsstring_t quitTitlePrefix = nsstring_stringWithUTF8String( "Quit " );
    nsstring_t quitTitle = nsstring_stringByAppendingString( quitTitlePrefix, appName );
    
	//id quitMenuItem = [[NSMenuItem alloc] initWithTitle:quitTitle action:@selector(terminate:) keyEquivalent:@"q"];
	nsstring_t quitMenuItemKey = nsstring_stringWithUTF8String( "q" );
    nsmenuitem_t quitMenuItem = nsmenuitem_initWithTitle( nsmenuitem_alloc(), quitTitle, sel_registerName("terminate:"), quitMenuItemKey );

	//[appMenu addItem:quitMenuItem];
	nsmenu_addItem( appMenu, quitMenuItem );

	//[appMenuItem setSubmenu:appMenu];
	nsmenuitem_setSubmenu( appMenuItem, appMenu );

    nsapplication_finishLaunching( nsapp );


    nsscreen_t mainScreen = nsscreen_mainScreen();
    nsarray_t screens = nsscreen_screens();
    unsigned long long screenCount = nsarray_count( screens );
    nsscreen_t specificScreen = nsarray_objectAtIndex( screens, 0u );
    CGRect frameRect = nsscreen_frame( mainScreen );

    betray_screen_screen_resolution_x = frameRect.member1.member0;
    betray_screen_screen_resolution_y = frameRect.member1.member1;

    nswindow_t betrayWindow = nswindow_initWithContentRect( nswindow_alloc(), frameRect, 15, 2, NO );
    
    nsobject_autorelease( betrayWindow );

    nswindow_setReleasedWhenClosed( betrayWindow, NO );

    nsview_t betrayContentView = nswindow_contentView( betrayWindow );
    nsview_setWantsBestResolutionOpenGLSurface( betrayContentView, YES );

    CGPoint point = {0, 0};

    if(size_x != 0)
      point.member0 = (betray_screen_screen_resolution_x - size_x) / 2;
    if(size_y != 0)
       point.member1 = (betray_screen_screen_resolution_y + size_y) / 2;

    nswindow_cascadeTopLeftFromPoint( betrayWindow, point );

    nsopenglcontext_t openglContextDefault = NULL;
    for(uint32_t i = 0; i < 3; i++)
    {
        uint32_t glAttributes[] = {
		8, 24,
		11, 8,
		5,
		73,
		72,
		55, 1,
        56, 4,
        99, 0x3200, // or 0x1000 0x3200 0x4100
     // 99, 0x4100, // or 0x1000 0x3200 0x4100
		0};
        uint32_t version[] = {0x4100, 0x3200, 0x1000};
        glAttributes[12] = version[i];
        
        nsopenglpixelformat_t pixelFormat = nsopenglpixelformat_initWithAttributes( nsopenglpixelformat_alloc(), glAttributes );
        nsobject_autorelease( pixelFormat );
        
        openglContextDefault = nsopenglcontext_initWithFormat( nsopenglcontext_alloc(), pixelFormat, nil );
        if( openglContextDefault != NULL )
        {
            break;
        }
    }

    if( openglContextDefault == NULL )
    {
        return FALSE;
    }

    nsobject_autorelease( openglContextDefault );
    nsopenglcontext_setView( openglContextDefault, betrayContentView );

    nsstring_t caption = nsstring_stringWithUTF8String( "Hello from C-Ocoa" );
    nswindow_setTitle( betrayWindow, caption );

    nswindow_makeKeyAndOrderFront( betrayWindow, betrayWindow );
    nswindow_setAcceptsMouseMovedEvents( betrayWindow, YES );
    nswindow_setBackgroundColor( betrayWindow, nscolor_blackColor() );

    nsapplication_activateIgnoringOtherApps( nsapp, YES );

    nsopenglcontext_makeCurrentContext( openglContextDefault );
    nsapplication_setPresentationOptions( nsapp, (1<<10) );

    return TRUE;
}

void betray_launch_main_loop(void)
{
    SEL allocSel = sel_registerName("alloc");
    SEL initSel = sel_registerName("init");
    SEL releaseSel = sel_registerName("release");
    SEL drainSel = sel_registerName("drain");
    SEL autoreleaseSel = sel_registerName("autorelease");
    //NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    Class NSAutoreleasePoolClass = objc_getClass("NSAutoreleasePool");
    /*
    id poolAlloc = ((id (*)(Class, SEL))objc_msgSend)(NSAutoreleasePoolClass, allocSel);
    id pool = ((id (*)(id, SEL))objc_msgSend)(poolAlloc, initSel);
    */

    static uint32 last_modifyer_keys = 0;
    BInputState *input;
    uint i, j, event_timer = 0;
    input = betray_get_input_state();
	printf("entering runloop\n");
	Class NSDateClass = objc_getClass("NSDate");
	SEL distantPastSel = sel_registerName("distantPast");
	SEL nextEventMatchingMaskSel = sel_registerName("nextEventMatchingMask:untilDate:inMode:dequeue:");
	SEL frameSel = sel_registerName("frame");
	SEL typeSel = sel_registerName("type");
	SEL buttonNumberSel = sel_registerName("buttonNumber");
	SEL keyCodeSel = sel_registerName("keyCode");
	SEL keyWindowSel = sel_registerName("keyWindow");
	SEL mouseLocationOutsideOfEventStreamSel = sel_registerName("mouseLocationOutsideOfEventStream");
	SEL convertRectToBackingSel = sel_registerName("convertRectToBacking:");
	SEL scrollingDeltaXSel = sel_registerName("scrollingDeltaX");
	SEL scrollingDeltaYSel = sel_registerName("scrollingDeltaY");
	SEL hasPreciseScrollingDeltasSel = sel_registerName("hasPreciseScrollingDeltas");
	SEL modifierFlagsSel = sel_registerName("modifierFlags");
	SEL charactersSel = sel_registerName("characters");
	SEL UTF8StringSel = sel_registerName("UTF8String");
	SEL sendEventSel = sel_registerName("sendEvent:");
	SEL updateWindowsSel = sel_registerName("updateWindows");
	SEL updateSel = sel_registerName("update");
	SEL makeCurrentContextSel = sel_registerName("makeCurrentContext");
    SEL flushBufferSel = sel_registerName("flushBuffer");
    SEL contentViewSel = sel_registerName("contentView");

	while(!terminated)
    {
        // [pool drain];
        // pool = [[NSAutoreleasePool alloc] init];
        /*
        ((void (*)(id, SEL))objc_msgSend)(pool, drainSel);
        id poolAlloc = ((id (*)(Class, SEL))objc_msgSend)(NSAutoreleasePoolClass, allocSel);
        pool = ((id (*)(id, SEL))objc_msgSend)(poolAlloc, initSel);
        */
        
		//NSEvent * event = [NSApp nextEventMatchingMask:NSAnyEventMask untilDate:[NSDate distantPast] inMode:NSDefaultRunLoopMode dequeue:YES];
		id distantPast = ((id (*)(Class, SEL))objc_msgSend)(NSDateClass, distantPastSel);
        id event;

		while((event = ((id (*)(id, SEL, NSUInteger, id, id, BOOL))objc_msgSend)(NSApp, nextEventMatchingMaskSel, NSUIntegerMax, distantPast, NSDefaultRunLoopMode, YES)) != NULL)
		{
            event_timer = 0;
			//NSEventType eventType = [event type];
			NSUInteger eventType = ((NSUInteger (*)(id, SEL))objc_msgSend)(event, typeSel);

			switch(eventType)
			{
				//case NSMouseMoved:
				//case NSLeftMouseDragged:
				//case NSRightMouseDragged:
				//case NSOtherMouseDragged:
				case 5:
				case 6:
				case 7:
				case 27:
				{
					//NSRect adjustFrame = [[currentWindow contentView] frame];
					id currentWindowContentView = ((id (*)(id, SEL))objc_msgSend)(betray_window, contentViewSel);
					NSRect adjustFrame = ((NSRect (*)(id, SEL))abi_objc_msgSend_stret)(betray_content_view, frameSel);

					//NSPoint p = [currentWindow mouseLocationOutsideOfEventStream];
					// NSPoint is small enough to fit a register, so no need for objc_msgSend_stret
					NSPoint p = ((NSPoint (*)(id, SEL))objc_msgSend)(betray_window, mouseLocationOutsideOfEventStreamSel);

					// map input to content view rect
					if(p.x < 0)
                        p.x = 0;
					else if(p.x > adjustFrame.size.width)
                        p.x = adjustFrame.size.width;
					if(p.y < 0)
                        p.y = 0;
					else if(p.y > adjustFrame.size.height)
                        p.y = adjustFrame.size.height;
                    input->pointers[0].pointer_x = (float)p.x / (float)adjustFrame.size.width * 2.0 - 1.0;
                    input->pointers[0].pointer_y = (-1.0 + (float)p.y / (float)adjustFrame.size.height * 2.0) * (float)adjustFrame.size.height / (float)adjustFrame.size.width;

					// map input to pixels
					NSRect r = {p.x, p.y, 0, 0};
					//r = [currentWindowContentView convertRectToBacking:r];
					r = ((NSRect (*)(id, SEL, NSRect))abi_objc_msgSend_stret)(currentWindowContentView, convertRectToBackingSel, r);
					p = r.origin;

					printf("mouse moved to %f %f\n", p.x, p.y);
					
				}
                break;
				//case NSLeftMouseDown:
                case 1:
                    input->pointers[0].button[0] = TRUE;
					printf("mouse left key down\n");
				break;
				//case :
				case 2:
                    input->pointers[0].button[0] = FALSE;
					printf("mouse left key up\n");
				break;
				//case NSRightMouseDown:
                case 3:
                    input->pointers[0].button[1] = TRUE;
					printf("mouse right key down\n");
				break;
				//case NSRightMouseUp:
                case 4:
                    input->pointers[0].button[1] = FALSE;
					printf("mouse right key up\n");
				break;
				//case NSOtherMouseDown:
				case 25:
				{
					// number == 2 is a middle button
					//NSInteger number = [event buttonNumber];
                    NSInteger number = ((NSInteger (*)(id, SEL))objc_msgSend)(event, buttonNumberSel);
                    if(number < B_POINTER_BUTTONS_COUNT)
                        input->pointers[0].button[number] = TRUE;
					printf("mouse other key down : %i\n", (int)number);
				}
                break;
				//case NSOtherMouseUp:
				case 26:
				{
					//NSInteger number = [event buttonNumber];
					NSInteger number = ((NSInteger (*)(id, SEL))objc_msgSend)(event, buttonNumberSel);
                    if(number < B_POINTER_BUTTONS_COUNT)
                        input->pointers[0].button[number] = FALSE;
				}
                break;
				//case NSScrollWheel:
				case 22:
				{
                    CGFloat delta_x, delta_y;
                    BOOL precision_scrolling;
					delta_x = ((CGFloat (*)(id, SEL))abi_objc_msgSend_fpret)(event, scrollingDeltaXSel);
					delta_y = ((CGFloat (*)(id, SEL))abi_objc_msgSend_fpret)(event, scrollingDeltaYSel);
					precision_scrolling = ((BOOL (*)(id, SEL))objc_msgSend)(event, hasPreciseScrollingDeltasSel);
					if(precision_scrolling)
					{
						delta_x *= 0.1f; // similar to glfw
						delta_y *= 0.1f;
                    }
                    if(delta_x >= 0.001)
                        betray_plugin_button_set(0, BETRAY_BUTTON_SCROLL_UP, TRUE, -1);
                    if(delta_y <= -0.001)
                        betray_plugin_button_set(0, BETRAY_BUTTON_SCROLL_DOWN, TRUE, -1);
                    if(delta_y >= 0.001)
                        betray_plugin_button_set(0, BETRAY_BUTTON_SCROLL_LEFT, TRUE, -1);
                    if(delta_y <= -0.001)
                        betray_plugin_button_set(0, BETRAY_BUTTON_SCROLL_RIGHT, TRUE, -1);
                    betray_plugin_axis_set(betray_scroll_axis_id, (float)delta_x, (float)delta_y, 0);
				}
                break;
				//case NSFlagsChanged:
				case 12:
				{
                    uint32 bits;
                    NSUInteger modifiers = ((NSUInteger (*)(id, SEL))objc_msgSend)(event, modifierFlagsSel);

                    bits = (modifiers & 0xffff0000UL) >> 16;
                 /*   for(i = 0; i < 32; i++)
                    {
                        printf("key bits %u = %u\n", i, bits % 2);
                        bits /= 2;
                    }*/
// command == 16
                    if((bits & 2) != (last_modifyer_keys & 2))
						betray_plugin_button_set(0, BETRAY_BUTTON_SHIFT, bits & 2, -1);
					if((bits & 4) != (last_modifyer_keys & 4))
						betray_plugin_button_set(0, BETRAY_BUTTON_CONTROL, bits & 4, -1);
					if((bits & 8) != (last_modifyer_keys & 8))
						betray_plugin_button_set(0, BETRAY_BUTTON_ALT, bits & 8, -1);
					last_modifyer_keys = bits;


				//	printf("mod keys : mask %03u state %u%u%u%u%u%u%u%u\n", keys.mask, keys.alpha_shift, keys.shift, keys.control, keys.alternate, keys.command, keys.numeric_pad, keys.help, keys.function);
					break;
				}
				//case NSKeyDown:
				case 10:
				{
                    uint pos = 0;
					id inputText = ((id (*)(id, SEL))objc_msgSend)(event, charactersSel);
					const char * inputTextUTF8 = ((const char* (*)(id, SEL))objc_msgSend)(inputText, UTF8StringSel);
					uint16_t keyCode = ((unsigned short (*)(id, SEL))objc_msgSend)(event, keyCodeSel);
					if((last_modifyer_keys & 16) && (last_modifyer_keys & 2) && keyCode == BETRAY_BUTTON_Z)
					{
						betray_plugin_button_set(0, BETRAY_BUTTON_REDO, TRUE, -1);
					}else if((last_modifyer_keys & 16) && keyCode == BETRAY_BUTTON_Z)
					{
						betray_plugin_button_set(0, BETRAY_BUTTON_UNDO, TRUE, -1);
					}else if((last_modifyer_keys & 16) && keyCode == BETRAY_BUTTON_X)
					{
						betray_plugin_button_set(0, BETRAY_BUTTON_CUT, TRUE, -1);
					}else if((last_modifyer_keys & 16) && keyCode == BETRAY_BUTTON_C)
					{
						betray_plugin_button_set(0, BETRAY_BUTTON_COPY, TRUE, -1);
					}else if((last_modifyer_keys & 16) && keyCode == BETRAY_BUTTON_V)
					{
						betray_plugin_button_set(0, BETRAY_BUTTON_PASTE, TRUE, -1);
					}else
						betray_plugin_button_set(0, keyCode, TRUE, f_utf8_to_uint32(inputTextUTF8, &pos));
					printf("key down %u, text '%s'\n", keyCode, inputTextUTF8);
				}
                break;
				//case NSKeyUp:
				case 11:
				{
                    uint pos = 0;
                    id inputText = ((id (*)(id, SEL))objc_msgSend)(event, charactersSel);
                    const char * inputTextUTF8 = ((const char* (*)(id, SEL))objc_msgSend)(inputText, UTF8StringSel);
                    uint16_t keyCode = ((unsigned short (*)(id, SEL))objc_msgSend)(event, keyCodeSel);
                    betray_plugin_button_set(0, keyCode, FALSE, f_utf8_to_uint32(inputTextUTF8, &pos));
                    printf("key up %u\n", keyCode);
					break;
				}
				default:
					break;
			}

			//[NSApp sendEvent:event];
			((void (*)(id, SEL, id))objc_msgSend)(NSApp, sendEventSel, event);

			// if user closes the window we might need to terminate asap
			if(terminated)
				break;


		}

		// do runloop stuff
		//[openGLContext update]; // probably we only need to do it when we resize the window
	//	((void (*)(id, SEL))objc_msgSend)(betray_opengl_context_current, updateSel);

		//[openGLContext makeCurrentContext];
	//	((void (*)(id, SEL))objc_msgSend)(betray_opengl_context_current, makeCurrentContextSel);

		//NSRect rect = [contentView frame];
		NSRect rect = ((NSRect (*)(id, SEL))abi_objc_msgSend_stret)(betray_content_view, frameSel);

		//rect = [contentView convertRectToBacking:rect];
		rect = ((NSRect (*)(id, SEL, NSRect))abi_objc_msgSend_stret)(betray_content_view, convertRectToBackingSel, rect);
        betray_reshape_view(rect.size.width, rect.size.height);
        for(i = 0; i < input->pointer_count; i++)
        {
            input->pointers[i].delta_pointer_x += input->pointers[i].pointer_x;
            input->pointers[i].delta_pointer_y += input->pointers[i].pointer_y;
            input->pointers[i].delta_pointer_z += input->pointers[i].pointer_z;
            for(j = 0; j < input->pointers[i].button_count && j < B_POINTER_BUTTONS_COUNT; j++)
            {
                if(input->pointers[i].button[j] && !input->pointers[i].last_button[j])
                {
                    input->pointers[i].click_pointer_x[j] = input->pointers[i].pointer_x;
                    input->pointers[i].click_pointer_y[j] = input->pointers[i].pointer_y;
                    input->pointers[i].click_pointer_z[j] = input->pointers[i].pointer_z;
                }
            }
        }
        betray_plugin_callback_main(input);
      //  if(event_timer < 3)
        {
            betray_action(BAM_EVENT);
            event_timer++;
        }
        betray_action(BAM_DRAW);
#ifdef BETRAY_CONTEXT_OPENGL
        glFinish();
        //[NSApp updateWindows];
        ((void (*)(id, SEL))objc_msgSend)(betray_opengl_context_current, flushBufferSel);
        ((void (*)(id, SEL))objc_msgSend)(betray_opengl_context_current, updateSel);
        ((void (*)(id, SEL))objc_msgSend)(NSApp, updateWindowsSel);
#endif
#ifdef BETRAY_CONTEXT_OPENGLES
        eglSwapBuffers(sEGLDisplay, sEGLSurface);
#endif
        input->frame_number++;
        betray_time_update();
        betray_action(BAM_MAIN);
        input->button_event_count = 0;
        betray_plugin_pointer_clean();
        for(i = 0; i < input->pointer_count; i++)
        {
            input->pointers[i].delta_pointer_x = -input->pointers[i].pointer_x;
            input->pointers[i].delta_pointer_y = -input->pointers[i].pointer_y;
            for(j = 0; j < input->pointers[i].button_count; j++)
                input->pointers[i].last_button[j] = input->pointers[i].button[j];
        }
    }

	printf("gracefully terminated\n");

    //[pool release];
    /*
    ((void (*)(id, SEL))objc_msgSend)(pool, releaseSel);
    */
}

uint betray_support_functionality(BSupportedFunctionality funtionality)
{
    uint array[] = {
        256, /*B_SF_USER_COUNT_MAX*/
        256, /*B_SF_POINTER_COUNT_MAX*/
        TRUE, /*B_SF_FULLSCREEN*/
        TRUE, /*B_SF_WINDOWED*/
        FALSE, /*B_SF_VIEW_POSITION*/
        FALSE, /*B_SF_VIEW_ROTATION*/
        FALSE, /*B_SF_MOUSE_WARP*/
        FALSE, /*B_SF_EXECUTE*/
        TRUE, /*B_SF_REQUESTER*/
        TRUE}; /*B_SF_CLIPBOARD*/
    if(funtionality >= B_SF_COUNT)
        return FALSE;
    return array[funtionality];
}

/*
char *betray_requester_save_get(void *id)
{
    return NULL;
}

void betray_requester_save(char **types, uint type_count, void *id)
{
}

char *betray_requester_load_get(void *id)
{
    return NULL;
}

void betray_requester_load(char **types, uint type_count, void *id)
{
}
*/

char *betray_clipboard_get()
{
    // NSPasteboard *pasteboard  = [NSPasteboard generalPasteboard];
    Class NSPasteboardClass = objc_getClass("NSPasteboard");
    SEL generalPasteboardSel = sel_registerName("generalPasteboard");
    id pasteboard = ((id (*)(Class, SEL))objc_msgSend)(NSPasteboardClass, generalPasteboardSel);
    SEL autoreleaseSel = sel_registerName("autorelease");
    ((void (*)(id, SEL))objc_msgSend)(pasteboard, autoreleaseSel);
    
    // NSString *content = [pasteboard stringForType:NSPasteboardTypeString];
    Class NSStringClass = objc_getClass("NSString");
    SEL stringWithUTF8StringSel = sel_registerName("stringWithUTF8String:");
    id NSPasteboardTypeStringStr = ((id (*)(Class, SEL, const char *))objc_msgSend)(NSStringClass, stringWithUTF8StringSel, "public.utf8-plain-text");
    ((void (*)(id, SEL))objc_msgSend)(NSPasteboardTypeStringStr, autoreleaseSel);
    
    SEL stringforTypeSel = sel_registerName("stringForType:");
    id content = ((id (*)(id, SEL, id))objc_msgSend)(pasteboard, stringforTypeSel, NSPasteboardTypeStringStr);
    ((void (*)(id, SEL))objc_msgSend)(content, autoreleaseSel);
    
    if (!content) {
        return NULL;
    }
    
    // NSUInteger length = [content lengthOfBytesUsingEncoding:NSUTF8StringEncoding] + 1;
    SEL lengthOfBytesUsingEncodingSel = sel_registerName("lengthOfBytesUsingEncoding:");
    unsigned long length = ((unsigned long (*)(id, SEL, unsigned long))objc_msgSend)(content, lengthOfBytesUsingEncodingSel, 4) + 1;
    
    char *cStr = (char *)malloc(sizeof(char) * (uint)length);
    // if (![content getCString:cStr maxLength:length encoding:NSUTF8StringEncoding]) {
    SEL getCStringmaxLengthencodingSel = sel_registerName("getCString:maxLength:encoding:");
    if (!((BOOL (*)(id, SEL, char *, unsigned long, unsigned long))objc_msgSend)(content, getCStringmaxLengthencodingSel, cStr, length, 4)) {
        free(cStr);
        return NULL;
    };
    
    return cStr;
}

void betray_clipboard_set(char *text)
{
    Class NSPasteboardClass = objc_getClass("NSPasteboard");
    SEL generalPasteboardSel = sel_registerName("generalPasteboard");
    id pasteboard = ((id (*)(Class, SEL))objc_msgSend)(NSPasteboardClass, generalPasteboardSel);
    SEL autoreleaseSel = sel_registerName("autorelease");
    ((void (*)(id, SEL))objc_msgSend)(pasteboard, autoreleaseSel);
    SEL clearContentsSel = sel_registerName("clearContents");
    ((void (*)(id, SEL))objc_msgSend)(pasteboard, clearContentsSel);
    
    Class NSStringClass = objc_getClass("NSString");
    SEL stringWithUTF8StringSel = sel_registerName("stringWithUTF8String:");
    id str = ((id (*)(Class, SEL, const char *))objc_msgSend)(NSStringClass, stringWithUTF8StringSel, text);
    ((void (*)(id, SEL))objc_msgSend)(str, autoreleaseSel);
    
    id NSPasteboardTypeStringStr = ((id (*)(Class, SEL, const char *))objc_msgSend)(NSStringClass, stringWithUTF8StringSel, "public.utf8-plain-text");
    ((void (*)(id, SEL))objc_msgSend)(NSPasteboardTypeStringStr, autoreleaseSel);
    
    SEL setStringforTypeSel = sel_registerName("setString:forType:");
    ((BOOL (*)(id, SEL, id, id))objc_msgSend)(pasteboard, setStringforTypeSel, str, NSPasteboardTypeStringStr);
}

void betray_button_keyboard(uint user_id, boolean show)
{
}

void betray_desktop_size_get(uint *size_x, uint *size_y)
{
	if(betray_screen_screen_resolution_x == 0)
	{
		Class NSScreenClass = objc_getClass("NSScreen");
		SEL mainScreensSel = sel_registerName("mainScreen");
		id mainScreen = ((id (*)(Class, SEL))objc_msgSend)(NSScreenClass, mainScreensSel);
		SEL screensSel = sel_registerName("screens");
		id screen_array = ((id (*)(Class, SEL))objc_msgSend)(NSScreenClass, screensSel);
		SEL countSel = sel_registerName("count");
		uint array_length = ((uint (*)(Class, SEL))objc_msgSend)(screen_array, countSel);

		SEL objectAtIndexSel = sel_registerName("objectAtIndex:");
		id specific_screen = ((id (*)(Class, SEL, uint))objc_msgSend)(screen_array, objectAtIndexSel, 0);
		SEL visibleFrameSel = sel_registerName("frame");
		NSRect rect = ((NSRect (*)(id, SEL))abi_objc_msgSend_stret)(specific_screen, visibleFrameSel);
        
		betray_screen_screen_resolution_x = rect.size.width;
		betray_screen_screen_resolution_y = rect.size.height;
	}
    if(size_x != NULL)
        *size_x = betray_screen_screen_resolution_x;
    if(size_y != NULL)
        *size_y = betray_screen_screen_resolution_y;
}

boolean b_win32_screen_mode(uint size_x, uint size_y)
{
    return FALSE;
}

boolean betray_activate_context(void *context)
{
    SEL makeCurrentContextSel;
    if(context == NULL)
        context = betray_opengl_context_default;
    if(context == betray_opengl_context_current)
        return TRUE;
    makeCurrentContextSel = sel_registerName("makeCurrentContext");
    ((void (*)(id, SEL))objc_msgSend)(context, makeCurrentContextSel);
    return TRUE;
}

void *b_create_context()
{
    return NULL;
}




void system_wrapper_lose_focus(void)
{
 //   input_focus = FALSE;
}

void betray_set_mouse_warp(boolean warp)
{
 //   mouse_warp = warp;
}


void betray_set_mouse_move(float x, float y)
{
 /*   BInputState *input;
    input = betray_get_input_state();
    mouse_warp_move_x = x - input->pointers[0].pointer_x;
    mouse_warp_move_y = input->pointers[0].pointer_y - y;
    mouse_warp_move = TRUE;*/
}

uint betray_support_context(BContextType context_type)
{
    return context_type == B_CT_OPENGL || context_type == B_CT_OPENGL_OR_ES;
}

extern uint BGlobal_draw_state_fbo;

void *betray_get_proc_address(const char *name)
{
    static const char * gl_lib_path = "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL";
    static void *lib = NULL;
    if(lib == NULL)
        lib = dlopen(gl_lib_path, RTLD_LAZY);
    void *addr = dlsym(lib, name);
    if(!addr)
    {
        size_t len;
        len = strlen(name);
        if(len > 3 && strcmp(name + (len - 3), "ARB") == 0)
        {
            char nameWithoutARB[len - 3 + 1];
            strncpy(nameWithoutARB, name, len - 3);
            nameWithoutARB[len - 3] = '\0';
            addr = dlsym(lib, name);
        }
    }
    return addr;
 }

void betray_glBindFramebufferEXT(GLenum target, GLuint framebuffer)
{
    static void (*internal_glBindFramebufferEXT)(GLenum target, GLuint framebuffer) = NULL;
    if(internal_glBindFramebufferEXT == NULL)
        internal_glBindFramebufferEXT = (void (*)(GLenum , GLuint))betray_get_proc_address("glBindFramebufferEXT");
    if(framebuffer == 0)
        internal_glBindFramebufferEXT(target, BGlobal_draw_state_fbo);
    else
        internal_glBindFramebufferEXT(target, framebuffer);
}


GLubyte *betray_glGetString(GLenum name)
{
    if(name == GL_EXTENSIONS)
    {
     //   return "GL_ARB_vertex_array_bgra GL_ARB_draw_elements_base_vertex GL_ARB_fragment_coord_conventions GL_ARB_provoking_vertex GL_ARB_seamless_cube_map GL_ARB_texture_multisample GL_ARB_depth_clamp GL_ARB_sync GL_ARB_geometry_shader4 GL_ARB_uniform_buffer_object GL_ARB_draw_instanced GL_EXT_copy_buffer GL_NV_primitive_restart GL_ARB_texture_buffer_object GL_ARB_texture_rectangle GL_ARB_compatibility GL_ARB_framebuffer_object GL_ARB_vertex_array_object GL_NV_conditional_render GL_ARB_color_buffer_float GL_NV_depth_buffer_float GL_ARB_texture_float GL_EXT_packed_float GL_EXT_texture_shared_exponent GL_NV_half_float GL_EXT_half_float_pixel GL_EXT_texture_integer GL_EXT_texture_array GL_EXT_draw_buffers2 GL_EXT_texture_compression_rgtc GL_ARB_transform_feedback GL_EXT_framebuffer_sRGBde GL_ARB_pixel_buffer_object GL_EXT_texture_sRGB GL_ARB_shader_objects GL_ARB_vertex_shader GL_ARB_fragment_shader GL_ARB_shading_language_100 GL_ARB_draw_buffers GL_ARB_texture_non_power_of_two GL_ARB_point_sprite GL_ATI_separate_stencil GL_EXT_stencil_two_side GL_ARB_vertex_buffer_object GL_ARB_occlusion_query GL_EXT_shadow_funcs GL_SGIS_generate_mipmap GL_NV_blend_equare GL_ARB_depth_texture GL_ARB_shadow GL_EXT_fog_coord GL_EXT_multi_draw_arrays GL_ARB_point_parameters GL_EXT_secondary_color GL_EXT_blend_func_separate GL_EXT_stencil_wrap GL_ARB_texture_env_crossbar GL_EXT_texture_lod_bias GL_ARB_texture_mirrored_repeat GL_ARB_window_pos GL_ARB_texture_compression GL_ARB_texture_cube_map ARB_multisample GL_ARB_multitexture GL_ARB_texture_env_add GL_ARB_texture_env_combine GL_ARB_texture_env_dot3 GL_ARB_texture_border_clamp GL_ARB_transpose_matrix EXT_texture3D GL_EXT_bgra GL_EXT_packed_pixels GL_EXT_rescale_normal GL_EXT_separate_specular_color GL_SGIS_texture_edge_clamp GL_SGIS_texture_lod GL_EXT_draw_range_elements GL_EXT_color_table GL_EXT_color_subtable GL_EXT_convolution GL_EXT_convolution_border_modes GL_EXT_color_matrix GL_EXT_histogram GL_EXT_blend_color GL_EXT_blend_minmax GL_EXT_blend_substract GL_EXT_vertex_array GL_EXT_polygon_offset GL_EXT_blend_logic_op GL_EXT_texture GL_EXT_copy_texture GL_EXT_subtexture GL_EXT_texture_object GL_ARB_framebuffer_object GL_ARB_vertex_buffer_object";
        return "GL_ARB_vertex_array_bgra GL_ARB_draw_elements_base_vertex GL_ARB_fragment_coord_conventions GL_ARB_provoking_vertex GL_ARB_seamless_cube_map GL_ARB_texture_multisample GL_ARB_depth_clamp GL_ARB_sync GL_ARB_geometry_shader4 GL_ARB_uniform_buffer_object GL_ARB_draw_instanced GL_EXT_copy_buffer GL_NV_primitive_restart GL_ARB_texture_buffer_object GL_ARB_texture_rectangle GL_ARB_compatibility GL_ARB_framebuffer_object GL_ARB_vertex_array_object GL_NV_conditional_render GL_ARB_color_buffer_float GL_NV_depth_buffer_float GL_ARB_texture_float GL_EXT_packed_float GL_EXT_texture_shared_exponent GL_NV_half_float GL_EXT_half_float_pixel GL_EXT_texture_integer GL_EXT_texture_array GL_EXT_draw_buffers2 GL_EXT_texture_compression_rgtc GL_ARB_transform_feedback GL_EXT_framebuffer_sRGBde GL_ARB_pixel_buffer_object GL_EXT_texture_sRGB GL_ARB_shader_objects GL_ARB_vertex_shader GL_ARB_fragment_shader GL_ARB_shading_language_100 GL_ARB_draw_buffers GL_ARB_texture_non_power_of_two GL_ARB_point_sprite GL_ATI_separate_stencil GL_EXT_stencil_two_side GL_ARB_vertex_buffer_object GL_ARB_occlusion_query GL_EXT_shadow_funcs GL_SGIS_generate_mipmap GL_NV_blend_equare GL_ARB_depth_texture GL_ARB_shadow GL_EXT_fog_coord GL_EXT_multi_draw_arrays GL_ARB_point_parameters GL_EXT_secondary_color GL_EXT_blend_func_separate GL_EXT_stencil_wrap GL_ARB_texture_env_crossbar GL_EXT_texture_lod_bias GL_ARB_texture_mirrored_repeat GL_ARB_window_pos GL_ARB_texture_compression GL_ARB_texture_cube_map ARB_multisample GL_ARB_multitexture GL_ARB_texture_env_add GL_ARB_texture_env_combine GL_ARB_texture_env_dot3 GL_ARB_texture_border_clamp GL_ARB_transpose_matrix EXT_texture3D GL_EXT_bgra GL_EXT_packed_pixels GL_EXT_rescale_normal GL_EXT_separate_specular_color GL_SGIS_texture_edge_clamp GL_SGIS_texture_lod GL_EXT_draw_range_elements GL_EXT_color_table GL_EXT_color_subtable GL_EXT_convolution GL_EXT_convolution_border_modes GL_EXT_color_matrix GL_EXT_histogram GL_EXT_blend_color GL_EXT_blend_minmax GL_EXT_blend_substract GL_EXT_vertex_array GL_EXT_polygon_offset GL_EXT_blend_logic_op GL_EXT_texture GL_EXT_copy_texture GL_EXT_subtexture GL_EXT_texture_object GL_ARB_framebuffer_object GL_ARB_vertex_buffer_object GL_ARB_get_program_binary GL_ARB_separate_shader_objects GL_ARB_ES2_compatibility GL_ARB_shader_precision GL_ARB_vertex_attrib_64_bit GL_ARB_viewport_array GL_ARB_texture_query_lod GL_ARB_gpu_shader5 GL_ARB_gpu_shader_fp64 GL_ARB_shader_subroutine GL_ARB_texture_gather GL_ARB_draw_indirect GL_ARB_sample_shading GL_ARB_tessellation_shader GL_ARB_texture_buffer_object_rgb32 GL_ARB_texture_cube_map_array GL_ARB_transform_feedback2 GL_ARB_transform_feedback3 GL_ARB_draw_buffers_blend GL_ARB_shader_bit_encoding GL_ARB_blend_func_extended GL_ARB_explicit_attrib_location GL_ARB_occlusion_query2 GL_ARB_sampler_objects GL_ARB_texture_rgb10_a2ui GL_ARB_texture_swizzle GL_ARB_timer_query GL_ARB_instanced_arrays GL_ARB_vertex_type_2_10_10_10_rev GL_ARB_framebuffer_object GL_ARB_vertex_buffer_object";
    }
    else
        return glGetString(name);
}

void *betray_gl_proc_address_get_internal(const char *text)
{
#ifdef BETRAY_CONTEXT_OPENGL
    // if(b_win32_opengl_context_current == b_win32_opengl_context)
    {
        uint i;
        char *extension = "glBindFramebuffer";
        for(i = 0; extension[i] == text[i] && extension[i] != 0; i++);
        if(extension[i] == 0)
            return betray_glBindFramebufferEXT;
    }
    {
        uint i;
        char *extension = "glGetString";
        for(i = 0; extension[i] == text[i] && extension[i] != 0; i++);
        if(extension[i] == 0)
            return betray_glGetString;
    }
    return betray_get_proc_address(text);
#endif
    return NULL;
}

void *betray_gl_proc_address_get()
{
    return (void *(*)(const char *))betray_gl_proc_address_get_internal;
}

#endif
