#include<stdio.h>

int n;
long long a,b,c,d,e,f;
long long g[5000];
int main(void)
{
    scanf("%d %lld %lld %lld %lld %lld %lld",&n,&a,&b,&c,&d,&e,&f);
    g[0]=d;
    g[1]=e;
    g[2]=f;
    for(int i=3;i<=n;i++)
    {
        g[i]=a*g[i-1]+b*g[i-2]+c*g[i-3];
        g[i]%=1000000007;
    }
    printf("%lld",g[n]);
    return 0;
}