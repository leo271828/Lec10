#include<stdio.h>

void addition();

void print_binary(void *n){
    for(int i = 31; i >= 0; --i){
        printf("%d", (*(int *)n >> i) & 1);
        if (i && !(i % 8)) printf(" ");
    }
}

int main(){
    addition();
    return 0;
}

void addition(){
    float a, b;
    scanf("%f %f", &a, &b);
    float sum = a + b;
    printf("   ");
    print_binary(&a);
    printf("\n+) ");
    print_binary(&b);
    printf("\n---------------------------------------\n");
    printf("   ");
    int total = *(int *)&a + *(int *)&b; // It is magic
    print_binary(&total);
    printf("\n%d + %d = %d", (int)a, (int)b, total);
}
