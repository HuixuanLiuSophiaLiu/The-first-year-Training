//这最先使用递归的做法，后来换了DP
#include<stdio.h>
#define stp1 2
#define stp2 3
#define stp3 4

int n;

long long dp[110];

int main(void)
{
    scanf("%d",&n);

    if(n==2||n==3)
    {
        printf("1");
        return 0;
    }

    dp[7]=1;
    dp[8]=1;
    dp[9]=2;

    for(int i=10;i<=n+5;i++)
    {
        dp[i]=dp[i-4]+dp[i-3]+dp[i-2];
    }
    printf("%lld",dp[n+5]);
    return 0;
}
/*int n;

long long sum;

void PlaceTheBrick(int TheRestPlace)
{
    if(TheRestPlace<0) return;
    if(TheRestPlace==0) sum++;
    PlaceTheBrick(TheRestPlace-stp1);
    PlaceTheBrick(TheRestPlace-stp2);
    PlaceTheBrick(TheRestPlace-stp3);
}
int main(void)
{
    scanf("%d",&n);

    if(n==2||n==3)
    {
        printf("1");
        return 0;
    }

    PlaceTheBrick(n);

    printf("%lld",sum);

    
    return 0;
}*/