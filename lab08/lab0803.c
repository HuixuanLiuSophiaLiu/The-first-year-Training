#include<stdio.h>

int n;
int ob[15][15];
int dp[15][15];

int main(void)
{
    scanf("%d",&n);


    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            scanf("%d",&ob[i][j]);
            ob[i][j]=1-ob[i][j];
        }
    }
    dp[1][1]=1;
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            if(i==1&&j==1) continue;
            dp[i][j]=ob[i-1][j]*dp[i-1][j]+ob[i][j-1]*dp[i][j-1];
        }
    }
    
    /*for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        printf("%d",ob[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        printf("%d",dp[i][j]);
        printf("\n");
    }*/
    printf("%d",dp[n+1][n+1]);

    return 0;
}