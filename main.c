#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "crypto.h"

int main ()
{

int k;
int l;
char f[500];
char result[500];
printf("Type your text:");
fgets(f, 500, stdin);
printf("Choose:\n1 - encoding\n2 - decoding\n");
scanf("%i", &l);




if(l == 1) {
    
    printf("Choose type of encoding:\n1 - reverse\n2 - vigenère cipher\n3 - bit chaos\n");
    scanf("%i", &k);
    if(k == 1) {

        reverse(f, result);
        printf("%s", result);
    } 
    if(k == 2) {
        

        char key[100];
        printf("Type your key word:");
        char c;
        scanf("%c", &c);
        if(k != 5){
         fgets(key, 100, stdin);
        }
        
        vigenere_encrypt(key, f, result);
        printf("%s", result);
    } 

    
    if(k == 3) {
       bit_encrypt(f, result);
        for(int i = 0; i < strlen(f); i++) {
            printf("%02x", (unsigned char)result[i]);

        }
        printf("%s", result);
    }
    } else {printf("Please, choose an existing option");}
    

//
if(l == 2) {
   printf("Choose type of decoding:\n1 - reverse\n2 - vigenère cipher\n3 - bit chaos\n"); 
    scanf("%i", &k);
    

if(k == 1) {
    reverse(f, result);
    printf("%s\n", result);
    }

if(k == 2) {
     char key[100];
        printf("Type your key word:");
        char c;
        scanf("%c", &c);
        if(k != 5){
         fgets(key, 100, stdin);
        }
        vigenere_decrypt(key, f, result);
        printf("%s\n", result);
    }


if(k == 3) {
    
    bit_decrypt(f, result);
    printf("%s\n", result);
    }
    
}



// //1	
// bool bits1[8];
// encode_char('A', bits1);
// for(int i = 0; i < 8; i++){
//     printf("%d", bits1[i]);
// }
// printf("\n");

// //2
// bool bits2[8] = {0,1,0,0,0,0,0,1};
// printf("%c\n", decode_char(bits2));

// //3
// char* text = "Hello, how are you?";
// const int len = strlen(text);
// bool bytes1[len+1][8];
// encode_string(text, bytes1);
// for(int j = 0; j <= len; j++){
//     printf("%c: ", text[j]);
//     for(int i = 0; i < 8; i++){
//         printf("%d", bytes1[j][i]);
//     }
//     printf("\n");
// }

// //4
// bool bytes2[7][8] = {
//     {0,1,0,0,1,0,0,0},
//     {0,1,1,0,0,1,0,1},
//     {0,1,1,0,1,1,0,0},
//     {0,1,1,0,1,1,0,0},
//     {0,1,1,0,1,1,1,1},
//     {0,0,1,0,0,0,0,1},
//     {0,0,0,0,0,0,0,0}
// };
// char string[7];
// decode_string(7, bytes2, string);
// printf("%s\n", string);

// //5
// char reversed[255];
// reverse("Hello world!", reversed);
// printf("%s\n", reversed);

// //6
// char encrypted[255];
// char decrypted[255];

// // basic test with long text
// vigenere_encrypt("CoMPuTeR", "Hello world!", encrypted);
// printf("%s\n", encrypted);

// //7
// vigenere_decrypt("CoMPuTeR", encrypted, decrypted);
// printf("%s\n", decrypted);


	

// //8

// char encrypted1[100];

// // basic test with long text
// bit_encrypt("Hello world!", encrypted1);
// for(int i = 0; i < 12; i++) {
//     printf("%02x \n", (unsigned char)encrypted1[i]);
//     //80 9c 95 95 96 11 bc 96 b9 95 9d 10
// }

// //9

// char decrypted1[100];
// bit_decrypt(encrypted1, decrypted1);
// printf("%s\n", decrypted1);


return 0;
}