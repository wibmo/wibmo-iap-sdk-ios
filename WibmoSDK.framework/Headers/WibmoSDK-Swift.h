#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.3 (swiftlang-1200.0.29.2 clang-1200.0.30.1)
#ifndef WIBMOSDK_SWIFT_H
#define WIBMOSDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="WibmoSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif


@interface UIDevice (SWIFT_EXTENSION(WibmoSDK))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull modalName;)
+ (NSString * _Nonnull)modalName SWIFT_WARN_UNUSED_RESULT;
+ (void)setModalName:(NSString * _Nonnull)value;
@end

typedef SWIFT_ENUM(NSInteger, WSBuildType, closed) {
  WSBuildTypeDev = 0,
  WSBuildTypeStaging = 1,
  WSBuildTypeStaging2 = 2,
  WSBuildTypeStagingV2 = 3,
  WSBuildTypeQa = 4,
  WSBuildTypeUat = 5,
  WSBuildTypeBeta = 6,
  WSBuildTypeProduction = 7,
};


SWIFT_CLASS("_TtC8WibmoSDK10WSCardInfo")
@interface WSCardInfo : NSObject
- (nonnull instancetype)initWithCardTokenRef:(NSString * _Nonnull)cardTokenRef cardTokenReq:(NSString * _Nonnull)cardTokenReq OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



SWIFT_CLASS("_TtC8WibmoSDK14WSCustomerInfo")
@interface WSCustomerInfo : NSObject
- (nonnull instancetype)initWithCustName:(NSString * _Nullable)custName custDob:(NSString * _Nullable)custDob custEmail:(NSString * _Nullable)custEmail custMobile:(NSString * _Nullable)custMobile OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


typedef SWIFT_ENUM(NSInteger, WSIAPVersion, closed) {
  WSIAPVersionV1 = 0,
  WSIAPVersionV2 = 1,
};


SWIFT_CLASS("_TtC8WibmoSDK14WSMerchantInfo")
@interface WSMerchantInfo : NSObject
- (nonnull instancetype)initWithMerName:(NSString * _Nullable)merName merCountryCode:(NSString * _Nullable)merCountryCode merId:(NSString * _Nonnull)merId merAppId:(NSString * _Nonnull)merAppId merUrlScheme:(NSString * _Nullable)merUrlScheme OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


typedef SWIFT_ENUM(NSInteger, WSPaymentCardType, closed) {
  WSPaymentCardTypeAllCards = 0,
  WSPaymentCardTypeVisaCards = 1,
  WSPaymentCardTypeMasterCards = 2,
  WSPaymentCardTypeWalletCards = 3,
  WSPaymentCardTypeRupayCards = 4,
  WSPaymentCardTypeNone = 5,
};

@class WSTransactionInfo;

SWIFT_PROTOCOL("_TtP8WibmoSDK19WSPaymentDatasource_")
@protocol WSPaymentDatasource
- (enum WSBuildType)buildType SWIFT_WARN_UNUSED_RESULT;
- (enum WSIAPVersion)iapVersion SWIFT_WARN_UNUSED_RESULT;
- (WSMerchantInfo * _Nonnull)merchantInfoForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (WSCustomerInfo * _Nonnull)customerInfoForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (BOOL)isWpayTransaction SWIFT_WARN_UNUSED_RESULT;
- (WSCardInfo * _Nullable)cardInfoForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (BOOL)requiresBillingAddressForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (BOOL)requiresShippingAddressForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (BOOL)requiresEmailIdForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_PROTOCOL("_TtP8WibmoSDK17WSPaymentDelegate_")
@protocol WSPaymentDelegate
- (void)paymentSuccessfullForTransaction:(NSDictionary<NSString *, id> * _Nonnull)transaction;
- (void)paymentFailedForTransaction:(NSDictionary<NSString *, id> * _Nonnull)transaction with:(NSError * _Nonnull)error;
- (void)paymentFailedWithError:(NSError * _Nonnull)error;
@end


SWIFT_CLASS("_TtC8WibmoSDK15WSPaymentOption")
@interface WSPaymentOption : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionAllCards;)
+ (NSString * _Nonnull)kPaymentOptionAllCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionVisaCards;)
+ (NSString * _Nonnull)kPaymentOptionVisaCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionMasterCards;)
+ (NSString * _Nonnull)kPaymentOptionMasterCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionRupayCards;)
+ (NSString * _Nonnull)kPaymentOptionRupayCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionWalletCards;)
+ (NSString * _Nonnull)kPaymentOptionWalletCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionNone;)
+ (NSString * _Nonnull)kPaymentOptionNone SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC8WibmoSDK17WSTransactionInfo")
@interface WSTransactionInfo : NSObject
- (nonnull instancetype)initWithMsgHash:(NSString * _Nonnull)msgHash txnCurrency:(NSString * _Nullable)txnCurrency chargeLater:(BOOL)chargeLater merAppData:(NSString * _Nullable)merAppData merTxnId:(NSString * _Nonnull)merTxnId restrictedPaymentType:(NSArray<NSString *> * _Nonnull)restrictedPaymentType txnAmtKnown:(BOOL)txnAmtKnown merDataField:(NSString * _Nullable)merDataField supportedPaymentType:(NSArray<NSString *> * _Nonnull)supportedPaymentType txnDate:(NSString * _Nonnull)txnDate txnDesc:(NSString * _Nullable)txnDesc txnAmount:(NSString * _Nonnull)txnAmount OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@class UIViewController;

SWIFT_CLASS("_TtC8WibmoSDK8WibmoSDK")
@interface WibmoSDK : NSObject
@property (nonatomic, strong) id <WSPaymentDatasource> _Nonnull datasource;
@property (nonatomic, strong) id <WSPaymentDelegate> _Nonnull delegate;
- (nonnull instancetype)initWithTransactionDetails:(WSTransactionInfo * _Nonnull)transactionDetails datasource:(id <WSPaymentDatasource> _Nonnull)datasource delegate:(id <WSPaymentDelegate> _Nonnull)delegate OBJC_DESIGNATED_INITIALIZER;
- (void)performIAPTransactionFrom:(UIViewController * _Nonnull)controller;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#elif defined(__ARM_ARCH_7A__) && __ARM_ARCH_7A__
// Generated by Apple Swift version 5.3 (swiftlang-1200.0.29.2 clang-1200.0.30.1)
#ifndef WIBMOSDK_SWIFT_H
#define WIBMOSDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="WibmoSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif


@interface UIDevice (SWIFT_EXTENSION(WibmoSDK))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, copy) NSString * _Nonnull modalName;)
+ (NSString * _Nonnull)modalName SWIFT_WARN_UNUSED_RESULT;
+ (void)setModalName:(NSString * _Nonnull)value;
@end

typedef SWIFT_ENUM(NSInteger, WSBuildType, closed) {
  WSBuildTypeDev = 0,
  WSBuildTypeStaging = 1,
  WSBuildTypeStaging2 = 2,
  WSBuildTypeStagingV2 = 3,
  WSBuildTypeQa = 4,
  WSBuildTypeUat = 5,
  WSBuildTypeBeta = 6,
  WSBuildTypeProduction = 7,
};


SWIFT_CLASS("_TtC8WibmoSDK10WSCardInfo")
@interface WSCardInfo : NSObject
- (nonnull instancetype)initWithCardTokenRef:(NSString * _Nonnull)cardTokenRef cardTokenReq:(NSString * _Nonnull)cardTokenReq OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



SWIFT_CLASS("_TtC8WibmoSDK14WSCustomerInfo")
@interface WSCustomerInfo : NSObject
- (nonnull instancetype)initWithCustName:(NSString * _Nullable)custName custDob:(NSString * _Nullable)custDob custEmail:(NSString * _Nullable)custEmail custMobile:(NSString * _Nullable)custMobile OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


typedef SWIFT_ENUM(NSInteger, WSIAPVersion, closed) {
  WSIAPVersionV1 = 0,
  WSIAPVersionV2 = 1,
};


SWIFT_CLASS("_TtC8WibmoSDK14WSMerchantInfo")
@interface WSMerchantInfo : NSObject
- (nonnull instancetype)initWithMerName:(NSString * _Nullable)merName merCountryCode:(NSString * _Nullable)merCountryCode merId:(NSString * _Nonnull)merId merAppId:(NSString * _Nonnull)merAppId merUrlScheme:(NSString * _Nullable)merUrlScheme OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


typedef SWIFT_ENUM(NSInteger, WSPaymentCardType, closed) {
  WSPaymentCardTypeAllCards = 0,
  WSPaymentCardTypeVisaCards = 1,
  WSPaymentCardTypeMasterCards = 2,
  WSPaymentCardTypeWalletCards = 3,
  WSPaymentCardTypeRupayCards = 4,
  WSPaymentCardTypeNone = 5,
};

@class WSTransactionInfo;

SWIFT_PROTOCOL("_TtP8WibmoSDK19WSPaymentDatasource_")
@protocol WSPaymentDatasource
- (enum WSBuildType)buildType SWIFT_WARN_UNUSED_RESULT;
- (enum WSIAPVersion)iapVersion SWIFT_WARN_UNUSED_RESULT;
- (WSMerchantInfo * _Nonnull)merchantInfoForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (WSCustomerInfo * _Nonnull)customerInfoForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (BOOL)isWpayTransaction SWIFT_WARN_UNUSED_RESULT;
- (WSCardInfo * _Nullable)cardInfoForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (BOOL)requiresBillingAddressForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (BOOL)requiresShippingAddressForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
- (BOOL)requiresEmailIdForTransaction:(WSTransactionInfo * _Nonnull)transaction SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_PROTOCOL("_TtP8WibmoSDK17WSPaymentDelegate_")
@protocol WSPaymentDelegate
- (void)paymentSuccessfullForTransaction:(NSDictionary<NSString *, id> * _Nonnull)transaction;
- (void)paymentFailedForTransaction:(NSDictionary<NSString *, id> * _Nonnull)transaction with:(NSError * _Nonnull)error;
- (void)paymentFailedWithError:(NSError * _Nonnull)error;
@end


SWIFT_CLASS("_TtC8WibmoSDK15WSPaymentOption")
@interface WSPaymentOption : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionAllCards;)
+ (NSString * _Nonnull)kPaymentOptionAllCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionVisaCards;)
+ (NSString * _Nonnull)kPaymentOptionVisaCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionMasterCards;)
+ (NSString * _Nonnull)kPaymentOptionMasterCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionRupayCards;)
+ (NSString * _Nonnull)kPaymentOptionRupayCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionWalletCards;)
+ (NSString * _Nonnull)kPaymentOptionWalletCards SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull kPaymentOptionNone;)
+ (NSString * _Nonnull)kPaymentOptionNone SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC8WibmoSDK17WSTransactionInfo")
@interface WSTransactionInfo : NSObject
- (nonnull instancetype)initWithMsgHash:(NSString * _Nonnull)msgHash txnCurrency:(NSString * _Nullable)txnCurrency chargeLater:(BOOL)chargeLater merAppData:(NSString * _Nullable)merAppData merTxnId:(NSString * _Nonnull)merTxnId restrictedPaymentType:(NSArray<NSString *> * _Nonnull)restrictedPaymentType txnAmtKnown:(BOOL)txnAmtKnown merDataField:(NSString * _Nullable)merDataField supportedPaymentType:(NSArray<NSString *> * _Nonnull)supportedPaymentType txnDate:(NSString * _Nonnull)txnDate txnDesc:(NSString * _Nullable)txnDesc txnAmount:(NSString * _Nonnull)txnAmount OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@class UIViewController;

SWIFT_CLASS("_TtC8WibmoSDK8WibmoSDK")
@interface WibmoSDK : NSObject
@property (nonatomic, strong) id <WSPaymentDatasource> _Nonnull datasource;
@property (nonatomic, strong) id <WSPaymentDelegate> _Nonnull delegate;
- (nonnull instancetype)initWithTransactionDetails:(WSTransactionInfo * _Nonnull)transactionDetails datasource:(id <WSPaymentDatasource> _Nonnull)datasource delegate:(id <WSPaymentDelegate> _Nonnull)delegate OBJC_DESIGNATED_INITIALIZER;
- (void)performIAPTransactionFrom:(UIViewController * _Nonnull)controller;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif

#endif
