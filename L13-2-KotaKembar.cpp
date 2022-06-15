#include <algorithm>
#include <cstdio>
#include <vector>
#define MOD 100000007
using namespace std;
long long anak[405],sdr[405],dp[405][405][5],n,m,k,a,b,ans;
vector <long long> v[405];
void dfs(long long x,long long sblm)
{
//	printf("-- %lld %lld --\n",x,sblm);
	long long lc;
	anak[x]=-1;
	sdr[x]=-1;
	lc=-1;
	for(long long i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=sblm)
		{
			if(anak[x]==-1)
			{
//				printf("anak %lld --> %lld\n",x,v[x][i]);
				anak[x]=v[x][i];
			}
			if(lc!=-1)
			{
//				printf("sodara %lld --> %lld\n",lc,v[x][i]);
				sdr[lc]=v[x][i];
			}
			dfs(v[x][i],x);
			lc=v[x][i];
		}
	}
	return;
}
long long f(long long x,long long sisa,long long p)
{
//	printf("-- %lld %lld %lld --\n",x,sisa,p);
	if(sisa==0)
	{
//		printf("-- %lld %lld %lld --> 1 --\n",x,sisa,p);
		return 1;
	}
	if(dp[x][sisa][p]!=-1)
	{
		return dp[x][sisa][p];
	}
	long long &ret=dp[x][sisa][p];
	ret=0;
	if(anak[x]==-1 && sdr[x]==-1)
	{
//		printf("-- %lld %lld %lld --> %lld --\n",x,sisa,p,!sisa);
		if(sisa==0)
		{
			return 1;
		}
		else if (sisa==1 && p==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(anak[x]==-1)
	{
		ret=f(sdr[x],sisa,p);
//		printf("-- %lld %lld %lld --> %lld -- sodara ini\n",x,sisa,p,ret);
		if(p==0)
		{
			ret+=f(sdr[x],sisa-1,1);
			ret=ret%MOD;
		}
		printf("-- %lld %lld %lld --> %lld -- sodara ini\n",x,sisa,p,ret);
		return ret;
	}
	if(sdr[x]==-1)
	{
		ret=f(anak[x],sisa,0);
		if(p==0)
		{
			ret+=f(anak[x],sisa-1,1);
			ret=ret%MOD;
		}
		printf("-- %lld %lld %lld --> %lld -- anak ini \n",x,sisa,p,ret);
		return ret;
	}
	for(long long i=0;i<=sisa;i++)
	{
		ret+=(f(anak[x],sisa-i,0)*f(sdr[x],i,p))%MOD;
		ret=ret%MOD;
	}
	if(p==0)
	{
		for(long long i=0;i<sisa;i++)
		{
			ret+=(f(anak[x],sisa-i-1,1)*f(sdr[x],i,1))%MOD;
			ret=ret%MOD;
		}
	}
	ret=ret%MOD;
	printf("-- %lld %lld %lld --> %lld --\n",x,sisa,p,ret);
	return ret;
}
int main ()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
//	for(long long i=1;i<=n;i++)
//	{
//		printf("%lld --> %lld %lld\n",i,anak[i],sdr[i]);
//	}
	for(long long i=0;i<=n;i++)
	{
		for(long long j=0;j<=k;j++)
		{
			for(long long l=0;l<=2;l++)
			{
				dp[i][j][l]=-1;
			}
		}
	}
	ans=f(1,k,1);
	printf("%lld\n",ans);
	return 0;
}
