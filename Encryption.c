// 來自嗡嗡
#include <stdio.h>
#define N 64

void swap(char a[],int s,int e);
void rotate(char a[],char direction,int step,int s,int e);
void rail_fence_cipher(char a[],int key[],int s,int e,int lengh);
void caeser_cipher(char a[],int k,int s,int e);
void trithemius_cipher(char a[],int k,int direction,int s,int e);
void vigenere_cipher(char a[],char key[],int lengh,int s,int e);


void first(char a[]);
void second(char a[]);
void third(char a[]);
void forth(char a[]);
void fifth(char a[]);

int main() {
    char old[N];
    int type;
    scanf("%d",&type);
    for(int i = 0 ; i < N ; i++){
        scanf("%c",&old[i]);
        if(old[i]=='\n')i--;
    }

    if(type==1) first(old);
    if(type==2) second(old);
    if(type==3) third(old);
    if(type==4) forth(old);
    if(type==5) fifth(old);

    for (int i = 0; i < N; i++){
        printf("%c",old[i]);
    }
    return 0;
}

void swap(char a[],int s,int e){
    char temp[N] = {0};
    for (int i = s; i < e/2; i++){
        temp[i]=a[i];
    }
    for (int i = s; i < e/2; i++){
        a[i]=a[i+e/2];
        a[i+e/2]=temp[i];
    }
}

void rotate(char a[],char direction,int step,int s,int e){
    char temp[1000];
    if(direction == 'l')
    {
        for(int i = s; i < e; i++){
            if(i+step < e) {
                temp[i] = a[i + step];
            }
            else {
                temp[i] = a[i + step - e + s];
            }
        }
    }
    else if(direction == 'r')
    {
        for(int i = s; i < e; i++){
            if(i-step >= s){
                temp[i] = a[i-step];
            }
            else {
                temp[i] = a[i-step-s+e];
            }
        }
    }
    for(int i = s; i < e; i++){
        a[i]=temp[i];
    }
}

void rail_fence_cipher(char a[],int key[],int s,int e,int lengh) {
    char temp[1000];
    char tempch[lengh];
    int temps=s;
    while(s+lengh <= e)
    {
        for (int i = 0; i < lengh; i++) {
            tempch[i]=a[s+i];
        }

        for (int i = 0; i < lengh; i++) {
            temp[s+key[i]-1]=tempch[i];
        }
        s += lengh;
    }
    while(e-s>0)
    {
        temp[s]=a[s];
        s++;
    }
    s=temps;

    for (int i = s; i < e; i++) {
        a[i] = temp[i];
    }
    printf("str : %s \n", a);
}

void caeser_cipher(char a[],int k,int s,int e){
    int temp[1000] ;
    for (int i = s; i < e; i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z')
        {
            temp[i] = a[i]+k%26;
            if (temp[i] < 'a'){
                temp[i] = 'z'-('a' - temp[i] - 1);
            }
            if (temp[i] > 'z'){
                temp[i] = temp[i]-'z'-1+'a';
            }
        }
        else if(a[i] >= 'A' && a[i] <= 'Z')
        {
            temp[i] = a[i]+k%26;
            if (temp[i] < 'A'){
                temp[i] = 'Z'-('A' - temp[i] - 1 );
            }
            if (temp[i] > 'Z'){
                temp[i] = temp[i]-'Z'-1+'A';
            }
        }else{
            temp[i] = a[i];
        }
    }
    for(int i = s ; i < e ; i++){
        a[i] = temp[i];
    }
}

void trithemius_cipher(char a[],int k,int direction,int s,int e)
{
    int alpha_count=0,temp[1000];
    for (int i = s; i < e; i++)
    {
        if(a[i] >= 'a'&& a[i] <= 'z')
        {
            int change=k+alpha_count*direction;
            change=change%26;
            temp[i] = a[i]+change;
            if (temp[i] < 'a'){
                temp[i] = 'z'-('a' - temp[i] - 1);
            }
            if (temp[i] > 'z') {
                temp[i] = temp[i]-'z'-1+'a';
            }
            alpha_count++;
        }
        else if(a[i] >= 'A'&&a[i] <= 'Z')
        {
            int change=k+alpha_count*direction;
            change=change%26;
            temp[i] = a[i]+change;
            if (temp[i] < 'A') {
                temp[i] = 'Z'-('A' - temp[i] - 1);
            }
            if (temp[i] > 'Z') {
                temp[i] = temp[i] -'Z'-1+'A';
            }
            alpha_count++;
        }else{
            temp[i] = a[i];
        }
    }
    for(int i = s ; i < e ; i++){
        a[i] = temp[i];
    }
}

void vigenere_cipher(char a[],char key[],int lengh,int s,int e)
{
    int ch[lengh],temp[1000];
    for (int i = 0; i < lengh; i++) {
        ch[i]=key[i]-65;
    }
    int alpha_count=0;
    for (int i = s; i < e; i++) {
        if(a[i]>='a'&&a[i]<='z') {
            int change = ch[alpha_count%lengh]-32;
            temp[i] = a[i]+change;
            if (temp[i] < 'a') {
                temp[i] = 'z'-('a' - temp[i] - 1);
            }
            if (temp[i] > 'z') {
                temp[i] = temp[i] -'z'-1+'a';
            }
            alpha_count++;
        }
        else if(a[i]>='A'&&a[i]<='Z')
        {
            int change=ch[alpha_count%lengh]-32;
            temp[i] = a[i]+change;
            if (temp[i] < 'A') {
                temp[i] = 'Z'-('A' - temp[i] - 1 );
            }
            if (temp[i] > 'Z') {
                temp[i] = temp[i]-'Z'-1+'A';
            }
            alpha_count++;
        }
        else{
            temp[i] = a[i];
        }
    }
    for(int i = s ; i < e ; i++){
        a[i] = temp[i];
    }
}

void first(char a[])
{
    swap(a,0,64);
    caeser_cipher(a,13,0,32);
    char key[4]={'m','e','o','w'};
    vigenere_cipher(a,key,4,32,64);
    rotate(a,'l',3,0,64);
}

void second(char a[])
{
    rotate(a,'r',11,0,64);


    trithemius_cipher(a,74,1,0,64);

    rotate(a,'r',1,0,32);


    rotate(a,'r',3,32,64);

    int key[8]={4,3,1,2,7,6,5,8};
    rail_fence_cipher(a,key,0,64,8);
}

void third(char a[])
{

    int key1[4]={3,2,4,1};
    rail_fence_cipher(a,key1,0,64,4);


    caeser_cipher(a,8,0,32);

    int key2[8]={1,8,4,3,6,5,7,2};
    rail_fence_cipher(a,key2,32,64,8);

    swap(a,0,64);

    trithemius_cipher(a,602,-1,0,64);

    rotate(a,'r',7,0,64);

}

void forth(char a[])
{
    char key1[8]={'v','i','g','e','n','e','r','e'};
    vigenere_cipher(a,key1,8,0,32);
    swap(a,0,32);
    trithemius_cipher(a,3,1,0,32);
    rotate(a,'l',24,32,64);
    rotate(a,'r',19,0,64);
}

void fifth(char a[])
{
    int key1[8]={3,1,7,6,4,5,2,8};
    rail_fence_cipher(a,key1,0,64,8);
    caeser_cipher(a,10,0,32);
    int key2[4]={2,4,1,3};
    rail_fence_cipher(a,key2,32,64,4);
    swap(a,0,64);
    trithemius_cipher(a,52,1,0,64);
    rotate(a,'r',7,0,64);
}
