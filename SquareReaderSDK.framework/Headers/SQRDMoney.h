//
//	Copyright (c) 2018-present, Square, Inc. All rights reserved.
//
//	Your use of this software is subject to the Square Developer Terms of
//	Service (https://squareup.com/legal/developers). This copyright notice shall
//	be included in all copies or substantial portions of the software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import <SquareReaderSDK/SQRDCurrencyCode.h>

/// Represents an amount of money.
@interface SQRDMoney : NSObject <NSCopying>

/**
 Create a new `SQRDMoney` instance.
 
 The currency is set automatically based on the currency of the authorized location at the time of checkout.

 @param amount The monetary amount, specified as a non-negative integer in the smallest currency denomination of the authorized location.
               For example, when the location's currency is USD, the amount is in cents.
 */
- (nonnull instancetype)initWithAmount:(NSInteger)amount;

/**
 Create a new `SQRDMoney` instance.
 
 @param amount The monetary amount, specified as a non-negative integer in the smallest currency denomination of the authorized location.
               For example, when the `currencyCode` is `.usd`, the amount is in cents.
 @param currencyCode The currency code (for example, the currency code for the US Dollar is `.usd`).
 */
- (nonnull instancetype)initWithAmount:(NSInteger)amount currencyCode:(SQRDCurrencyCode)currencyCode;

/**
 The amount of money in the smallest denomination of the currency.
 
 For example, when `currencyCode` is `.usd`, the amount is in cents.
 */
@property (nonatomic, readonly) NSInteger amount;

/**
 The currency code.
 */
@property (nonatomic, readonly) SQRDCurrencyCode currencyCode;

#pragma mark - NSObject

/**
 :nodoc:
 Returns a Boolean value that indicates whether the receiver and a given SQRDMoney are equal.
 */
- (BOOL)isEqual:(nullable SQRDMoney *)object;

/**
 :nodoc:
 Returns an integer that can be used as a table address in a hash table structure.
 */
@property (readonly) NSUInteger hash;

/**
 :nodoc:
 `init` is unavailable. Use `initWithAmount:` or `initWithAmount:currencyCode:` instead.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 :nodoc:
 `new` is unavailable. Use `initWithAmount:` or `initWithAmount:currencyCode:` instead.
 */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
