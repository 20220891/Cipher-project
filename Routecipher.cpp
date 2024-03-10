#include <iostream>
#include<string>
#include<vector>

using namespace std;
//function to remove non-letter characters and capitalize letters
string preprocesstext(const string& input){
    string result;
    for (char c: input){
        if (isalpha(c)){
            result += toupper(c);
        }
    }
    return result;
}
//funcrion to encrypt the next using the specified grid width
string encrypttext(const string & input, int gridwidth){
    int numRows = input.length() / gridwidth;
    vector<vector<char>> grid(numRows, vector<char>(gridwidth));

    //fill the grid row by row
    int idx = 0;
    for (int row = 0; row < numRows; ++row){
        for (int col = 0; col < gridwidth; ++col){
            grid[row][col] =input[idx++]; 
        }
    }
    //Read the grid clokwise, starting from the top right corner
    string ciphertext;
    for (int col = gridwidth - 1; col >=0; --col){
        for (int row = 0; row < numRows; ++row){
            ciphertext += grid[row][col];
        }
    }
    return ciphertext;
    
 }   
 int main(){
    string cityName = "Brighton and hove";
    int secretkey = 3;

    //preprocess the text
    string processedtext = preprocesstext(cityName);

    //Encrypt the text 
    string encryptedtext = encrypttext(processedtext, secretkey);

    cout <<"Encrypted text:" <<encryptedtext<< endl;

    return 0;
 }

















