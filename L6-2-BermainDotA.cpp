#include <algorithm>
#include <cstdio>
#define MOD 1000000007
#define fs first
#define sc second
#define mp make_pair
using namespace std;
long long p[40005],n,m,temp,a,b,c,mst,ans,ttl,ctr;
pair <long long,pair<long long,long long> > list[100005];
long long par(long long x)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=par(p[x]);
	return p[x];
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		list[i]=mp(c,mp(a,b));
	}
	for(long long i=1;i<=n;i++)
	{
		p[i]=i;
	}
	sort(list+1,list+1+m);
	for(long long i=1;i<=m;i++)
	{
		long long a,b;
		a=par(list[i].sc.fs);
		b=par(list[i].sc.sc);
		if(a!=b)
		{
			p[a]=b;
			mst+=list[i].fs;
			mst=mst%MOD;
			q.push(i);
		}
	}
	printf("%lld %lld\n",mst,ans);
	return 0;
}
