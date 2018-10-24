//
//  main.cpp
//  Midterm 2 exercice
//
//  Created by Tomás González on 2016-11-07.
//  Copyright © 2016 Tomás González. All rights reserved.
//
// LIBRARIES
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

// FUNCTION PROTOTYPES
void welcome();
void arrayInitialize(int[], const int, const int);
int getWordNo(int);
int getSentenceNo(int);

// GLOBAL VARIABLES
int numberOfLetters[0];
int words = 0;
int sentences = 0;

// FUNCTIONS
void welcome(){
    cout << "This program will analize a text document (context.txt) and will display it's amount of letters, words and sentences in another .txt output file" << endl;
}

int getWordNo (string text){
    int wordCounter = 0;
    for (int i=0; i < text.length(); i++){
        if (isalpha(text[i])){
            wordCounter++;
            if(wordCounter == 1){
                words++;
            }
        }
        else{
            wordCounter = 0;
        }
    }
    return words;
}

int getSentenceNo (string text){
    int letters = 0;
    for (int i=0; i <= text.length(); i++){
        if (isalpha(text[i])){
            letters++;
        }
        if ((letters > 0) && (text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ';' || text[i] == ':' )){
            sentences++;
            letters = 0;
        }
    }
    return sentences;
}

void arrayInitialize(int array[], const int size, const int initialValue){
        for (int i = 0; i < size-1; i++){
            array[i]=initialValue;
        }
}

int main(){
    welcome();
    arrayInitialize(numberOfLetters, 26, 0);
    string text; //declare the string to write it
    ifstream input("context.txt");  // Open the file
    if (input.is_open()){ // verify the file is open
        while(getline(input, text)){  // Get the strings
            getWordNo(text);
            getSentenceNo(text);
            int letterCounter = 0; // the counter of letters
            for (int i = 0; i < text.length(); i++){ //read the letters
                for (char lowerCase = 'a'; lowerCase <= 'z'; lowerCase++ ){ // reading characters in the text from a to z on lowercase
                    if (lowerCase==text[i]){ //
                    numberOfLetters[letterCounter]++; //
                    }
                letterCounter++; // This changes the index for the next letter
                }
            letterCounter=0; // reset the counter to 0 to go back to number of letters a
            }
            // SAME FOR CAPITAL LETTERS
            for (int i = 0; i < text.length(); i++){ //read the string
                for (char lowerCase = 'A'; lowerCase <= 'Z'; lowerCase++ ){ // reading characters in the text from a to z on lowercase
                    if (lowerCase==text[i]){
                        numberOfLetters[letterCounter]++;
                    }
                    letterCounter++; // This changes the index for the next letter
                }
                letterCounter=0; // reset the counter to 0 to go back to number of letters a
            }
            ofstream output ("lettersStatistics.txt");
            if(output.is_open()){
                output << sentences << " sentences " << endl << words << " " << "words " << endl;
                for(int i = 0; i < 25; i++){
                    output << numberOfLetters[i] << endl;
                }
                output.close();
            }
        }
    }
    input.close(); // Close the file!
    return 0;
}
