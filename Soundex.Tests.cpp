#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX" ,soundex);
  ASSERT_STREQ(soundex,"A200");
}

TEST(SoundexTest, BasicFunctionality) {
    char soundex[5];
    generateSoundex("Robert", soundex);
    EXPECT_STREQ(soundex, "R163");
}

TEST(SoundexTest, SimilarStartingLetters) {
    char soundex[5];
    generateSoundex("Ashitosh", soundex);
    EXPECT_STREQ(soundex, "A232");
    
    generateSoundex("Ashitom", soundex);
    EXPECT_STREQ(soundex, "A235");
}


TEST(SoundexTest, DifferentLengths) {
    char soundex[5];
    generateSoundex("Apple", soundex);
    EXPECT_STREQ(soundex, "A140");
    
    generateSoundex("Apples", soundex);
    EXPECT_STREQ(soundex, "A142");
   
}


TEST(SoundexTest, NoMatchingConsonantCodes) {
    char soundex[5];
    generateSoundex("Euler", soundex);
    EXPECT_STREQ(soundex, "E460");
    
    generateSoundex("Ellery", soundex);
    EXPECT_STREQ(soundex, "E460");
}


TEST(SoundexTest, RepeatedLetters) {
    char soundex[5];
    generateSoundex("Bobby", soundex);
    EXPECT_STREQ(soundex, "B100");
    
    generateSoundex("Booby", soundex);
    EXPECT_STREQ(soundex, "B100");
}


TEST(SoundexTest, Vowelcase) {
    char soundex[5];
    generateSoundex("A", soundex);
    EXPECT_STREQ(soundex, "A000");
    
    generateSoundex("E", soundex);
    EXPECT_STREQ(soundex, "E000");
    
    generateSoundex("I", soundex);
    EXPECT_STREQ(soundex, "I000");
    
    generateSoundex("O", soundex);
    EXPECT_STREQ(soundex, "O000");
    
    generateSoundex("U", soundex);
    EXPECT_STREQ(soundex, "U000");
}

TEST(SoundexTest, NonAlphabet) {
    char soundex[5];
    generateSoundex("O@Mygod", soundex);
    EXPECT_STREQ(soundex, "O523");
   

   generateSoundex("D2Areto", soundex);
    EXPECT_STREQ(soundex, "D630");
     
}





