@import Foundation;

NS_ASSUME_NONNULL_BEGIN

/** First In First Out queue.
 If number of items exceed theCapacity defined in initWithCapacity: method the object which
 came first will be removed.
 If you use init: method the capacity will be NSUIntegerMax.
 */
@interface DSQueue<ObjectType> : NSObject
<
NSCoding,
NSCopying,
NSFastEnumeration
> 

/** \param theCapacity maximum number of items in queue */
- (instancetype)initWithCapacity:(NSUInteger)theCapacity NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCoder:(NSCoder *__nonnull)aDecoder NS_DESIGNATED_INITIALIZER;
+ (instancetype)queue;

/** \return Poped object from the queue. The one which pushed last. */
- (ObjectType __nullable)pop;

/** Adds theObject to the end of queue. 
 @param theObject nil values ignored
 */
- (void)push:(ObjectType __nullable)theObject;
/** Adds theObject to the beginning of the queue */
- (void)pushBack:(ObjectType __nullable)theObject;

- (void)pushObjectsFromArray:(NSArray<ObjectType> *__nullable)array;

/** The top object in the queue */
- (nullable ObjectType)top;

/** The first object in queue */
- (nullable ObjectType)first;

/** Remove all objects from the queue */
- (void)removeAll;

/** Remove specific objects from queue */
- (void)removeObjectsInArray:(NSArray<ObjectType> *__nullable)theObjects;

- (BOOL)containsObject:(ObjectType __nullable)anObject;

/** \return current number of objects in the queue */
- (NSUInteger)count;

/** \return maximum number of objects in the queue */
- (NSUInteger)capacity;

/** \return YES if capacity == count. 
 \note KVO is supported by this method */
- (BOOL)isFull;

/** \return enumerator for all objects in queue */
- (NSEnumerator<ObjectType> *)objectEnumerator;

/** \return reversed enumerator for all objects in queue */
- (NSEnumerator<ObjectType> *)reverseObjectEnumerator;

- (ObjectType __nullable)firstObjectWhichEqualsTo:(ObjectType)object;

- (void)filterWithPredicate:(NSPredicate *)predicate;

- (NSArray<ObjectType> *)array;
@end

/** For internal and subclass use */
@interface DSQueue()
@property (assign) BOOL isFull;
@end

NS_ASSUME_NONNULL_END
