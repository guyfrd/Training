#include<stdio.h>

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



//cracking the code interview 5.1 
int merge_bits( int m,  int n, int i, int j){

    int mask_r = (1 << i) -1; 
    int mask_l = (-1 << (j+ 1)); 

    int mask = mask_l | mask_r ;  

    return (n & mask) | (m << i); 

}

int main(){
    int res = 0; 
    res = merge_bits(19, 1024, 2, 6); 
    print_bits(res); 
    return 0; 
}