#include<stdio.h>

typedef enum{
    TRUE,
    FALSE
}RES; 

int GET_BIT(int n, int i){
    return (n & (1 << (i -1))) ? 1 : 0; 
}

void print_bits(unsigned int n)
{    
    printf("print %d\n", n);
    while (n > 0)
    {
        if (n & 1)
            printf("1 ");
        else
            printf("0 ");
        n >>= 1;
    }
    printf("\n");
}

RES is_poli(unsigned int n){
    int r =  sizeof(unsigned int) * 8;
    int l = 1; 

    while(l < r){
        if(GET_BIT(n,l) != GET_BIT(n, r)){

            return FALSE; 
        }
        l++;
        r--;
    } 
    return TRUE; 
}

int main(){
    RES res = 0; 
    res = is_poli(199); 
    printf("is poli?: %d\n", res);
    print_bits(199); 

    res = is_poli(3758096391); 
    printf("is poli?: %d\n", res);
    print_bits(3758096391); 

    res = is_poli(4026531847); 
    printf("is poli?: %d\n", res);
    print_bits(4026531847); 
    return 0; 
}