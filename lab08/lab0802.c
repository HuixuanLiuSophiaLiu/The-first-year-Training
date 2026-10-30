#include <stdio.h>

int dp[15][15] = {0};

int main() 
{
    int n;
    scanf("%d",&n);
    
    for (int i=0;i<=n;i++) 
    {
        dp[0][i]=1;
    }
    
    for (int i=1;i<=n;i++) 
    {
        for (int j=i;j<=n;j++) 
        {
            dp[i][j]=dp[i][j-1]+dp[i-1][j]+dp[i-1][j-1];
        }
    }
    
    printf("%d\n", dp[n][n]);
    
    return 0;
}