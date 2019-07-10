//
//  UBSignalObserver.h
//  UberSignals
//
//  Copyright (c) 2015 Uber Technologies, Inc.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSUInteger UBObserverPriority NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT const UBObserverPriority UBObserverPriorityDefaultVeryHigh; // 1000
FOUNDATION_EXPORT const UBObserverPriority UBObserverPriorityDefaultHigh;     // 750
FOUNDATION_EXPORT const UBObserverPriority UBObserverPriorityDefaultNormal;   // 500
FOUNDATION_EXPORT const UBObserverPriority UBObserverPriorityDefaultLow;      // 250
FOUNDATION_EXPORT const UBObserverPriority UBObserverPriorityDefaultVeryLow;  // 200

/**
 A SignalObserver is returned whenever an observer is added to a UBSignal. Use it to cancel this specific observation or change the OperationQueue on which to dispatch the callback on.
 */
@interface UBSignalObserver : NSObject

/*
 An opertion OperationQueue to dispath the callback on. If nil (default), the callback will be dispatched on the same queue as the signal fires on.
 */
@property (nonatomic) NSOperationQueue *operationQueue;

/*
 If YES, cancels the observer once the signal has fired the next time.
 */
@property (nonatomic) BOOL cancelsAfterNextFire;

@property (nonatomic, readonly) UBObserverPriority priority;

/**
 Cancels the observation for this specific observer and callback block.
 */
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
