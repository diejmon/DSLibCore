
@import Foundation;

NS_ASSUME_NONNULL_BEGIN

//TODO: doesn't work with cross references.
//23.11.2012 Tried to add support for cross references but got an issues with description for NSNumber, NSString etc.
#define OVERWRITE_DESCRIPTION 0

@interface NSObject (DSAdditions)
#if !OVERWRITE_DESCRIPTION
- (NSString *)longDescription;
#endif

+ (NSArray *)propertyNames;

- (NSMutableDictionary*)objectUserInfo;

+ (NSArray *)propertiesPassingTest:(BOOL(^)(Class propertyClass))test;
- (NSDictionary *)keysAndValuesForPropertiesPassingTest:(BOOL (^)(Class propertyClass))test;
- (NSDictionary *)keysAndValuesForPropertiesPassingTest:(BOOL (^)(Class propertyClass))test
                                    includeSuperClasses:(BOOL)includeSuperClasses
                                           includeDepth:(NSUInteger)depth;
- (NSDictionary *)filterOutNonRespondingKeys:(NSDictionary *)keysAndValues;

- (nullable id)ds_jsonValueForKeyPath:(nullable NSString *)keyPath;

- (nullable NSString *)ds_jsonStringWithPrettyPrint:(BOOL)prettyPrint;
@end

NS_ASSUME_NONNULL_END
