#include<stdio.h> 
#include<string.h> 

/* you should always check with your interviewer about the
size of the character set. We assumed that the character set was ASCII. */
int lut[128] = {0}; 

int print_lut(){
    for (int i =0; i < 128; i++){
        printf("index: %d value:%d \n",i, lut[i]); 
    }
    
    printf("\n "); 
}

int is_prmu(char* str1, char* str2){
    int str1_len = strlen(str1); 
    int str2_len = strlen(str2); 


    int i = 0; 
    
    for(i = 0; i < str1_len; i++){
        lut[str1[i]]++; 
    } 

    for(i=0; i < str2_len; i++){
        lut[str2[i]]--;
        if(lut[str2[i]] < 0){
            return 1; 
        } 
    }
    return 0; 
}


int main(){

    char* str1 = "abFcd"; 
    char* str2 = "cbaA"; 
    int ret = 0 ;
    ret = is_prmu(str1, str2); 

    printf("res: %d\n", ret); 

    //print_lut();
    return 0; 
}
