#include <gmock/gmock.h>
#include "Soundex.h"

using namespace testing;

/*
 * Fixture class to eliminate the code duplication in each test
 */
class SoundexEncoding : public Test
{
public:
    Soundex soundex;
};

/*
 * The first rule tells us to retain the first letter of the name.
 */
TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

/*
 * The fourth rule tells us to zero pad the result to reach 4 digit overall result
 */
TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

/*
 * The second rule tells us to replace consonants with digits after the first letter
 */
TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
    ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
}
