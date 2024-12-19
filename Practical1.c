#include<stdio.h>
#include<conio.h>

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);
    for (int i = 0; i < strlen(str)-2; i++){
        if(str[i] != 'a'){
            printf("Invalid String");
            return 0;
        }
    }
    
    if(str[strlen(str)-2] == 'b' && str[strlen(str)-1] == 'b'){
        printf("Valid String");
    }else{
        printf("Invalid String");
    }

    return 0;
}
