#include<stdio.h>
#include <string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 100
#define LET 26
#define UTL 32



int _strtoi(const char* str){ //changes number stored in a string to integer
   int res = 0;
   char *ptr = (char*)str;

   while (*ptr != '\0') {
      if (isdigit(*ptr)) {
         // Integer part
         res *= 10; // Shift the previous digits to the left
         res += *ptr - 48; // Add the new one

      }
      ptr++;
   }
   return res;
}

void encrypt(char* string, int rotValue){

	int i;
	char* outcome = (char*)calloc(1, strlen(string)+1);
        for (i = 0; i < strlen(string); i++){
            if((*(string+i) >=32 && *(string+i) <=64) || (*(string+i) >=91 && *(string+i) <=96) || (*(string+i) >=123 && *(string+i) <=126)){
                *(outcome+i) = *(string+i);
            }else if(toupper(*(string+i)) >=65 && toupper(*(string+i)) <=90){
                *(outcome+i) = (toupper(*(string+i))+rotValue);   
                if(*(outcome+i) > 90)
                    *(outcome+i) = *(outcome+i)-LET;
            }
            if(islower(*(string+i))){
                *(outcome+i) = *(outcome+i)+UTL;
            }
        }
        *(outcome+i) = '\0';

	puts(outcome);
	free(outcome);

}
void decrypt(char* string, int rotValue){
        
    int i;
    char* outcome = (char*)calloc(1, strlen(string)+1);
    for (i = 0; i < strlen(string); i++){
        if((*(string+i) >=32 && *(string+i) <=64) || (*(string+i) >=91 && *(string+i) <=96) || (*(string+i) >=123 && *(string+i) <=126)){
            *(outcome+i) = *(string+i);
        }else if((toupper(*(string+i)) >=65 && toupper(*(string+i)) <=90)){
            *(outcome+i) = (toupper(*(string+i))-rotValue);   
            if(*(outcome+i) < 65)
                 *(outcome+i) = *(outcome+i)+LET;       
        }
        if(islower(*(string+i))){
            *(outcome+i) = *(outcome+i)+UTL;
        }  
    }
    *(outcome+i) = '\0';
   
    puts(outcome);
    free(outcome);
}
void help(){
    
     fprintf(stdout, "Usage: rot -s <string> -m (enc|dec) -r <int>\
     \nOptions:-\n\n\t-s  set data string\
     \n\t-m  set mode to encrypt or decrypt the message\
     \n\t-r  set rotate value [-1 to print all possibilities]\n");
}

int arg_validate(char* arg){
    if(arg == NULL || 
        !strcmp(arg, "-s") ||
        !strcmp(arg, "-m") ||
        !strcmp(arg, "-r")){
            return -1;
        }
    return 0;
}

int main(int argc, char*argv[]){
    
    int stridx, modidx, rotidx, i;
    if(argc == 1 || (argc == 2 && !strcmp(argv[1], "-h"))){
	help();
    }else if(argc == 7){
	
        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], "-s")){

                if(arg_validate(argv[i+1]) == -1){
                    fprintf(stderr, "DataError: something went wrong.");
		    exit(1);
                } else {
                    stridx = i+1;
                }
                break;
            } else{
                continue;
            }
        }
        
        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], "-m")){

                if(strcmp(argv[i+1], "enc") && strcmp(argv[i+1], "dec")){
                    fprintf(stderr, "DataError: something went wrong.");
		    exit(1);
                } else {
                    modidx = i+1;
                }
                break;
            } else{
                continue;
            }
        }
        for(i = 0; i < argc; i++){
            if(!strcmp(argv[i], "-r")){

                if(arg_validate(argv[i+1]) == -1){
                    fprintf(stderr, "ValueError: invalid rotate value.");
		    exit(1);
                } else {
                    rotidx = i+1;
                }
                break;
            } else{
                continue;
            }
        }
		
    	int rotValue;
    	if(strcmp(argv[rotidx], "-1")){
            int d = _strtoi(argv[rotidx]);
	    if(d >= 0 && d < LET) 
                rotValue = d;
	    else exit(1);
        }
        
	if(!strcmp(argv[modidx], "enc")){
	    if(!strcmp(argv[rotidx], "-1")){
                for(rotValue = 1; rotValue < 26; rotValue++){
                    encrypt(argv[stridx], rotValue);
                } 
            }else encrypt(argv[stridx], rotValue);

	} else if(!strcmp(argv[modidx], "dec")){
	    if(!strcmp(argv[rotidx], "-1")){
                for(rotValue = 1; rotValue < 26; rotValue++){
                    decrypt(argv[stridx], rotValue);
                } 
            }else decrypt(argv[stridx], rotValue);
	    
	}

    } else{
     	fprintf(stdout, "Usage: %s -s <string> -m (enc|dec) -r <int>\
        \nFor more, check help section:\
        \n    %s -h", argv[0], argv[0]);
        return 1;
    }

    return 0;
}