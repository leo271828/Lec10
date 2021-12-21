#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define LEN 10000

int len = 0;

void Reverse(char str[]);
void Print(char str[]);
void Upper(char str[]);
void Lower(char str[]);
void Remove(char str[], char );
void Compress(char str[]);

int main(){
    int line;
    char str[LEN];
    
    // 要用 getchar 慢慢讀取才能包含所有的字元
    while(1){
        char tmp = getchar();
        if(tmp == '\n')
            break;
        str[len++] = tmp;
    }
  
    // 開始輸入行數和 command
    scanf("%d", &line);
    for(int i=0;i<line;i++){
        char command[LEN];
        scanf("%s", command);
        if (strcmp(command, "REVERSE") == 0){
            Reverse(str);
        }
        else if (strcmp(command, "PRINT") == 0){
            Print(str);
        }
        else if (strcmp(command, "TO_UPPER") == 0){
            Upper(str);
        }
        else if (strcmp(command, "TO_LOWER") == 0){
            Lower(str);
        }
        else if (strcmp(command, "REMOVE") == 0){
            // 指令通常是「REMOVE a」這類，E和a中間有個空格要先用 getchar 抓掉
            getchar();
            char target = getchar();
            Remove(str, target);
        }
        else if (strcmp(command, "COMPRESS") == 0){
            Compress(str);
        }
        
    }
    return 0;
}

void Reverse(char str[]){
    char tmp[LEN];
    strcpy(tmp, str);
    for(int i=0;i<len;i++)
        str[i] = tmp[len - 1 - i];
    Print(str);
}
void Print(char str[]){
    for(int i=0;i<len;i++)
        printf("%c", str[i]);
    printf("\n");
}
void Upper(char str[]){
    for(int i=0;i<len;i++)
        if(isalpha(str[i]))
            str[i] = toupper(str[i]);
    Print(str);
}
void Lower(char str[]){
    for(int i=0;i<len;i++)
        if(isalpha(str[i]))
            str[i] = tolower(str[i]);
    Print(str);
}
void Remove(char str[], char target){
    int j, idx;
    for(int i=0;i<len;i++){
        if(str[i] == target){
            for(j=i;j<len-1;j++){
                str[j] = str[j+1];
            }
            str[j] = '\0';
            len--;
            i--;
        }
    }
    Print(str);
}
void Compress(char str[]){ // 齁齁這個最麻煩囉
    int idx = 0;
    char tmp[LEN];
    for(int i=0;i<len; i++){
        char target = str[i]; // 現在判斷的符號
        int time = 1; // 有幾個連續相同字元
        for(int j=i+1;j<len;j++){ // 開始判斷連續
            if(target == str[j]){
                time++;
                i++;
            }
            else 
                break;
        }
        // 這裡都在處理字元出現次數time該如何轉成字元陣列
        // PS 這裡要用陣列存 不然有字元連續超過10位 你只用一個字元存的話會爆掉
        char time_str[10];
        sprintf(time_str, "%d", time); // 把 int 變成 string 的神奇函式

        tmp[idx] = '-';
        tmp[idx + 1] = target;
        for(int t=0 ;t < strlen(time_str) ; t++, idx++) // 這裡idx要+1，為了長度要剛剛好
            tmp[idx + 2] = time_str[t];
        idx += 2;
    }
    tmp[idx] = '\0';
    strcpy(str, tmp);
    len = idx;
    Print(str);
}
