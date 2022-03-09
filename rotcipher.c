#include<stdio.h>
#define MAX 100
#define LET 26
#define UTL 32

int Strlen(const char* string){
    
    int len = 0;
    while (*string != '\0'){
        len++;
        string++;
    }
    return len;    
}

int Strcmp(const char* string1, const char* string2){

   int len_string1 = Strlen(string1);
   int len_string2 = Strlen(string2);

   if((len_string1 - len_string2) == 0){
      for(int i = 0; i < len_string1; i++){
         if(*(string1+i) == *(string2+i))
            len_string2--;         
      }
      if(len_string2 == 0)
         return 0;
      else
         return 1;
   } else{
      return 1;
      }
}

int isDigit(int ch){
   if(ch >= 48 && ch <= 57)
      return 1;
   return 0;
}

int AtoI(const char* str){ //changes number stored in a string to integer
   int res = 0;
   char *ptr = (char*)str;

   while (*ptr != '\0') {
      if (isDigit(*ptr)) {
         // Integer part
         res *= 10; // Shift the previous digits to the left
         res += *ptr - 48; // Add the new one

      }
      ptr++;
   }
   return res;
}

int toUpper(int ch){

   int upper;
   if(ch >= 97 && ch <= 122){
      upper = ch-32;
   } else {
      upper = ch;
   }
   return upper;
}

int isLower(int ch){
   if(ch >= 97 && ch <= 122)
      return 1;
   return 0 ;
}

void Rot(char* string, char* mode, char* rotval){

    auto void encode();
    auto void decode();

    int rotValue;
    char outcome[MAX], rotstr[5];
    if(Strcmp(rotval, "--allpos")){
        rotstr[0] = rotval[5];
        rotstr[1] = rotval[6];
        rotValue = AtoI(rotstr);
    }
    if(Strcmp(mode, "--encrypt") == 0){
        if(!Strcmp(rotval, "--allpos")){
            for(rotValue = 1; rotValue < 26; rotValue++){
                encode();
                printf("%s\n", outcome);
            } 
        }else{
            encode();
            printf("%s\n", outcome);
        }
    } else if(Strcmp(mode, "--decrypt") == 0){
        if(!Strcmp(rotval, "--allpos")){
            for(rotValue = 1; rotValue < 26; rotValue++){
                decode();
                printf("%s\n", outcome);
            } 
        }else{
            decode();
            printf("%s\n", outcome);
        }
    }
    void encode(){
        
        int i;
        for (i = 0; i < Strlen(string); i++){
            // *(arrName+i) is same as arrName[i] //[The name of the array is the pointer to first element of the array]
            // arrName == &arrName[0] and *arrName == arrName[0] 
            // *(arrName) gives the value of the first element, so to retrieve all the values write *(arrName+i) and increment i
            // till i is lesser than length of the arrName-1 (possible for both array and string literal) 
            // or until *(arrName+i) 'or' arrName[i] is '\0'[NULL] character (this method is only for string literal)
            if((*(string+i) >=32 && *(string+i) <=64) || (*(string+i) >=91 && *(string+i) <=96) || (*(string+i) >=123 && *(string+i) <=126)){
                *(outcome+i) = *(string+i);
            }else if(toUpper(*(string+i)) >=65 && toUpper(*(string+i)) <=90){
                *(outcome+i) = (toUpper(*(string+i))+rotValue);   
                if(*(outcome+i) > 90)
                    *(outcome+i) = *(outcome+i)-LET;
            }
            if(isLower(*(string+i))){
                *(outcome+i) = *(outcome+i)+UTL;
            }
        }
        *(outcome+i) = '\0';

    }
    void decode(){

        int i;
        for (i = 0; i < Strlen(string); i++){
            if((*(string+i) >=32 && *(string+i) <=64) || (*(string+i) >=91 && *(string+i) <=96) || (*(string+i) >=123 && *(string+i) <=126)){
                *(outcome+i) = *(string+i);
            }else if((toUpper(*(string+i)) >=65 && toUpper(*(string+i)) <=90)){
                *(outcome+i) = (toUpper(*(string+i))-rotValue);   
                if(*(outcome+i) < 65)
                    *(outcome+i) = *(outcome+i)+LET;       
            }
            if(isLower(*(string+i))){
                *(outcome+i) = *(outcome+i)+UTL;
            }  
        }
        *(outcome+i) = '\0';
    }
}

int main(int argc, char*argv[]){
    
    if(argc == 2 && (Strcmp(argv[1], "--help")||Strcmp(argv[1], "-h"))){
        fprintf(stdout, "\nUsage: %s <string> --<mode> --<rotval>\n|CLI options|:-\
        \n\t<data> = A plaintext or ciphertext.\
        \n\t<mode>:\n\t\t--encrypt = Encrypts the string\n\t\t--decrypt = Decrypts the string\
        \n\t<rotval>:\n\t\t--rot<int> = Rotates according to given value.|<int> should be between 1-25|\
        \n\t\t--allpos = prints all possibilities by rotating the values between 1-25.\n", argv[0]);
    }else if(argc == 4){
        Rot(argv[1], argv[2], argv[3]);
    } else{
        fprintf(stderr, "\nUsage: %s <string> --<mode> --<rotval>\
        \nFor more, check help section:\
        \n    %s --help 'or' -h", argv[0], argv[0]);
        return 1;
    }

    return 0;
}
