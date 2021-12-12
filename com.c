#include <stdio.h>

int n, m;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void show(int **pic){
    for(int i=0;i<n;i++, printf("\n"))
        for(int j=0;j<m;j++)
            printf("%d ", pic[i][j]);
    printf("\n");
}
void vertical(int **pic){
    for(int i=0;i<n/2;i++)
        for(int j=0;j<m;j++)
            swap(&pic[i][j], &pic[(n-1)-i][j]);
}
void horizontal(int **pic){
    for(int i=0;i<n;i++)
        for(int j=0;j<m/2;j++)
            swap(&pic[i][j], &pic[i][(m-1)-j]);
}
void rotation_right(int **pic, int len){
    int temp[len][len];
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++){
            temp[i][j] = pic[i][j];
        }
    
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            pic[i][j] = temp[j][i];
    swap(&n, &m);
    horizontal(pic);
}
int clip(int **pic, int len, int *bd){
    int temp[len][len];
    int index_i=0, index_j=0;

    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            temp[i][j] = 0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            temp[i][j] = pic[i][j];
            pic[i][j] = 0;
        }
    n = bd[3] - bd[2] + 1;
    m = bd[1] - bd[0] + 1;
    for(int i=bd[2]-1, idx_i=0 ; i<bd[3] ; i++, idx_i++)
        for(int j=bd[0]-1, idx_j=0 ; j<bd[1] ; j++, idx_j++){
            pic[idx_i][idx_j] = temp[i][j];
        }
    return n >= m ? n : m ;
}
int main(void){
    // int n, m;
    scanf("%d %d", &n, &m);
    int len = n >= m? n : m;
    int pic[len][len], *p[len];
    for(int i=0;i<len;i++){
        p[i] = &pic[i][0];
        for(int j=0;j<len;j++)
            pic[i][j] = 0;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &pic[i][j]);

    int line;
    scanf("%d", &line);
    for(int time=0;time<line;time++){
        char a, temp1 = getchar();
        scanf("%c", &a);
        if(a == 'r'){
            int t;
            char diretion, temp2 = getchar();
            scanf("%c %d", &diretion, &t);
            t %= 4;
            if(diretion == 'r'){
                for(int idx=0;idx<t;idx++)
                    rotation_right(p, len);
            }
            else if(diretion == 108){
                for(int idx=0;idx<4-t;idx++)
                    rotation_right(p, len);
            }
        }
        else if (a == 'p'){
            show(p);
        }
        else if (a == 'h'){
            horizontal(p);
        }
        else if (a == 'v'){
            vertical(p);
        }
        else if (a == 'c'){
            int bd[4];
            int *bd_p = &bd[0];
            scanf("%d %d %d %d", &bd[0], &bd[1], &bd[2], &bd[3]);
            len = clip(p, len, bd_p);
        }
    }

    return 0;
}