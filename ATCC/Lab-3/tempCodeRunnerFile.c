#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *str) {
    char *keywords[] = {
        "int","float","char","double","long","short","unsigned","signed",
        "for","while","do","if","else","switch","case","break","continue",
        "return","void","static","struct","sizeof"
    };
    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *f1, *f2;
    f1 = fopen("input.txt", "r");
    if (f1 == NULL) {
        printf("File not found");
        return 0;
    }

    f2 = fopen("output.txt", "w");

    char c;
    char token[100];
    int i = 0;

    while ((c = fgetc(f1)) != EOF) {

        if (isalpha(c) || c == '_') {     // start of identifier/keyword
            token[i++] = c;

            while ((c = fgetc(f1)) != EOF && (isalnum(c) || c == '_')) {
                token[i++] = c;
            }

            token[i] = '\0';
            i = 0;

            if (isKeyword(token)) {
                fprintf(f2, "<KEYWORD , %s>\n", token);
            } else {
                fprintf(f2, "<IDENTIFIER , %s>\n", token);
            }

            if (c != EOF)
                ungetc(c, f1);   // go one char back
        }
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
