#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "md5.h"

void print_hash(unsigned char *p){
	unsigned int;
    for(i = 0; i < 16; ++i){
        printf("%02x", p[i]);
    }
    printf("\n");
}

int main(){
    unsigned char result[16];
	int boolean_is_correct, i;

    char* tested_string = "A hundred suspicions don't make a proof."; // Crime and Punishment,  Fyodor Dostoevsky.
    unsigned char  expected_hash[16] = {0x89,0x58,0xf2,0xcf,0xcc,0x05,0xdb,0x49,0x4b,0x09,0xa5,0xdd,0xe0,0xcc,0x5d,0x3d};

    md5String(tested_string, result);

    boolean_is_correct = 1;
    for(i = 0; i < 16; i++) {
        if(expected_hash[i] != result[i]){
            boolean_is_correct = 0;
        }
    }

    if(boolean_is_correct){
        printf("O valor está correto.\n");
        return 0;
    }else{
        printf("O valor está INCORRETO!.\n");
        return -1;
    }
}