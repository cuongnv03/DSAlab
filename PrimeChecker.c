#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

// Function to swap two characters in a string
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate all permutations of a string
void generatePermutations(char *str, int left, int right, int *result) {
    if (left == right) {
        int num = atoi(str);
        if (isPrime(num)) {
            *result = 1;
        }
    } else {
        for (int i = left; i <= right; i++) {
            swap(&str[left], &str[i]);
            generatePermutations(str, left + 1, right, result);
            swap(&str[left], &str[i]); // Backtrack
        }
    }
}

// Function to check if any permutation of num is prime
int PrimeChecker(int num) {
    char numStr[20]; // Assuming the maximum number of digits is 20
    sprintf(numStr, "%d", num); // Convert num to a string
    int result = 0;
    generatePermutations(numStr, 0, strlen(numStr) - 1, &result);
    return result;
}

int main() {
    int num;
    printf("Nhap so tu ban phim: ");
    scanf("%d", &num);
    int result = PrimeChecker(num);
    if (result == 1) {
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}

