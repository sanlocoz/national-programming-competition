#include <algorithm>
#include <cstdio>
#define MOD 1000000007
using namespace std;
long long n,dp[1005][105][105],m,hsl;
long long f(long long idx,long long l,long long r)
{
	if(idx==n)
	{
		return 1;
	}
	if(dp[idx][l][r]!=-1)
	{
		return dp[idx][l][r];
	}
	if(dp[idx][r][l]!=-1)
	{
		return dp[idx][r][l];
	}
	long long temp=0;
	for(int i=min(l,r);i<=m;i++)
	{
		for(int j=min(l,r);j<=m;j++)
		{
			if((i>=l && j>=r) || (i>=r && j>=l))
			{
				temp+=f(idx+1,i,j)%MOD;
				temp=temp%MOD;
			}
		}
	}
	dp[idx][l][r]=dp[idx][r][l]=temp;
	return temp;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=m;k++)
			{
				dp[i][j][k]=-1;
			}
		}
	}
	hsl=f(0,1,1);
	printf("%lld\n",hsl);
	return 0;
}
