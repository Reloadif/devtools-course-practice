// Copyright 2022 Chornyi Yura

#include "include/vigenere_cipher.h"

#include <sstream>

bool checkString(const std::string str) {
	for (auto element : str) {
		if (element < 65 || element > 90) return false;
	}

	return true;
}

VigenereCipher::VigenereCipher() : m_original(), m_key() {}
VigenereCipher::VigenereCipher(const std::string& original, const std::string& key) : m_original(original), m_key(key) {
	if (m_original.size() != m_key.size()) throw std::exception("Original string size not equal key string size!");
	if (!checkString(original)) throw std::exception("Original string has not allowed characters!");
	if (!checkString(key)) throw std::exception("Key string has not allowed characters!");
}

const std::string& VigenereCipher::getOriginal() const {
	return m_original;
}
const std::string& VigenereCipher::getKey() const {
	return m_key;
}

void VigenereCipher::setOriginal(const std::string& original) {
	if (m_original.size() != original.size()) throw std::exception("Original string size not equal new original string size!");
	if (!checkString(original)) throw std::exception("Original string has not allowed characters!");

	m_original = original;
}
void VigenereCipher::setKey(const std::string& key) {
	if (m_key.size() != key.size()) throw std::exception("Key string size not equal new key string size!");
	if (!checkString(key)) throw std::exception("Key string has not allowed characters!");

	m_key = key;
}

void VigenereCipher::setPair(const std::string& original, const std::string& key) {
	if (original.size() != key.size()) throw std::exception("New original string size not equal new key string size!");
	if (!checkString(original)) throw std::exception("Original string has not allowed characters!");
	if (!checkString(key)) throw std::exception("Key string has not allowed characters!");
	
	m_original = original;
	m_key = key;
}

std::string VigenereCipher::cipher() const {
	std::stringstream cipher;

	for (std::string::size_type it = 0; it < m_original.size(); ++it) {
		cipher << static_cast<char>(65 + (m_original[it] + m_key[it]) % 26);
	}

	return cipher.str();
}
