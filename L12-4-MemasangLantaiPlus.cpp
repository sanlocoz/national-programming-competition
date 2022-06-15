#include <algorithm>
#include <cstdio>
#define MOD 1000000
using namespace std;
int ans,n,m,dp[5005][3005];
int f(int x,int mask)
{
	int a,b,c,z,baru,q;
	z=x%n;
	q=x/n;
	a=mask & (1<<n);
	b=mask & (1<<(n-1));
	c=mask & (1<<0);
//	printf("--- %d %d %d ---\n",a,b,c);
	baru=mask%(1<<(n));
	baru=baru*2;
//	printf("-- %d %d %d --\n",q,z,mask);
	if(x>=n*m)
	{
//		printf("asdf");
		if(__builtin_popcount(mask)==n+1)
		{
//			printf("asdf");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(dp[x][mask]!=-1)
	{
		return dp[x][mask];
	}
	if(z==0)
	{
		if(mask & (1<<n))
		{
			return f(x+1,baru);
		}
		else
		{
			return 0;
		}
	}
	else if(z==n-1)
	{
		int ret;
		ret=0;
//		printf("----- %d %d %d -----\n",a,b,c);
		if(!b && a && c)
		{
			dp[x][mask]=0;
			return 0;
		}
		if(!a && b && c)
		{
			dp[x][mask]=0;
			return 0;
		}
		if(!a && !b && !c)
		{
			ret+=f(x+1,((baru | (1<<n)) | (1<<1))+1);
			ret=ret%MOD;
			ret+=f(x+1,((baru | (1<<n)) | (1<<1)));
			ret=ret%MOD;
		}
		if(!a && !b)
		{
			ret+=f(x+1,(baru | (1<<n))+1);
			ret=ret%MOD;
		}
		if(!a && !c && b)
		{
			ret+=f(x+1,(baru | (1<<1))+1);
			ret=ret%MOD;
		}
		if(a && !b && !c)
		{
			ret+=f(x+1,((baru | (1<<n)) | (1<<1))+1); 
			ret=ret%MOD;
		}
		if(a)
		{
			ret+=f(x+1,baru);
		}
		ret=ret%MOD;
		dp[x][mask]=ret;
		return ret;
	}
	else
	{
		int ret;
		ret=0;
		if(!a && b && c)
		{
			dp[x][mask]=0;
			return 0;
		}
		if(!a && !b && !c)
		{
			ret+=f(x+1,((baru | (1<<n)) | (1<<1))+1);
			ret=ret%MOD;
			ret+=f(x+1,((baru | (1<<n)) | (1<<1)));
			ret=ret%MOD;
		}
		if(!a && !b)
		{
			ret+=f(x+1,(baru | (1<<n))+1);
			ret=ret%MOD;
		}
		if(!a && !c)
		{
			ret+=f(x+1,(baru | (1<<1))+1);
			ret=ret%MOD;
		}
		if(a && !b && !c)
		{
			ret+=f(x+1,((baru | (1<<n)) | (1<<1))+1); 
			ret=ret%MOD;
		}
		if(a)
		{
			ret+=f(x+1,baru);
			ret=ret%MOD;
		}
		ret=ret%MOD;
		dp[x][mask]=ret;
		return ret;
	}
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=5001;i++)
	{
		for(int j=0;j<=2500;j++)
		{
			dp[i][j]=-1;
		}
	}
	ans=f(n+1,0);
	printf("%d\n",ans);
	return 0;
}
