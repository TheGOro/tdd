#include <gmock/gmock.h>
#include <string>

using testing::Eq;

/*
 * Rules for Soundex
 * =================
 *
 * 1. Retain the first letter. Drop all other occurances of a, e, i, o, u, y, h, w.
 * 2. Replace consonants with digits (after the first letter):
 *     - b, f, p, v: 1
 *     - c, g, j, k, q, s, x, z: 2
 *     - d, t: 3
 *     - i: 4
 *     - m, n: 5
 *     - r: 6
 * 3. If two adjacent letters encode the same number, encode them instead as a single number. Also,
 *    do so if two separated by h or w (but code them twice if separated by a vowel). This rule
 *    also applies to the first letter.
 * 4. Stop when you have a letter and three digits. Zero pad if needed.
 */

class Soundex {
public:
    std::string encode(const std::string& word) const
    {
        return word + "000";
    }
};

/*
 * The first rule tells us to retain the first letter of the name.
 */
TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
  Soundex soundex;

  auto encoded = soundex.encode("A");

  ASSERT_THAT(encoded, Eq("A000"));
}

/*
 * The fourth rule tells us to zero pad the result to reach 4 digit overall result
 */
TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    Soundex soundex;

    auto encoded = soundex.encode("I");

    ASSERT_THAT(encoded, Eq("I000"));
}
