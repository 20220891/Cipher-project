#include <iostream>
#include <string>
using namespace std;

// Function to encrypt a single character
char encryptChar(char ch, int a , int b) {
  if(isalpha(ch)) {
    char base = islower(ch) ? 'a' : 'A';
    int x = ch - base;
    return ((a * x + b) % 26) + base;
  }

  return ch;
}

// Function to decrypt a single character
char decryptChar(char ch, int a, int b, int c) {
  if(isalpha(ch)) {
     char base = islower(ch) ? 'a' : 'A';
      int y = ch - base;
      return (((c * (y - b)) % 26) + 26) % 26 + base;
  }

  return ch; // If not alphabet character, return the character unchanged
}

// Function to encrypt a string
string encrypt(string plaintext, int a, int b) {
  string ciphertext = "";
  for(char &ch : plaintext) {
    ciphertext += encryptChar(ch, a, b);
  }
  return ciphertext;
}

// Function to decrypt a string
string decrypt(string ciphertext, int a, int b, int c) {
  string plaintext = "";
  for(char &ch : ciphertext) {
    plaintext += decryptChar(ch, a, b, c);
  }
  return plaintext;
}

int main() {
  // Constants for encryption and decryption
  int a = 5, b = 8, c = 21; 
  string plaintext = "AFFINECIPHER";

  // Encryption
  string encrypted_text = encrypt(plaintext, a, b);
  cout << "Encrypted: " << encrypted_text << endl;

  // Decryption
  string decrypted_text = decrypt(encrypted_text, a, b, c);
  cout << "Decrypted: " << decrypted_text << endl;
}
