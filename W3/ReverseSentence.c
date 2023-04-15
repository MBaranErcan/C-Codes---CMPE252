#include <stdio.h>

void reverseSentence();

int main()
{
    printf("Enter the sentence you want to reverse: ");
    reverseSentence();

    return 0;
}

void reverseSentence(){
    char c;
    scanf("%c", &c);
    if (c != '\n'){
        reverseSentence();
        printf("%c", c);
    }
    
}
