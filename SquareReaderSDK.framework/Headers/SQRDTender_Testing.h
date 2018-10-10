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

#import <SquareReaderSDK/SQRDTender.h>


@interface SQRDTender (Testing)

- (nonnull instancetype)initWithClientID:(nonnull NSString *)clientID
                               createdAt:(nonnull NSDate *)createdAt
                              totalMoney:(nonnull SQRDMoney *)totalMoney
                                tipMoney:(nonnull SQRDMoney *)tipMoney
                                    type:(SQRDTenderType)type
                                serverID:(nullable NSString *)serverID
                             cardDetails:(nullable SQRDTenderCardDetails *)cardDetails
                             cashDetails:(nullable SQRDTenderCashDetails *)cashDetails;

@end
