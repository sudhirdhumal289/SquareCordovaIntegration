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

@class SQRDMoney;

/**
 Represents the details related to a cash payment.
 */
@interface SQRDTenderCashDetails : NSObject <NSCopying>

/**
 The total amount of cash provided to pay for the transaction, before change is given.
 */
@property (nonatomic, readonly, nonnull) SQRDMoney *buyerTenderedMoney;

/**
 The total amount of cash returned during the transaction as change.
 */
@property (nonatomic, readonly, nonnull) SQRDMoney *changeBackMoney;

#pragma mark - NSObject

/**
 :nodoc:
 Returns a Boolean value that indicates whether the receiver and a given SQRDTenderCashDetails are equal.
 */
- (BOOL)isEqual:(nullable SQRDTenderCashDetails *)object;

/**
 :nodoc:
 Returns an integer that can be used as a table address in a hash table structure.
 */
@property (readonly) NSUInteger hash;

/** :nodoc: */
- (nonnull instancetype)init NS_UNAVAILABLE;

/** :nodoc: */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
