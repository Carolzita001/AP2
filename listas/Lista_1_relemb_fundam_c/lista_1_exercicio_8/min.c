#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int is_palindrome(char *str) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        if (tolower(str[start]) != tolower(str[end])) {
            return 0; // not a palindrome
        }
        start++;
        end--;
    }

    return 1; // is a palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // remove the newline character at the end of the string
    str[strcspn(str, "\n")] = 0;

    if (is_palindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}