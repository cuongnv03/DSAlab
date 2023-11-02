#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    int dem1[26] = {0}, dem2[26] = {0}, i, commonchars = 0;
    

    printf("Chuoi 1: ");
    scanf("%s", str1);

    printf("Chuoi 2: ");
    scanf("%s", str2);

	 for (i = 0; i < strlen(str1); i++) {
        dem1[str1[i] - 'a']++;
    }

	for (i = 0; i < strlen(str2); i++) {
        dem2[str2[i] - 'a']++;
    }

	 for (i = 0; i < 26; i++) {
        commonchars += (dem1[i] < dem2[i]) ? dem1[i] : dem2[i];
    }

    printf("So ky tu chung la: %d\n", commonchars);

    return 0;
}