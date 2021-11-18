#include<stdio.h>
#define MAX 100
#define LET 26

int Strlen(char* string){
    
    int len = 0;
    while (*string != '\0'){
        len++;
        string++;
    }
    return len;    
}

void encode(char* string, int rot, char* outcome){
    
    int i;
    for (i = 0; i < (Strlen(string)-1); i++){
        // *(arrName+i) is same as arrName[i] //[The name of the array is the pointer to first element of the array]
        // arrName == &arrName[0] and *arrName == arrName[0] 
        // *(arrName) gives the value of the first element, so to retrieve all the values write *(arrName+i) and increment i
        // till i is lesser than length of the arrName-1 (possible for both array and string literal) 
        // or until *(arrName+i) 'or' arrName[i] is '\0'[NULL] character (this method is only for string literal)
        if((*(string+i) >=65 && *(string+i) <=90) && *(string+i)+rot >90){
            *(outcome+i) = (*(string+i)+rot)-LET;         
        } else if((*(string+i)>=97 && *(string+i)<=122) && *(string+i)+rot >122){
            *(outcome+i) = (*(string+i)+rot)-LET;
        } else
            *(outcome+i) = *(string+i)+rot;
    }
    *(outcome+i) = '\0';

}
void decode(char* string, int rot, char* outcome){

    int i;
    for (i = 0; i < (Strlen(string)-1); i++){

        if((*(string+i) >=65 && *(string+i) <=90) && *(string+i)-rot <65){
            *(outcome+i) = (*(string+i)-rot)+LET;          
        } else if((*(string+i) >=97 && *(string+i)<=122) && *(string+i)-rot<97){
            *(outcome+i) = (*(string+i)-rot)+LET;
        } else{
            *(outcome+i) = *(string+i)-rot;
        }        
    }
    *(outcome+i) = '\0';

}

int main(){

    char string[MAX];
    char outcome[MAX];
    char res;
    int rotate, mode;

    printf("Enter the string: ");
    fgets(string, MAX, stdin);

    printf("Enter 1 for encryption and 0 for decryption\n:");
    scanf("%d", &mode);

    
    if(mode){
        printf("How many letters do you want to rotate?(select between 1 - 25)\n:");
        scanf("%d", &rotate);
        encode(string, rotate, outcome);
        printf("%s\n", outcome);

    } else if(!mode){
        printf("do you want to specify the shift value or want the program to list every possible decrypted string?(press y to specify shift value/else n)\n:");
        
        scanf(" %c", &res);
        if(res == 'y'){
           printf("How many letters do you want to rotate?(select between 1 - 25)\n:");
           scanf("%d", &rotate);
           decode(string, rotate, outcome);
           printf("%s\n", outcome);
        }else
            for(int rot = 1; rot < 26; rot++){
                decode(string, rot, outcome);
                printf("%s\n", outcome);
            }        
    }
    return 0;
}
