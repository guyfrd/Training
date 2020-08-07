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

//cracking the code interview 5.3 Flip Bit to Win
int long_set_bits(unsigned int n){
    
    int max_seq = 1; 
    int curr_seq = 0; 
    int prev_seq =0; 

    if (~n == 0){
        return sizeof(unsigned int) * 8; 
    }

    while(n > 0){
        if(n & 1){
            curr_seq++;
        } else { /* Update to a (if next bit is a) or currentLength (if next bit is 1). */
            if ((n & 2) == 0) { 
                prev_seq = 0; 
            } else {
                prev_seq = curr_seq; //continue counting
            }
                if ((prev_seq+curr_seq) > max_seq){
                    max_seq = prev_seq + curr_seq; 
                } 
            curr_seq = 0; 
        }
        n >>= 1;
    }      
    return max_seq; 
}

int main(){
    RES res = 0; 
    int num; 
    print_bits(5687);
    num = long_set_bits(5687);
    printf("num %d\n", num);

    return 0; 
}