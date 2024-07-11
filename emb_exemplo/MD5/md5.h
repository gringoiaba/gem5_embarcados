#ifndef MD5_H
#define MD5_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    unsigned long long size;    // Size of input in bytes
    unsigned int buffer[4];     // Current accumulation of hash
    unsigned char input[64];    // Input to be used in the next step
    unsigned char digest[16];   // Result of algorithm
} MD5Context;

void md5Init(MD5Context *ctx);
void md5Update(MD5Context *ctx, unsigned char *input, size_t input_len);
void md5Finalize(MD5Context *ctx);
void md5Step(unsigned int *buffer, unsigned int *input);

void md5String(char *input, unsigned char *result);

#endif