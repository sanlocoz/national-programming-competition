#include <algorithm>
#include <cstdio>
using namespace std;
long long n,ctra,ans;
long long a,gede,temp,list[3005],dp[3005][3005],ps[3005];
long long binser(long long l,long long r,long long cari,long long i)
{
	if(l==r)
	{
		return r;
	}
	long long piv,zz;
	piv=(l+r)/2;
	zz=ps[piv]-ps[i];
//	printf("---- %lld %lld %lld ----\n",l,r,zz);
	if(zz>=cari)
	{
		return binser(l,piv,cari,i);
	}
	else
	{
		return binser(piv+1,r,cari,i);
	}
}
int main ()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&list[i]);
		ps[i]=ps[i-1]+list[i];
	}
	for(long long i=1;i<=n;i++)
	{
		dp[n][i]=1;
	}
	for(long long i=n-1;i>=1;i--)
	{
		for(long long j=i;j>=1;j--)
		{
			long long a,temp=ps[i]-ps[j-1];
			a=binser(i+1,n,temp,i);
//			printf("-- %lld %lld --> %lld\n",j,i,a);
			if(ps[n]-ps[i]<temp)
			{
				dp[i][j]=0;
			}
			else
			{
				dp[i][j]=dp[a][i+1]+1;
			}
			dp[i][j]=max(dp[i][j],dp[i+1][j]);
		}
	}
//	for(long long i=1;i<=n;i++)
//	{
//		for(long long j=1;j<=n;j++)
//		{
//			printf("%lld ",dp[i][j]);
//		}
//		printf("\n");
//	}
	for(long long i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][1]);
	}
	printf("%lld\n",ans);
	return 0;
}
