#include<stdio.h>
#include<string.h>

int main(){
    int store[7], len, sum = 0; 
    // B W T G M sugar, ice
    // 0 1 2 3 4 5      6
    for(int i=0;i<7;i++){
        int temp;
        scanf("%d", &temp);
        store[i] = 1000*temp;
    }
    scanf("%d", &len);
    for(int i=0;i<len;i++){
        char tea[500];
        int ice, sugar;
        scanf("%s", tea);
        scanf("%d/%d", &sugar, &ice);
        if ( !strcmp(tea, "B") ){
            sum += 20;
            store[0] -= 500;
        }else if ( !strcmp(tea, "W") ){
            sum += 15;
            store[1] -= 500;
        }else if ( !strcmp(tea, "T") ){
            sum += 30;
            store[2] -= 500;
        }else if ( !strcmp(tea, "G") ){
            sum += 20;
            store[3] -= 500;
        }else if ( !strcmp(tea, "GT") ){
            sum += 45;
            store[3] -= 250;
            store[2] -= 250;
        }else if ( !strcmp(tea, "WT") ){
            sum += 40;
            store[1] -= 150;
            store[2] -= 350;
        }else if ( !strcmp(tea, "BM") ){
            sum += 35;
            store[0] -= 200;
            store[4] -= 300;
        }else if ( !strcmp(tea, "TM") ){
            sum += 45;
            store[2] -= 200;
            store[4] -= 300;
        }else if ( !strcmp(tea, "WM") ){
            sum += 30;
            store[1] -= 200;
            store[4] -= 300;
        }
        if(sugar == 5)
            store[5] -= 10;
        else if (1 < sugar && sugar < 5)
            store[5] -= (2*sugar-1);
        if(ice == 5)
            store[6] -= 100;
        else if (1 < ice && ice < 5)
            store[6] -= (20*ice-10);
    }
    for(int i=0;i<7;i++)
        printf("%d ", store[i]);
    printf("\n%d", sum);
    return 0;
}
