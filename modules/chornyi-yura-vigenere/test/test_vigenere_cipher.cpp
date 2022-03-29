// Copyright 2022 Chornyi Yura

#include <gtest/gtest.h>
#include <tuple>
#include <string>

#include "include/vigenere_cipher.h"

TEST(Constructor, ConstructorWithoutParameters) {
    ASSERT_NO_THROW(VigenereCipher());
}

TEST(Constructor, ConstructorWithTwoParameters) {
    ASSERT_NO_THROW(VigenereCipher("TEST", "QWER"));
}

TEST(Constructor, ConstructorWithTwoParametersNotEqualSize) {
    ASSERT_ANY_THROW(VigenereCipher("TEST", ""));
}

TEST(Constructor, ConstructorWithTwoParametersWithNotAllowedCharacter) {
    ASSERT_ANY_THROW(VigenereCipher("TE12", "QW12"));
}

TEST(Methods, CheckDefaultValue) {
    VigenereCipher v;

    ASSERT_EQ(v.getOriginal(), "");
    ASSERT_EQ(v.getKey(), "");
}

TEST(Methods, CheckCustomValue) {
    VigenereCipher v("TEST", "QWER");

    ASSERT_EQ(v.getOriginal(), "TEST");
    ASSERT_EQ(v.getKey(), "QWER");
}

TEST(Methods, CheckCipheringWithoutParameters) {
    VigenereCipher v;

    std::string cipher = v.cipher();

    ASSERT_EQ(cipher, "");
}

TEST(Methods, CheckCipheringWithParameters) {
    VigenereCipher v("ATTACKATDAWN", "LEMONLEMONLE");

    std::string cipher = v.cipher();

    ASSERT_EQ(cipher, "LXFOPVEFRNHR");
}

TEST(Methods, CheckSetOriginalEqualKey) {
    VigenereCipher v("TEST", "QWER");

    v.setOriginal("QQQQ");

    ASSERT_EQ(v.getOriginal(), "QQQQ");
}

TEST(Methods, CheckSetOriginalNotEqualKey) {
    VigenereCipher v("TEST", "QWER");

    ASSERT_ANY_THROW(v.setOriginal("T"));
}

TEST(Methods, CheckSetOriginalWithNotAllowedCharacter) {
    VigenereCipher v("TEST", "QWER");

    ASSERT_ANY_THROW(v.setOriginal("TE12"));
}

TEST(Methods, CheckSetKeyEqualOriginal) {
    VigenereCipher v("TEST", "QWER");

    v.setKey("QQQQ");

    ASSERT_EQ(v.getKey(), "QQQQ");
}

TEST(Methods, CheckSetKeyNotEqualOriginal) {
    VigenereCipher v("TEST", "QWER");

    ASSERT_ANY_THROW(v.setKey("Q"));
}

TEST(Methods, CheckSetKeyWithNotAllowedCharacter) {
    VigenereCipher v("TEST", "QWER");

    ASSERT_ANY_THROW(v.setOriginal("QW12"));
}

TEST(Methods, CheckSetPairWithEqualSize) {
    VigenereCipher v("TEST", "QWER");

    v.setPair("QWER", "TEST");

    ASSERT_EQ(v.getOriginal(), "QWER");
    ASSERT_EQ(v.getKey(), "TEST");
}

TEST(Methods, CheckSetPairWithoutEqualSize) {
    VigenereCipher v("TEST", "QWER");

    ASSERT_ANY_THROW(v.setPair("TEST", "Q"));
}

TEST(Methods, CheckSetPairWithNotAllowedCharacter) {
    VigenereCipher v("TEST", "QWER");

    ASSERT_ANY_THROW(v.setPair("TE12", "QW12"));
}
