#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX" ,soundex);
  ASSERT_STREQ(soundex,"A200");
}
TEST(SoudexTestsuite, gettingvaluesfrommacro) {
 //AAA
  char c;
 GET_SOUNDEX_CODE(c);
}
