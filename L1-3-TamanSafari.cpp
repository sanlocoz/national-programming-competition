#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
double temp,ans,hsl;
long long bsr[100005],p[100005],n,m,a,b,gede[100005];
pair <long long,pair<long long,long long> > list[100005];
long long ortu(long long x)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=ortu(p[x]);
	return p[x];
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=0;i<n;i++)
	{
		scanf("%lld",&gede[i]);
		p[i]=i;
		bsr[i]=1;
	}
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld%lld",&a,&b);
		list[i]=mp(min(gede[a],gede[b]),mp(a,b));
	}
	sort(list+1,list+1+m);
	temp=n*(n-1);
	temp/=2;
	hsl=0;
	for(long long i=m;i>=1;i--)
	{
		long long x,y;
		x=ortu(list[i].sc.fs);
		y=ortu(list[i].sc.sc);
		if(x!=y)
		{
			ans=bsr[x]*bsr[y]*list[i].fs;
			hsl+=ans/temp;
			p[x]=y;
			bsr[y]+=bsr[x];
		}
		
	}
	printf("%.8lf\n",hsl);
	return 0;
}
