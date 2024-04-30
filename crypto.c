#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


//1
void encode_char(const char unsigned character, bool bits[8]) {
    int bit_values[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int charValue = (int)character;
    for(int i = 0; i < 8; i++) {
        bits[i] = 0;
        if(bit_values[i] <= charValue) {
            bits[i] = 1;
            charValue -= bit_values[i];
        }
    }
}

//2
char decode_char(const bool bits[8]) {
    int bit_values[8] = {128, 64, 32, 16, 8, 4, 2, 1};
    int charValue = 0;

    for (int i = 0; i < 8; i++) {
        if(bits[i] == 1) {
            charValue += bit_values[i];
        }
        
    }     
return (unsigned char)charValue;
}

//3
void encode_string(const char string[], bool bytes[][8]) {
    bool bits[8];    
    
        for(int i = 0; i < strlen(string) + 1; i++){            
            encode_char(string[i], bits);
            for (int k = 0; k < 8; k++) {
                bytes[i][k] = bits[k];   
             }
             
        }
    
}

//4
void decode_string(const int rows, bool bytes[][8], char string[]){

bool bits[8];

for(int i = 0; i < rows; i++){
    for(int j = 0; j < 8; j++){
        bits[j] = bytes[i][j];
    }
    string[i] = decode_char(bits);
}

}

//5
void reverse(const char* text, char* result) {
    int n = strlen(text);
    for(int i = 0; i < strlen(text); i++) {
    
        result[i] = text[n - 1]; 
         n--;
    }

    for(int i = 0; i < strlen(text); i++) {
        if(result[i] >= 'a' && result[i] <= 'z') {
            result[i] = (int)result[i] - 32;
        }
    }
}

//6

void vigenere_encrypt(const char* key, const char* text, char* result) {
    int textLength = strlen(text);
    int keyLength = strlen(key); // 6
    // Hello world! => Helloworld
    for (int i = 0, j = 0; i < textLength; i++, j++) {
        if (j >= keyLength) {
            j = 0;
        }
        char textSymbol = text[i];
        if (textSymbol >= 97 && textSymbol <= 122) {
            textSymbol -= 32; // to uppercase
        }
        // is not a letter
        if (!(textSymbol >= 65 && textSymbol <= 90)) {
            j--;
            result[i] = textSymbol;
            continue;
        }
        char keySymbol = key[j];
        if (keySymbol >= 97 && keySymbol <= 122) {
            keySymbol -= 32; // to uppercase
        }
        int shift = (int)keySymbol - 65; // 2
        char tmp = textSymbol + shift; // 88 (X) + 10
        if (tmp > 90) {
            tmp -= 26; // 
        }
        result[i] = tmp;
    }
}

//7

void vigenere_decrypt(const char* key, const char* text, char* result){
    
    int textLength = strlen(text);
    int keyLength = strlen(key);
    int shift;
    
    for(int i = 0, j = 0; i < textLength; i++, j++) {
       if (j >= keyLength) {
            j = 0;
       }

       shift = 0;
       char keySymbol = key[j];
        if(key[j] >= 97 && key[j] <= 122) {
             keySymbol -= 32;
        }

    char textSymbol = text[i];

    if (textSymbol >= 97 && textSymbol <= 122) {
            textSymbol -= 32;
        }

    if (!(textSymbol >= 65 && textSymbol <= 90)) {
            j--;
            result[i] = textSymbol;
            continue;
    }
        shift = (int)keySymbol - 65;

        

        char tmp = text[i] - shift;
        if (tmp < 65) {
            tmp += 26;  
        }

        result[i] = tmp;

        

    }
    
}

//8
void bit_encrypt(const char* text, char* result){
   
   bool bitss[8];
   
   for(int i = 0; i < strlen(text); i++) {
    encode_char(text[i], bitss);
    for(int j = 0; j < 4; j += 2) {
        int save = bitss[j];
        bitss[j] = bitss[1 + j];
        bitss[j + 1] = save;
    }
    for(int k = 4; k < 8; k++){
        if(bitss[k - 4] == bitss[k]) {
            bitss[k] = 0;
        } else { bitss[k] = 1; }
    }
     result[i] = decode_char(bitss);
   }
  
    
}

//9
    
    void bit_decrypt(const char unsigned* text, char unsigned* result) {
        bool bits[8];
        int c = 0;
        for(int i = 0; i < 1000; i++) {
        if (text[i] != '\0') {
            c++;
        } else {
            break;
        }
    }
        for(int i = 0; i < c; i++){
            encode_char(text[i], bits);
            for(int k = 4; k < 8; k++){
                if(bits[k - 4] == bits[k]) {
                bits[k] = 0;
            } else { bits[k] = 1; }
            }
            for(int j = 0; j < 4; j += 2) {
             int save = bits[j];
             bits[j] = bits[1 + j];
             bits[j + 1] = save;
        }
        result[i] = decode_char(bits);
    }
    }