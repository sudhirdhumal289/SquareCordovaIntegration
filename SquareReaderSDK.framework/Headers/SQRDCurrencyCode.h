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

/**
 A list of currencies in ISO 4217 format.
 
 Each numeric value corresponds to the ISO 4217 numeric code for that currency except `.unknown` and `.automatic`.
 */
typedef NS_ENUM(NSUInteger, SQRDCurrencyCode) {
    /** The currency code is unknown or not supported by Reader SDK. */
    SQRDCurrencyCodeUnknown = 0,

    /** The currency code is set automatically from the currency code of the authorized location at the time of checkout. */
    SQRDCurrencyCodeAutomatic = -1,

    SQRDCurrencyCodeAED = 784,
    SQRDCurrencyCodeALL = 8,
    SQRDCurrencyCodeAMD = 51,
    SQRDCurrencyCodeAOA = 973,
    SQRDCurrencyCodeARS = 32,
    SQRDCurrencyCodeAUD = 36,
    SQRDCurrencyCodeAWG = 533,
    SQRDCurrencyCodeAZN = 944,
    SQRDCurrencyCodeBAM = 977,
    SQRDCurrencyCodeBBD = 52,
    SQRDCurrencyCodeBDT = 50,
    SQRDCurrencyCodeBGN = 975,
    SQRDCurrencyCodeBHD = 48,
    SQRDCurrencyCodeBMD = 60,
    SQRDCurrencyCodeBND = 96,
    SQRDCurrencyCodeBOB = 68,
    SQRDCurrencyCodeBRL = 986,
    SQRDCurrencyCodeBSD = 44,
    SQRDCurrencyCodeBTN = 64,
    SQRDCurrencyCodeBWP = 72,
    SQRDCurrencyCodeBYR = 974,
    SQRDCurrencyCodeBZD = 84,
    SQRDCurrencyCodeCAD = 124,
    SQRDCurrencyCodeCDF = 976,
    SQRDCurrencyCodeCHF = 756,
    SQRDCurrencyCodeCLP = 152,
    SQRDCurrencyCodeCNY = 156,
    SQRDCurrencyCodeCOP = 170,
    SQRDCurrencyCodeCRC = 188,
    SQRDCurrencyCodeCVE = 132,
    SQRDCurrencyCodeCZK = 203,
    SQRDCurrencyCodeDKK = 208,
    SQRDCurrencyCodeDOP = 214,
    SQRDCurrencyCodeDZD = 12,
    SQRDCurrencyCodeEGP = 818,
    SQRDCurrencyCodeETB = 230,
    SQRDCurrencyCodeEUR = 978,
    SQRDCurrencyCodeFJD = 242,
    SQRDCurrencyCodeGBP = 826,
    SQRDCurrencyCodeGEL = 981,
    SQRDCurrencyCodeGHS = 936,
    SQRDCurrencyCodeGIP = 292,
    SQRDCurrencyCodeGMD = 270,
    SQRDCurrencyCodeGTQ = 320,
    SQRDCurrencyCodeGYD = 328,
    SQRDCurrencyCodeHKD = 344,
    SQRDCurrencyCodeHNL = 340,
    SQRDCurrencyCodeHRK = 191,
    SQRDCurrencyCodeHTG = 332,
    SQRDCurrencyCodeHUF = 348,
    SQRDCurrencyCodeIDR = 360,
    SQRDCurrencyCodeILS = 376,
    SQRDCurrencyCodeINR = 356,
    SQRDCurrencyCodeISK = 352,
    SQRDCurrencyCodeJMD = 388,
    SQRDCurrencyCodeJOD = 400,
    SQRDCurrencyCodeJPY = 392,
    SQRDCurrencyCodeKES = 404,
    SQRDCurrencyCodeKGS = 417,
    SQRDCurrencyCodeKHR = 116,
    SQRDCurrencyCodeKRW = 410,
    SQRDCurrencyCodeKWD = 414,
    SQRDCurrencyCodeKYD = 136,
    SQRDCurrencyCodeKZT = 398,
    SQRDCurrencyCodeLAK = 418,
    SQRDCurrencyCodeLBP = 422,
    SQRDCurrencyCodeLKR = 144,
    SQRDCurrencyCodeLRD = 430,
    SQRDCurrencyCodeLTL = 440,
    SQRDCurrencyCodeMAD = 504,
    SQRDCurrencyCodeMDL = 498,
    SQRDCurrencyCodeMGA = 969,
    SQRDCurrencyCodeMKD = 807,
    SQRDCurrencyCodeMMK = 104,
    SQRDCurrencyCodeMNT = 496,
    SQRDCurrencyCodeMOP = 446,
    SQRDCurrencyCodeMRO = 478,
    SQRDCurrencyCodeMUR = 480,
    SQRDCurrencyCodeMWK = 454,
    SQRDCurrencyCodeMXN = 484,
    SQRDCurrencyCodeMYR = 458,
    SQRDCurrencyCodeMZN = 943,
    SQRDCurrencyCodeNAD = 516,
    SQRDCurrencyCodeNGN = 566,
    SQRDCurrencyCodeNIO = 558,
    SQRDCurrencyCodeNOK = 578,
    SQRDCurrencyCodeNPR = 524,
    SQRDCurrencyCodeNZD = 554,
    SQRDCurrencyCodeOMR = 512,
    SQRDCurrencyCodePAB = 590,
    SQRDCurrencyCodePEN = 604,
    SQRDCurrencyCodePGK = 598,
    SQRDCurrencyCodePHP = 608,
    SQRDCurrencyCodePKR = 586,
    SQRDCurrencyCodePLN = 985,
    SQRDCurrencyCodePYG = 600,
    SQRDCurrencyCodeQAR = 634,
    SQRDCurrencyCodeRON = 946,
    SQRDCurrencyCodeRSD = 941,
    SQRDCurrencyCodeRUB = 643,
    SQRDCurrencyCodeRWF = 646,
    SQRDCurrencyCodeSAR = 682,
    SQRDCurrencyCodeSBD = 90,
    SQRDCurrencyCodeSCR = 690,
    SQRDCurrencyCodeSEK = 752,
    SQRDCurrencyCodeSGD = 702,
    SQRDCurrencyCodeSLL = 694,
    SQRDCurrencyCodeSRD = 968,
    SQRDCurrencyCodeSTD = 678,
    SQRDCurrencyCodeSVC = 222,
    SQRDCurrencyCodeSZL = 748,
    SQRDCurrencyCodeTHB = 764,
    SQRDCurrencyCodeTJS = 972,
    SQRDCurrencyCodeTMT = 934,
    SQRDCurrencyCodeTND = 788,
    SQRDCurrencyCodeTRY = 949,
    SQRDCurrencyCodeTTD = 780,
    SQRDCurrencyCodeTWD = 901,
    SQRDCurrencyCodeTZS = 834,
    SQRDCurrencyCodeUAH = 980,
    SQRDCurrencyCodeUGX = 800,
    SQRDCurrencyCodeUSD = 840,
    SQRDCurrencyCodeUYU = 858,
    SQRDCurrencyCodeUZS = 860,
    SQRDCurrencyCodeVEF = 937,
    SQRDCurrencyCodeVND = 704,
    SQRDCurrencyCodeXAF = 950,
    SQRDCurrencyCodeXCD = 951,
    SQRDCurrencyCodeXOF = 952,
    SQRDCurrencyCodeYER = 886,
    SQRDCurrencyCodeZAR = 710,
    SQRDCurrencyCodeZMW = 967,
};

// clang-format off

/**
 Make a SQRDCurrencyCode from an ISO 4217 currency code.
 
 @param ISOCurrencyCode An ISO 4217 currency code.
 @returns The corresponding SQRDCurrencyCode if `ISOCurrencyCode` is a valid ISO currency code; otherwise `.unknown`.
 */
extern SQRDCurrencyCode SQRDCurrencyCodeMake(NSString * _Nonnull ISOCurrencyCode) CF_SWIFT_NAME(SQRDCurrencyCode.init(isoCurrencyCode:));

/**
 Get the corresponding ISO 4217 currency code from a SQRDCurrencyCode.
 
 @param currencyCode A currency code.
 @returns The corresponding ISO 4217 currency code if `currencyCode` is not `.unknown` or `.automatic`.
 */

extern NSString * _Nonnull SQRDCurrencyCodeGetISOCurrencyCode(SQRDCurrencyCode currencyCode) CF_SWIFT_NAME(getter:SQRDCurrencyCode.isoCurrencyCode(self:));

// clang-format on
