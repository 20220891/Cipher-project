#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
using namespace std;

map<char, string> morseCodeMap = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {' ', " "} // Space between words
};

string textToMorse(const string &text) {
  string morse;
  for(char c: text) {
    if(morseCodeMap.find(toupper(c)) != morseCodeMap.end()) {
      morse += morseCodeMap[toupper(c)] + " ";
    }
  }
  return morse;
}

string morseToText(const string &morse) {
  stringstream ss(morse);
  string token, text;
  while(ss >> token) {
    for(const auto &pair : morseCodeMap) {
      if(pair.second == token) {
        text += pair.first;
        break;
      }
    }
  }
  return text;
}

int main() {
  string userText;
  cout << "Enter a message: ";
  getline(cin, userText);

  string morseText = textToMorse(userText);
  cout << "Morse code: " << morseText << endl;

  string decodeText = morseToText(morseText);
  cout << "Decoded message: " << decodeText << endl;

  return 0;
 }
