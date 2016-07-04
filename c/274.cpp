#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<bitset>
using namespace std;
#define N 5010
#define mod 1000000007

int n,a,b,m;
int dp[N][N];
int sum[N];
int abx(int x)
{
    if(x<0) return -x;
    return x;
}

int main()
{
    int i,j,dis,L,R,ans;
    scanf("%d%d%d%d",&n,&a,&b,&m);   
    memset(dp,0,sizeof(dp));
    dp[0][a]=1;
    for(i=1;i<=m;i++)
    {
        sum[0]=0;
        for(j=1;j<=n;j++)
            sum[j]=(sum[j-1]+dp[i-1][j])%mod;
        for(j=1;j<=n;j++)
        {
            if(j==b) continue;
            int st,ed,cha;
            cha=abx(j-b)-1;
            if(j<b)
            {
                st=1;
                ed=j+cha/2;
            }
            else
            {
                st=j-cha/2;
                ed=n;
            }
            dp[i][j]=(sum[ed]-sum[st-1])%mod;
            dp[i][j]=(dp[i][j]-dp[i-1][j])%mod;
        }
    }
    ans=0;
    for(j=1;j<=n;j++)
    {
        if(j==b) continue;
        ans=(ans+dp[m][j])%mod;
    }
    printf("%d\n",(ans+mod)%mod);
    return 0;
}
