#include<stdio.h>
#include<stdint.h>

#define MAX 51
#define RANGE (MAX-1)

char Pull(int x,int y);

uint32_t secret [MAX]={
    2721155218,
    2770945298,
    3878240786,
    2771485184,
    2770403858,
    3341928960,
    2720565760,
    3257961984,
    2721090048,
    3341322752,
    3257008128,
    2769560648,
    2802341032,
    2768783504,
    3305635840,
    3258040320,
    2770927616,
    3341926400,
    2770927616,
    3308371968,
    524342,
    8257609,
    31588417,
    50397218,
    241270804,
    941645832,
    1613770752,
    1081609216,
    3228829184,
    4166255360,
    1312293344,
    1136656432,
    1077903368,
    1879310328,
    2113929224,
    1643118600,
    2132787208,
    568393720,
    538951804,
    536935946,
    2080376827,
    2273312777,
    2155741193,
    2148003849,
    3221233418,
    1073742836,
    536870924,
    402653208,
    234881120,
    62916480,
    8386560
};

char Pull(int x,int y){
    char color = (secret[y]&(1<<(31-x)))>>((31-x));
    return color;
}

int main(){
    char color = 0;
    for (char i=0; i<MAX; i++){
        for(char j=0; j<32; j++){
            color = Pull(j,i);
            if(color== 1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        if((i+1)%5==0 && i<22){
            printf("\n");
        }
        printf("\n");
    }
}