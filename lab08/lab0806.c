#include<stdio.h>
#include<string.h>

long long dp[20][20],ndp[20][20];

int main(void)
{
    int n,w,b;
    scanf("%d %d %d",&n,&w,&b);

    int W=w-1;
    int H=b-1;
    int si=w/2-1;
    int sj=b/2-1;

    dp[si][sj]=1;

    for(int step=1;step<n;step++)
    {
        memset(ndp,0,sizeof(ndp));

        for(int i=0;i<W;i++)
        {
            for(int j=0;j<H;j++)
            {
                if(dp[i][j]==0)continue;

                for(int dx=-1;dx<=1;dx++)
                {
                    for(int dy=-1;dy<=1;dy++)
                    {
                        int ni=i+dx,nj=j+dy;

                        if(ni>=0&&ni<W&&nj>=0&&nj<H)
                            ndp[ni][nj]+=dp[i][j];
                    }
                }
            }
        }

        memcpy(dp,ndp,sizeof(dp));
    }

    long long ans=0;
    
    for(int i=0;i<W;i++)
        for(int j=0;j<H;j++)
            ans+=dp[i][j];

    printf("%lld\n",ans);
    return 0;
}