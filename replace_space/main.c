#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

void replace_space(char* str){
    size_t str_len = strlen(str);
    size_t tail_len = 0; 
    char* tmp_str = malloc(str_len); 
    char* tail = NULL;
    char * run_ptr = str + str_len-1; 

    //start from the end of the string
    while (run_ptr > str)
    {
        //TODO just spaces string 
        //run till the you find space
        while(*(run_ptr) != ' '){
            if(run_ptr == str){
                *(run_ptr + tail_len + 1) ='\0'; 
                return; 
            }
            run_ptr--;
            tail_len++;  
        }
        tail = run_ptr; 
        strncpy(tmp_str ,tail +1, tail_len); 

        run_ptr--;

        while(*(run_ptr) == ' '){
            run_ptr--;
        }
        strncpy(run_ptr + 1, "%20", 3); 
        strncpy(run_ptr + 4, tmp_str, tail_len); 
        tail_len += 3; 
        //else if the first char is not space
            //run to end word(mean find space/end of string)
            //tail is now the start of the last word
            //copy the tail to temp
        //run to the last space in squence
        //earse space withe %20
        //tail now assigin to % char
        //update tail size
    
    }
}


int main(){
    char *str = malloc(32); //assumption i have space for extre chars if needed 
    strcpy(str, "Mr    3ohn     Smith  ");
    

    replace_space(str); 
    printf("the result: %s\n", str); 
    printf("the result: %d\n", strcmp(str, "Mr%203ohn%20Smith%02")); 

    return 0; 
}