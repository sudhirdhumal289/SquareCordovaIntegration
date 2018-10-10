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

/** Indicates a card's brand, such as Visa. */
typedef NS_ENUM(NSInteger, SQRDCardBrand) {
    /** An unidentified brand. */
    SQRDCardBrandOtherBrand = 0,

    /** Visa */
    SQRDCardBrandVisa,

    /** Mastercard */
    SQRDCardBrandMastercard,

    /** Discover */
    SQRDCardBrandDiscover,

    /** American Express */
    SQRDCardBrandAmericanExpress,

    /** Diners Club International */
    SQRDCardBrandDiscoverDiners,

    /** Interac */
    SQRDCardBrandInterac,

    /** JCB */
    SQRDCardBrandJCB,

    /** China UnionPay */
    SQRDCardBrandChinaUnionPay,

    /** Square Gift Card */
    SQRDCardBrandSquareGiftCard
};

/**
 Represents the non-confidential details of a payment card.
 */
@interface SQRDCard : NSObject <NSCopying>

/**
 The card brand (for example, Visa).
 */
@property (nonatomic, readonly) SQRDCardBrand brand;

/**
  The last four digits of the card number.
 */
@property (nonatomic, readonly, nonnull) NSString *lastFourDigits;

#pragma mark - NSObject

/**
 Returns a Boolean value that indicates whether the receiver and a given SQRDCard are equal.
 */
- (BOOL)isEqual:(nullable SQRDCard *)object;

/**
 Returns an integer that can be used as a table address in a hash table structure.
 */
@property (readonly) NSUInteger hash;

/** :nodoc: */
- (nonnull instancetype)init NS_UNAVAILABLE;

/** :nodoc: */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
