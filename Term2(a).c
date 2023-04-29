#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[20];
    char pat[10];
    int pos = -1;

    printf("Enter string: \n");
    scanf("%s", str);
    printf("\nEnter pattern: ");
    scanf("%s", pat);
    pos = searchPattern(pat, str);
    if(pos == -1){
        printf("\nPattern not found\n");
    }
    else{
        printf("\nPattern found at index: %d\n", pos);
    }


    return 0;
}

int searchPattern(char* pat, char* str){
    int m = strlen(pat);
    int n = strlen(str);
    int i, j;

    for(i = 0; i <= n - m; i++){
        for(j = 0; j < m; j++){
            if(str[i + j] != pat[j]){
                break;
            }
        }
        if(j == m){
            return i;
        }
    }
    return -1;
}
