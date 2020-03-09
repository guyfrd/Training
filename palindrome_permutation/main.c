#include<stdio.h> 
#include<string.h> 

/* you should always check with your interviewer about the
size of the character set. We assumed that the character set was ASCII. */
int lut[128] = {0}; 
int lut2[128] = {0}; 

typedef enum {
    TRUE,
    FALSE
}RES;

RES is_poli_permu(char* str){

    size_t str_len = strlen(str); 
    int odd = 0; 
    int i = 0; 

    for(i =0; i < str_len; i++){
        if(str[i] == ' '){
            continue; 
        }
        lut[str[i]]++; 
    }

    for (i=0; i < 128; i++)
    {
        if((lut[i] % 2) != 0 ) {
            if(odd != 0){
                return 1;
            } 
            odd = FALSE;
        }
    }
    return TRUE; 
}

int is_poli_permu_opt(char* str){
    int count_odd = 0; 
    size_t str_len = strlen(str); 

     for(int i =0; i < str_len; i++){
        if(str[i] == ' '){
            continue; 
        }
        lut2[str[i]]++; 
        if( (lut2[str[i]] % 2) == 1){
            count_odd++; 
        }  else {
            count_odd--;
        }
    }
    if(count_odd <=1){
        return TRUE; 
    }else{
        return FALSE;
    }
     
}

int main(){

    char * str = "tsaco catsoaaa"; 
    int res = 0; 
    int res2 = 0; 

    res = is_poli_permu(str);
    printf("res: %d\n", res);

    res2 = is_poli_permu_opt(str);
    printf("res opt: %d\n", res2);
    
    return 0; 
}