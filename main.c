#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "crypto.h"

int main ()
{

//1	
bool bits1[8];
encode_char('A', bits1);
for(int i = 0; i < 8; i++){
    printf("%d", bits1[i]);
}
printf("\n");

//2
bool bits2[8] = {0,1,0,0,0,0,0,1};
printf("%c\n", decode_char(bits2));

//3
char* text = "Hello, how are you?";
const int len = strlen(text);
bool bytes1[len+1][8];
encode_string(text, bytes1);
for(int j = 0; j <= len; j++){
    printf("%c: ", text[j]);
    for(int i = 0; i < 8; i++){
        printf("%d", bytes1[j][i]);
    }
    printf("\n");
}

//4
bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
};
char string[7];
decode_string(7, bytes2, string);
printf("%s\n", string);

//5
char reversed[255];
reverse("Hello world!", reversed);
printf("%s\n", reversed);

//6
char encrypted[255];
char decrypted[255];

// basic test with long text
vigenere_encrypt("CoMPuTeR", "Hello world!", encrypted);
printf("%s\n", encrypted);

//7
vigenere_decrypt("CoMPuTeR", encrypted, decrypted);
printf("%s\n", decrypted);


	

//8

char encrypted1[100];

// basic test with long text
bit_encrypt("Hello world!", encrypted1);
for(int i = 0; i < 12; i++) {
    printf("%02x \n", (unsigned char)encrypted1[i]);
    //80 9c 95 95 96 11 bc 96 b9 95 9d 10
}

//9

char decrypted1[100];
bit_decrypt(encrypted1, decrypted1);
printf("%s\n", decrypted1);


return 0;
}