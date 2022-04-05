/*
	This file has been automatically generated by the shimmer industries c-ocoa API generator
	Thus, manual changes to this file will be lost if the file is re-generated.
*/

#ifndef SHIMMER_C_OCOA_NSSCREEN_HEADER
#define SHIMMER_C_OCOA_NSSCREEN_HEADER

typedef void*	nsscreen_t;
#include "c_ocoa_types.h"

// Signature from Objective-C Runtime: v dealloc @ :
void 				nsscreen_dealloc( nsscreen_t object );

// Signature from Objective-C Runtime: c isEqual: @ : @
char 				nsscreen_isEqual( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: Q hash @ :
unsigned long long 	nsscreen_hash( nsscreen_t object );

// Signature from Objective-C Runtime: @ localizedName @ :
nsobject_t 			nsscreen_localizedName( nsscreen_t object );

// Signature from Objective-C Runtime: i depth @ :
int 				nsscreen_depth( nsscreen_t object );

// Signature from Objective-C Runtime: {CGRect={CGPoint=dd}{CGSize=dd}} visibleFrame @ :
CGRect 				nsscreen_visibleFrame( nsscreen_t object );

// Signature from Objective-C Runtime: {CGRect={CGPoint=dd}{CGSize=dd}} frame @ :
CGRect 				nsscreen_frame( nsscreen_t object );

// Signature from Objective-C Runtime: @ displayLinkWithTarget:selector: @ : @ :
nsobject_t 			nsscreen_displayLinkWithTarget( nsscreen_t object, nsobject_t arg0, nsselector_t arg1 );

// Signature from Objective-C Runtime: @ colorSpace @ :
nsobject_t 			nsscreen_colorSpace( nsscreen_t object );

// Signature from Objective-C Runtime: d backingScaleFactor @ :
double 				nsscreen_backingScaleFactor( nsscreen_t object );

// Signature from Objective-C Runtime: {CGRect={CGPoint=dd}{CGSize=dd}} backingAlignedRect:options: @ : {CGRect={CGPoint=dd}{CGSize=dd}} Q
CGRect 				nsscreen_backingAlignedRect( nsscreen_t object, CGRect arg0, unsigned long long arg1 );

// Signature from Objective-C Runtime: {CGRect={CGPoint=dd}{CGSize=dd}} convertRectToBacking: @ : {CGRect={CGPoint=dd}{CGSize=dd}}
CGRect 				nsscreen_convertRectToBacking( nsscreen_t object, CGRect arg0 );

// Signature from Objective-C Runtime: {CGRect={CGPoint=dd}{CGSize=dd}} convertRectFromBacking: @ : {CGRect={CGPoint=dd}{CGSize=dd}}
CGRect 				nsscreen_convertRectFromBacking( nsscreen_t object, CGRect arg0 );

// Signature from Objective-C Runtime: @ deviceDescription @ :
nsobject_t 			nsscreen_deviceDescription( nsscreen_t object );

// Signature from Objective-C Runtime: c canRepresentDisplayGamut: @ : q
char 				nsscreen_canRepresentDisplayGamut( nsscreen_t object, long long arg0 );

// Signature from Objective-C Runtime: {CGSize=dd} devicePixelCounts @ :
CGSize 				nsscreen_devicePixelCounts( nsscreen_t object );

// Signature from Objective-C Runtime: d maximumExtendedDynamicRangeColorComponentValue @ :
double 				nsscreen_maximumExtendedDynamicRangeColorComponentValue( nsscreen_t object );

// Signature from Objective-C Runtime: d maximumPotentialExtendedDynamicRangeColorComponentValue @ :
double 				nsscreen_maximumPotentialExtendedDynamicRangeColorComponentValue( nsscreen_t object );

// Signature from Objective-C Runtime: d maximumReferenceExtendedDynamicRangeColorComponentValue @ :
double 				nsscreen_maximumReferenceExtendedDynamicRangeColorComponentValue( nsscreen_t object );

// Signature from Objective-C Runtime: r^i supportedWindowDepths @ :
int* 				nsscreen_supportedWindowDepths( nsscreen_t object );

// Signature from Objective-C Runtime: @ imageInRect: @ : {CGRect={CGPoint=dd}{CGSize=dd}}
nsobject_t 			nsscreen_imageInRect( nsscreen_t object, CGRect arg0 );

// Signature from Objective-C Runtime: d userSpaceScaleFactor @ :
double 				nsscreen_userSpaceScaleFactor( nsscreen_t object );

// Signature from Objective-C Runtime: @ displayLinkWithHandler: @ : @?
nsobject_t 			nsscreen_displayLinkWithHandler( nsscreen_t object, nsobject_t* arg0 );

// Signature from Objective-C Runtime: @ accessibilityOverriddenAttributes @ :
nsobject_t 			nsscreen_accessibilityOverriddenAttributes( nsscreen_t object );

// Signature from Objective-C Runtime: c accessibilityReplaceRange:withText: @ : {_NSRange=QQ} @
char 				nsscreen_accessibilityReplaceRange( nsscreen_t object, _NSRange arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: d accessibilityVisibleArea @ :
double 				nsscreen_accessibilityVisibleArea( nsscreen_t object );

// Signature from Objective-C Runtime: Q accessibilityArrayAttributeCount: @ : @
unsigned long long 	nsscreen_accessibilityArrayAttributeCount( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: Q accessibilityIndexOfChild: @ : @
unsigned long long 	nsscreen_accessibilityIndexOfChild( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ accessibilityArrayAttributeValues:index:maxCount: @ : @ Q Q
nsobject_t 			nsscreen_accessibilityArrayAttributeValues( nsscreen_t object, nsobject_t arg0, unsigned long long arg1, unsigned long long arg2 );

// Signature from Objective-C Runtime: @ accessibilityParameterizedAttributeNames @ :
nsobject_t 			nsscreen_accessibilityParameterizedAttributeNames( nsscreen_t object );

// Signature from Objective-C Runtime: @ accessibilityAttributeValue:forParameter: @ : @ @
nsobject_t 			nsscreen_accessibilityAttributeValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: @ accessibilityIndexForChildUIElementAttributeForParameter: @ : @
nsobject_t 			nsscreen_accessibilityIndexForChildUIElementAttributeForParameter( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ accessibilityAttributedValueForStringAttributeAttributeForParameter: @ : @
nsobject_t 			nsscreen_accessibilityAttributedValueForStringAttributeAttributeForParameter( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ accessibilityTemporaryChildren @ :
nsobject_t 			nsscreen_accessibilityTemporaryChildren( nsscreen_t object );

// Signature from Objective-C Runtime: c accessibilityPerformShowMenuOfChild: @ : @
char 				nsscreen_accessibilityPerformShowMenuOfChild( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: i accessibilityPresenterProcessIdentifier @ :
int 				nsscreen_accessibilityPresenterProcessIdentifier( nsscreen_t object );

// Signature from Objective-C Runtime: c accessibilityShouldUseUniqueId @ :
char 				nsscreen_accessibilityShouldUseUniqueId( nsscreen_t object );

// Signature from Objective-C Runtime: c accessibilitySupportsNotifications @ :
char 				nsscreen_accessibilitySupportsNotifications( nsscreen_t object );

// Signature from Objective-C Runtime: c accessibilityShouldSendNotification: @ : @
char 				nsscreen_accessibilityShouldSendNotification( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c accessibilitySupportsOverriddenAttributes @ :
char 				nsscreen_accessibilitySupportsOverriddenAttributes( nsscreen_t object );

// Signature from Objective-C Runtime: c accessibilityAllowsOverriddenAttributesWhenIgnored @ :
char 				nsscreen_accessibilityAllowsOverriddenAttributesWhenIgnored( nsscreen_t object );

// Signature from Objective-C Runtime: c accessibilitySetOverrideValue:forAttribute: @ : @ @
char 				nsscreen_accessibilitySetOverrideValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: v accessibilityEncodeOverriddenAttributes: @ : @
void 				nsscreen_accessibilityEncodeOverriddenAttributes( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v accessibilityDecodeOverriddenAttributes: @ : @
void 				nsscreen_accessibilityDecodeOverriddenAttributes( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c accessibilitySupportsCustomElementData @ :
char 				nsscreen_accessibilitySupportsCustomElementData( nsscreen_t object );

// Signature from Objective-C Runtime: v bind:toObject:withKeyPath:options: @ : @ @ @ @
void 				nsscreen_bind( nsscreen_t object, nsobject_t arg0, nsobject_t arg1, nsobject_t arg2, nsobject_t arg3 );

// Signature from Objective-C Runtime: v awakeFromNib @ :
void 				nsscreen_awakeFromNib( nsscreen_t object );

// Signature from Objective-C Runtime: @ userInterfaceItemIdentifier @ :
nsobject_t 			nsscreen_userInterfaceItemIdentifier( nsscreen_t object );

// Signature from Objective-C Runtime: v setUserInterfaceItemIdentifier: @ : @
void 				nsscreen_setUserInterfaceItemIdentifier( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v unbind: @ : @
void 				nsscreen_unbind( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: # valueClassForBinding: @ : @
nsclass_t 			nsscreen_valueClassForBinding( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ NS_observationForKeyPath:options:block: @ : @ Q @?
nsobject_t 			nsscreen_NS_observationForKeyPath( nsscreen_t object, nsobject_t arg0, unsigned long long arg1, nsobject_t* arg2 );

// Signature from Objective-C Runtime: @ NS_observationForKeyPaths:options:block: @ : @ Q @?
nsobject_t 			nsscreen_NS_observationForKeyPaths( nsscreen_t object, nsobject_t arg0, unsigned long long arg1, nsobject_t* arg2 );

// Signature from Objective-C Runtime: @ optionDescriptionsForBinding: @ : @
nsobject_t 			nsscreen_optionDescriptionsForBinding( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ exposedBindings @ :
nsobject_t 			nsscreen_exposedBindings( nsscreen_t object );

// Signature from Objective-C Runtime: @ infoForBinding: @ : @
nsobject_t 			nsscreen_infoForBinding( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v prepareForInterfaceBuilder @ :
void 				nsscreen_prepareForInterfaceBuilder( nsscreen_t object );

// Signature from Objective-C Runtime: v accessibilityAddTemporaryChild: @ : @
void 				nsscreen_accessibilityAddTemporaryChild( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v accessibilityRemoveTemporaryChild: @ : @
void 				nsscreen_accessibilityRemoveTemporaryChild( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ NSLifeguard_autorelease @ :
nsobject_t 			nsscreen_NSLifeguard_autorelease( nsscreen_t object );

// Signature from Objective-C Runtime: v accessibilitySetPresenterProcessIdentifier: @ : i
void 				nsscreen_accessibilitySetPresenterProcessIdentifier( nsscreen_t object, int arg0 );

// Signature from Objective-C Runtime: @ NS_tiledLayerVisibleRect @ :
nsobject_t 			nsscreen_NS_tiledLayerVisibleRect( nsscreen_t object );

// Signature from Objective-C Runtime: v NS_addTiledLayerDescendent: @ : @
void 				nsscreen_NS_addTiledLayerDescendent( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v NS_removeTiledLayerDescendent: @ : @
void 				nsscreen_NS_removeTiledLayerDescendent( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c CAMLTypeSupportedForKey: @ : @
char 				nsscreen_CAMLTypeSupportedForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ CAMLTypeForKey: @ : @
nsobject_t 			nsscreen_CAMLTypeForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c CA_validateValue:forKey: @ : @ @
char 				nsscreen_CA_validateValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: v encodeWithCAMLWriter: @ : @
void 				nsscreen_encodeWithCAMLWriter( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ CA_interpolateValues:::interpolator: @ : @ @ @ r^{ValueInterpolator=dddddddddB}
nsobject_t 			nsscreen_CA_interpolateValues( nsscreen_t object, nsobject_t arg0, nsobject_t arg1, nsobject_t arg2, ValueInterpolator* arg3 );

// Signature from Objective-C Runtime: @ CAMLType @ :
nsobject_t 			nsscreen_CAMLType( nsscreen_t object );

// Signature from Objective-C Runtime: @ CA_archivingValueForKey: @ : @
nsobject_t 			nsscreen_CA_archivingValueForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ CA_roundToIntegerFromValue: @ : @
nsobject_t 			nsscreen_CA_roundToIntegerFromValue( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ CA_addValue:multipliedBy: @ : @ i
nsobject_t 			nsscreen_CA_addValue( nsscreen_t object, nsobject_t arg0, int arg1 );

// Signature from Objective-C Runtime: @ CA_interpolateValue:byFraction: @ : @ f
nsobject_t 			nsscreen_CA_interpolateValue( nsscreen_t object, nsobject_t arg0, float arg1 );

// Signature from Objective-C Runtime: d CA_distanceToValue: @ : @
double 				nsscreen_CA_distanceToValue( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v CA_prepareRenderValue @ :
void 				nsscreen_CA_prepareRenderValue( nsscreen_t object );

// Signature from Objective-C Runtime: ^{Object=^^?{Atomic={?=i}}} CA_copyRenderValue @ :
Object* 			nsscreen_CA_copyRenderValue( nsscreen_t object );

// Signature from Objective-C Runtime: c supportsRBSXPCSecureCoding @ :
char 				nsscreen_supportsRBSXPCSecureCoding( nsscreen_t object );

// Signature from Objective-C Runtime: c RBSIsXPCObject @ :
char 				nsscreen_RBSIsXPCObject( nsscreen_t object );

// Signature from Objective-C Runtime: @ NSRepresentation @ :
nsobject_t 			nsscreen_NSRepresentation( nsscreen_t object );

// Signature from Objective-C Runtime: c supportsBSXPCSecureCoding @ :
char 				nsscreen_supportsBSXPCSecureCoding( nsscreen_t object );

// Signature from Objective-C Runtime: c bs_isPlistableType @ :
char 				nsscreen_bs_isPlistableType( nsscreen_t object );

// Signature from Objective-C Runtime: @ bs_secureEncoded @ :
nsobject_t 			nsscreen_bs_secureEncoded( nsscreen_t object );

// Signature from Objective-C Runtime: @ bs_encoded @ :
nsobject_t 			nsscreen_bs_encoded( nsscreen_t object );

// Signature from Objective-C Runtime: # classForCoder @ :
nsclass_t 			nsscreen_classForCoder( nsscreen_t object );

// Signature from Objective-C Runtime: @ replacementObjectForCoder: @ : @
nsobject_t 			nsscreen_replacementObjectForCoder( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ awakeAfterUsingCoder: @ : @
nsobject_t 			nsscreen_awakeAfterUsingCoder( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c implementsSelector: @ : :
char 				nsscreen_implementsSelector( nsscreen_t object, nsselector_t arg0 );

// Signature from Objective-C Runtime: v setObservationInfo: @ : ^v
void 				nsscreen_setObservationInfo( nsscreen_t object, void* arg0 );

// Signature from Objective-C Runtime: v setValue:forKey: @ : @ @
void 				nsscreen_setValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: @ replacementObjectForPortCoder: @ : @
nsobject_t 			nsscreen_replacementObjectForPortCoder( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v willChangeValueForKey: @ : @
void 				nsscreen_willChangeValueForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v didChangeValueForKey: @ : @
void 				nsscreen_didChangeValueForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ dictionaryWithValuesForKeys: @ : @
nsobject_t 			nsscreen_dictionaryWithValuesForKeys( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ valueForKey: @ : @
nsobject_t 			nsscreen_valueForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ valueForUndefinedKey: @ : @
nsobject_t 			nsscreen_valueForUndefinedKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: # classForKeyedArchiver @ :
nsclass_t 			nsscreen_classForKeyedArchiver( nsscreen_t object );

// Signature from Objective-C Runtime: @ replacementObjectForKeyedArchiver: @ : @
nsobject_t 			nsscreen_replacementObjectForKeyedArchiver( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ valueForKeyPath: @ : @
nsobject_t 			nsscreen_valueForKeyPath( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ addObserver: @ : @
nsobject_t 			nsscreen_addObserver( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ objectSpecifier @ :
nsobject_t 			nsscreen_objectSpecifier( nsscreen_t object );

// Signature from Objective-C Runtime: @ replacementObjectForArchiver: @ : @
nsobject_t 			nsscreen_replacementObjectForArchiver( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: # classForArchiver @ :
nsclass_t 			nsscreen_classForArchiver( nsscreen_t object );

// Signature from Objective-C Runtime: @ attributeKeys @ :
nsobject_t 			nsscreen_attributeKeys( nsscreen_t object );

// Signature from Objective-C Runtime: @ toOneRelationshipKeys @ :
nsobject_t 			nsscreen_toOneRelationshipKeys( nsscreen_t object );

// Signature from Objective-C Runtime: @ toManyRelationshipKeys @ :
nsobject_t 			nsscreen_toManyRelationshipKeys( nsscreen_t object );

// Signature from Objective-C Runtime: @ inverseForRelationshipKey: @ : @
nsobject_t 			nsscreen_inverseForRelationshipKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ classDescription @ :
nsobject_t 			nsscreen_classDescription( nsscreen_t object );

// Signature from Objective-C Runtime: @ copyScriptingValue:forKey:withProperties: @ : @ @ @
nsobject_t 			nsscreen_copyScriptingValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1, nsobject_t arg2 );

// Signature from Objective-C Runtime: ^{objc_method_description=:*} methodDescriptionForSelector: @ : :
objc_method_description* nsscreen_methodDescriptionForSelector( nsscreen_t object, nsselector_t arg0 );

// Signature from Objective-C Runtime: @ newScriptingObjectOfClass:forValueForKey:withContentsValue:properties: @ : # @ @ @
nsobject_t 			nsscreen_newScriptingObjectOfClass( nsscreen_t object, nsclass_t arg0, nsobject_t arg1, nsobject_t arg2, nsobject_t arg3 );

// Signature from Objective-C Runtime: @ handleQueryWithUnboundKey: @ : @
nsobject_t 			nsscreen_handleQueryWithUnboundKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v handleTakeValue:forUnboundKey: @ : @ @
void 				nsscreen_handleTakeValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: @ storedValueForKey: @ : @
nsobject_t 			nsscreen_storedValueForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v takeStoredValue:forKey: @ : @ @
void 				nsscreen_takeStoredValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: v takeValue:forKey: @ : @ @
void 				nsscreen_takeValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: @ valuesForKeys: @ : @
nsobject_t 			nsscreen_valuesForKeys( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v takeValuesFromDictionary: @ : @
void 				nsscreen_takeValuesFromDictionary( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v unableToSetNilForKey: @ : @
void 				nsscreen_unableToSetNilForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ keyValueBindingForKey:typeMask: @ : @ Q
nsobject_t 			nsscreen_keyValueBindingForKey( nsscreen_t object, nsobject_t arg0, unsigned long long arg1 );

// Signature from Objective-C Runtime: @ createKeyValueBindingForKey:typeMask: @ : @ Q
nsobject_t 			nsscreen_createKeyValueBindingForKey( nsscreen_t object, nsobject_t arg0, unsigned long long arg1 );

// Signature from Objective-C Runtime: @ mutableArrayValueForKeyPath: @ : @
nsobject_t 			nsscreen_mutableArrayValueForKeyPath( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ mutableOrderedSetValueForKeyPath: @ : @
nsobject_t 			nsscreen_mutableOrderedSetValueForKeyPath( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ mutableSetValueForKeyPath: @ : @
nsobject_t 			nsscreen_mutableSetValueForKeyPath( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v removeObservation: @ : @
void 				nsscreen_removeObservation( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v receiveObservedValue: @ : @
void 				nsscreen_receiveObservedValue( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v receiveObservedError: @ : @
void 				nsscreen_receiveObservedError( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v finishObserving @ :
void 				nsscreen_finishObserving( nsscreen_t object );

// Signature from Objective-C Runtime: v setObservation:forObservingKeyPath: @ : @ @
void 				nsscreen_setObservation( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: v observeValueForKeyPath:ofObject:change:context: @ : @ @ @ ^v
void 				nsscreen_observeValueForKeyPath( nsscreen_t object, nsobject_t arg0, nsobject_t arg1, nsobject_t arg2, void* arg3 );

// Signature from Objective-C Runtime: v removeObserver:forKeyPath:context: @ : @ @ ^v
void 				nsscreen_removeObserver( nsscreen_t object, nsobject_t arg0, nsobject_t arg1, void* arg2 );

// Signature from Objective-C Runtime: @ className @ :
nsobject_t 			nsscreen_className( nsscreen_t object );

// Signature from Objective-C Runtime: @ addChainedObservers: @ : @
nsobject_t 			nsscreen_addChainedObservers( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ addObserverBlock: @ : @?
nsobject_t 			nsscreen_addObserverBlock( nsscreen_t object, nsobject_t* arg0 );

// Signature from Objective-C Runtime: @ addObservationTransformer: @ : @?
nsobject_t 			nsscreen_addObservationTransformer( nsscreen_t object, nsobject_t* arg0 );

// Signature from Objective-C Runtime: v setNilValueForKey: @ : @
void 				nsscreen_setNilValueForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ mutableArrayValueForKey: @ : @
nsobject_t 			nsscreen_mutableArrayValueForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ mutableOrderedSetValueForKey: @ : @
nsobject_t 			nsscreen_mutableOrderedSetValueForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ mutableSetValueForKey: @ : @
nsobject_t 			nsscreen_mutableSetValueForKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v setValuesForKeysWithDictionary: @ : @
void 				nsscreen_setValuesForKeysWithDictionary( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v willChange:valuesAtIndexes:forKey: @ : Q @ @
void 				nsscreen_willChange( nsscreen_t object, unsigned long long arg0, nsobject_t arg1, nsobject_t arg2 );

// Signature from Objective-C Runtime: v didChange:valuesAtIndexes:forKey: @ : Q @ @
void 				nsscreen_didChange( nsscreen_t object, unsigned long long arg0, nsobject_t arg1, nsobject_t arg2 );

// Signature from Objective-C Runtime: ^v observationInfo @ :
void* 				nsscreen_observationInfo( nsscreen_t object );

// Signature from Objective-C Runtime: @ autoContentAccessingProxy @ :
nsobject_t 			nsscreen_autoContentAccessingProxy( nsscreen_t object );

// Signature from Objective-C Runtime: @ coerceValue:forKey: @ : @ @
nsobject_t 			nsscreen_coerceValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: v setScriptingProperties: @ : @
void 				nsscreen_setScriptingProperties( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ scriptingValueForSpecifier: @ : @
nsobject_t 			nsscreen_scriptingValueForSpecifier( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ scriptingProperties @ :
nsobject_t 			nsscreen_scriptingProperties( nsscreen_t object );

// Signature from Objective-C Runtime: @ coerceValueForScriptingProperties: @ : @
nsobject_t 			nsscreen_coerceValueForScriptingProperties( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ valueAtIndex:inPropertyWithKey: @ : Q @
nsobject_t 			nsscreen_valueAtIndex( nsscreen_t object, unsigned long long arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: @ valueWithName:inPropertyWithKey: @ : @ @
nsobject_t 			nsscreen_valueWithName( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: @ valueWithUniqueID:inPropertyWithKey: @ : @ @
nsobject_t 			nsscreen_valueWithUniqueID( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: v insertValue:atIndex:inPropertyWithKey: @ : @ Q @
void 				nsscreen_insertValue( nsscreen_t object, nsobject_t arg0, unsigned long long arg1, nsobject_t arg2 );

// Signature from Objective-C Runtime: v replaceValueAtIndex:inPropertyWithKey:withValue: @ : Q @ @
void 				nsscreen_replaceValueAtIndex( nsscreen_t object, unsigned long long arg0, nsobject_t arg1, nsobject_t arg2 );

// Signature from Objective-C Runtime: v removeValueAtIndex:fromPropertyWithKey: @ : Q @
void 				nsscreen_removeValueAtIndex( nsscreen_t object, unsigned long long arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: # classForPortCoder @ :
nsclass_t 			nsscreen_classForPortCoder( nsscreen_t object );

// Signature from Objective-C Runtime: v performSelector:withObject:afterDelay:inModes: @ : : @ d @
void 				nsscreen_performSelector( nsscreen_t object, nsselector_t arg0, nsobject_t arg1, double arg2, nsobject_t arg3 );

// Signature from Objective-C Runtime: I classCode @ :
unsigned int 		nsscreen_classCode( nsscreen_t object );

// Signature from Objective-C Runtime: c isEqualTo: @ : @
char 				nsscreen_isEqualTo( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c isLessThanOrEqualTo: @ : @
char 				nsscreen_isLessThanOrEqualTo( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c isLessThan: @ : @
char 				nsscreen_isLessThan( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c isGreaterThanOrEqualTo: @ : @
char 				nsscreen_isGreaterThanOrEqualTo( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c isGreaterThan: @ : @
char 				nsscreen_isGreaterThan( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c isNotEqualTo: @ : @
char 				nsscreen_isNotEqualTo( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c doesContain: @ : @
char 				nsscreen_doesContain( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c isLike: @ : @
char 				nsscreen_isLike( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c isCaseInsensitiveLike: @ : @
char 				nsscreen_isCaseInsensitiveLike( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v performSelectorOnMainThread:withObject:waitUntilDone:modes: @ : : @ c @
void 				nsscreen_performSelectorOnMainThread( nsscreen_t object, nsselector_t arg0, nsobject_t arg1, char arg2, nsobject_t arg3 );

// Signature from Objective-C Runtime: v performSelectorInBackground:withObject: @ : : @
void 				nsscreen_performSelectorInBackground( nsscreen_t object, nsselector_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: @ classDescriptionForDestinationKey: @ : @
nsobject_t 			nsscreen_classDescriptionForDestinationKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ entityName @ :
nsobject_t 			nsscreen_entityName( nsscreen_t object );

// Signature from Objective-C Runtime: c ownsDestinationObjectsForRelationshipKey: @ : @
char 				nsscreen_ownsDestinationObjectsForRelationshipKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c isToManyKey: @ : @
char 				nsscreen_isToManyKey( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: v removeObject:fromPropertyWithKey: @ : @ @
void 				nsscreen_removeObject( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: v addObject:toPropertyWithKey: @ : @ @
void 				nsscreen_addObject( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: @ validateTakeValue:forKeyPath: @ : @ @
nsobject_t 			nsscreen_validateTakeValue( nsscreen_t object, nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: @ allPropertyKeys @ :
nsobject_t 			nsscreen_allPropertyKeys( nsscreen_t object );

// Signature from Objective-C Runtime: v clearProperties @ :
void 				nsscreen_clearProperties( nsscreen_t object );

// Signature from Objective-C Runtime: v flushKeyBindings @ :
void 				nsscreen_flushKeyBindings( nsscreen_t object );

// Signature from Objective-C Runtime: v takeStoredValuesFromDictionary: @ : @
void 				nsscreen_takeStoredValuesFromDictionary( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c isNSDate__ @ :
char 				nsscreen_isNSDate__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSString__ @ :
char 				nsscreen_isNSString__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSCFConstantString__ @ :
char 				nsscreen_isNSCFConstantString__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSNumber__ @ :
char 				nsscreen_isNSNumber__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSArray__ @ :
char 				nsscreen_isNSArray__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSDictionary__ @ :
char 				nsscreen_isNSDictionary__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSSet__ @ :
char 				nsscreen_isNSSet__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSData__ @ :
char 				nsscreen_isNSData__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSObject__ @ :
char 				nsscreen_isNSObject__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSOrderedSet__ @ :
char 				nsscreen_isNSOrderedSet__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSTimeZone__ @ :
char 				nsscreen_isNSTimeZone__( nsscreen_t object );

// Signature from Objective-C Runtime: c isNSValue__ @ :
char 				nsscreen_isNSValue__( nsscreen_t object );

// Signature from Objective-C Runtime: @ description @ :
nsobject_t 			nsscreen_description( nsscreen_t object );

// Signature from Objective-C Runtime: v doesNotRecognizeSelector: @ : :
void 				nsscreen_doesNotRecognizeSelector( nsscreen_t object, nsselector_t arg0 );

// Signature from Objective-C Runtime: @ methodSignatureForSelector: @ : :
nsobject_t 			nsscreen_methodSignatureForSelector( nsscreen_t object, nsselector_t arg0 );

// Signature from Objective-C Runtime: @ retain @ :
nsobject_t 			nsscreen_retain( nsscreen_t object );

// Signature from Objective-C Runtime: Q retainCount @ :
unsigned long long 	nsscreen_retainCount( nsscreen_t object );

// Signature from Objective-C Runtime: @ autorelease @ :
nsobject_t 			nsscreen_autorelease( nsscreen_t object );

// Signature from Objective-C Runtime: @ copy @ :
nsobject_t 			nsscreen_copy( nsscreen_t object );

// Signature from Objective-C Runtime: v finalize @ :
void 				nsscreen_finalize( nsscreen_t object );

// Signature from Objective-C Runtime: # class @ :
nsclass_t 			nsscreen_class( nsscreen_t object );

// Signature from Objective-C Runtime: @ self @ :
nsobject_t 			nsscreen_self( nsscreen_t object );

// Signature from Objective-C Runtime: c isProxy @ :
char 				nsscreen_isProxy( nsscreen_t object );

// Signature from Objective-C Runtime: c isKindOfClass: @ : #
char 				nsscreen_isKindOfClass( nsscreen_t object, nsclass_t arg0 );

// Signature from Objective-C Runtime: c isMemberOfClass: @ : #
char 				nsscreen_isMemberOfClass( nsscreen_t object, nsclass_t arg0 );

// Signature from Objective-C Runtime: c conformsToProtocol: @ : @
char 				nsscreen_conformsToProtocol( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: c respondsToSelector: @ : :
char 				nsscreen_respondsToSelector( nsscreen_t object, nsselector_t arg0 );

// Signature from Objective-C Runtime: ^{_NSZone=} zone @ :
_NSZone* 			nsscreen_zone( nsscreen_t object );

// Signature from Objective-C Runtime: # superclass @ :
nsclass_t 			nsscreen_superclass( nsscreen_t object );

// Signature from Objective-C Runtime: @ debugDescription @ :
nsobject_t 			nsscreen_debugDescription( nsscreen_t object );

// Signature from Objective-C Runtime: @ init @ :
nsobject_t 			nsscreen_init( nsscreen_t object );

// Signature from Objective-C Runtime: c retainWeakReference @ :
char 				nsscreen_retainWeakReference( nsscreen_t object );

// Signature from Objective-C Runtime: c allowsWeakReference @ :
char 				nsscreen_allowsWeakReference( nsscreen_t object );

// Signature from Objective-C Runtime: c isFault @ :
char 				nsscreen_isFault( nsscreen_t object );

// Signature from Objective-C Runtime: v forwardInvocation: @ : @
void 				nsscreen_forwardInvocation( nsscreen_t object, nsobject_t arg0 );

// Signature from Objective-C Runtime: @ forwardingTargetForSelector: @ : :
nsobject_t 			nsscreen_forwardingTargetForSelector( nsscreen_t object, nsselector_t arg0 );

// Signature from Objective-C Runtime: @ mutableCopy @ :
nsobject_t 			nsscreen_mutableCopy( nsscreen_t object );

// Signature from Objective-C Runtime: @ screens @ :
nsobject_t 			nsscreen_screens( );

// Signature from Objective-C Runtime: @ mainScreen @ :
nsobject_t 			nsscreen_mainScreen( );

// Signature from Objective-C Runtime: c screensHaveSeparateSpaces @ :
char 				nsscreen_screensHaveSeparateSpaces( );

// Signature from Objective-C Runtime: @ deepestScreen @ :
nsobject_t 			nsscreen_deepestScreen( );

// Signature from Objective-C Runtime: @ defaultPlaceholderForMarker:withBinding: @ : @ @
nsobject_t 			nsscreen_defaultPlaceholderForMarker( nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: v exposeBinding: @ : @
void 				nsscreen_exposeBinding( nsobject_t arg0 );

// Signature from Objective-C Runtime: v setDefaultPlaceholder:forMarker:withBinding: @ : @ @ @
void 				nsscreen_setDefaultPlaceholder( nsobject_t arg0, nsobject_t arg1, nsobject_t arg2 );

// Signature from Objective-C Runtime: c CA_automaticallyNotifiesObservers: @ : #
char 				nsscreen_CA_automaticallyNotifiesObservers( nsclass_t arg0 );

// Signature from Objective-C Runtime: c CA_encodesPropertyConditionally:type: @ : I i
char 				nsscreen_CA_encodesPropertyConditionally( unsigned int arg0, int arg1 );

// Signature from Objective-C Runtime: @ CA_CAMLPropertyForKey: @ : @
nsobject_t 			nsscreen_CA_CAMLPropertyForKey( nsobject_t arg0 );

// Signature from Objective-C Runtime: @ bs_secureDecodedFromData: @ : @
nsobject_t 			nsscreen_bs_secureDecodedFromData( nsobject_t arg0 );

// Signature from Objective-C Runtime: @ bs_secureDataFromObject: @ : @
nsobject_t 			nsscreen_bs_secureDataFromObject( nsobject_t arg0 );

// Signature from Objective-C Runtime: @ bs_secureObjectFromData:ofClass: @ : @ #
nsobject_t 			nsscreen_bs_secureObjectFromData( nsobject_t arg0, nsclass_t arg1 );

// Signature from Objective-C Runtime: @ bs_dataFromObject: @ : @
nsobject_t 			nsscreen_bs_dataFromObject( nsobject_t arg0 );

// Signature from Objective-C Runtime: @ bs_objectFromData: @ : @
nsobject_t 			nsscreen_bs_objectFromData( nsobject_t arg0 );

// Signature from Objective-C Runtime: @ bs_decodedFromData: @ : @
nsobject_t 			nsscreen_bs_decodedFromData( nsobject_t arg0 );

// Signature from Objective-C Runtime: v load @ :
void 				nsscreen_load( );

// Signature from Objective-C Runtime: q version @ :
long long 			nsscreen_version( );

// Signature from Objective-C Runtime: c instancesImplementSelector: @ : :
char 				nsscreen_instancesImplementSelector( nsselector_t arg0 );

// Signature from Objective-C Runtime: v poseAsClass: @ : #
void 				nsscreen_poseAsClass( nsclass_t arg0 );

// Signature from Objective-C Runtime: v setVersion: @ : q
void 				nsscreen_setVersion( long long arg0 );

// Signature from Objective-C Runtime: c automaticallyNotifiesObserversForKey: @ : @
char 				nsscreen_automaticallyNotifiesObserversForKey( nsobject_t arg0 );

// Signature from Objective-C Runtime: @ classFallbacksForKeyedArchiver @ :
nsobject_t 			nsscreen_classFallbacksForKeyedArchiver( );

// Signature from Objective-C Runtime: # classForKeyedUnarchiver @ :
nsclass_t 			nsscreen_classForKeyedUnarchiver( );

// Signature from Objective-C Runtime: c useStoredAccessor @ :
char 				nsscreen_useStoredAccessor( );

// Signature from Objective-C Runtime: c accessInstanceVariablesDirectly @ :
char 				nsscreen_accessInstanceVariablesDirectly( );

// Signature from Objective-C Runtime: ^{objc_method_description=:*} instanceMethodDescriptionForSelector: @ : :
objc_method_description* nsscreen_instanceMethodDescriptionForSelector( nsselector_t arg0 );

// Signature from Objective-C Runtime: @ keyPathsForValuesAffectingValueForKey: @ : @
nsobject_t 			nsscreen_keyPathsForValuesAffectingValueForKey( nsobject_t arg0 );

// Signature from Objective-C Runtime: v setKeys:triggerChangeNotificationsForDependentKey: @ : @ @
void 				nsscreen_setKeys( nsobject_t arg0, nsobject_t arg1 );

// Signature from Objective-C Runtime: v cancelPreviousPerformRequestsWithTarget:selector:object: @ : @ : @
void 				nsscreen_cancelPreviousPerformRequestsWithTarget( nsobject_t arg0, nsselector_t arg1, nsobject_t arg2 );

// Signature from Objective-C Runtime: v flushAllKeyBindings @ :
void 				nsscreen_flushAllKeyBindings( );

// Signature from Objective-C Runtime: v flushClassKeyBindings @ :
void 				nsscreen_flushClassKeyBindings( );

// Signature from Objective-C Runtime: @ SFSQLiteClassName @ :
nsobject_t 			nsscreen_SFSQLiteClassName( );

// Signature from Objective-C Runtime: @ instanceMethodSignatureForSelector: @ : :
nsobject_t 			nsscreen_instanceMethodSignatureForSelector( nsselector_t arg0 );

// Signature from Objective-C Runtime: @ copyWithZone: @ : ^{_NSZone=}
nsobject_t 			nsscreen_copyWithZone( _NSZone* arg0 );

// Signature from Objective-C Runtime: @ allocWithZone: @ : ^{_NSZone=}
nsobject_t 			nsscreen_allocWithZone( _NSZone* arg0 );

// Signature from Objective-C Runtime: v initialize @ :
void 				nsscreen_initialize( );

// Signature from Objective-C Runtime: @ new @ :
nsobject_t 			nsscreen_new( );

// Signature from Objective-C Runtime: c resolveInstanceMethod: @ : :
char 				nsscreen_resolveInstanceMethod( nsselector_t arg0 );

// Signature from Objective-C Runtime: c resolveClassMethod: @ : :
char 				nsscreen_resolveClassMethod( nsselector_t arg0 );

// Signature from Objective-C Runtime: @ alloc @ :
nsscreen_t 			nsscreen_alloc( );

// Signature from Objective-C Runtime: @ mutableCopyWithZone: @ : ^{_NSZone=}
nsobject_t 			nsscreen_mutableCopyWithZone( _NSZone* arg0 );

// Signature from Objective-C Runtime: c isSubclassOfClass: @ : #
char 				nsscreen_isSubclassOfClass( nsclass_t arg0 );

// Signature from Objective-C Runtime: c isAncestorOfObject: @ : @
char 				nsscreen_isAncestorOfObject( nsobject_t arg0 );

// Signature from Objective-C Runtime: c instancesRespondToSelector: @ : :
char 				nsscreen_instancesRespondToSelector( nsselector_t arg0 );

#endif