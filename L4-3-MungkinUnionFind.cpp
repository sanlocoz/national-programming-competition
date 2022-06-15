#include <algorithm>
#include <cstdio>
using namespace std;
long long p[200005],n,m,k,a,b,jmlh[200005],bnyk[200005];
long long par(long long x)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=par(p[x]);
	return p[x];
}
inline void update(long long a,long long b)
{
	if(a==b)
	{
		return;
	}
	p[a]=b;
	jmlh[b]+=jmlh[a];
	bnyk[b]+=bnyk[a];
	return;
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		p[i]=100000+i;
		p[i+100000]=i+100000;
		jmlh[i]=jmlh[i+100000]=i;
		bnyk[i]=bnyk[i+100000]=1;
	}
	while(m--)
	{
		scanf("%lld",&k);
		if(k==1)
		{
			scanf("%lld%lld",&a,&b);
			a=par(a);
			b=par(b);
			update(a,b);
		}
		else if(k==2)
		{
			scanf("%lld%lld",&a,&b);
			int temp;
			temp=par(a);
			bnyk[temp]--;
			jmlh[temp]-=a;
			b=par(b);
			update(a,b);
		}
		else if(k==3)
		{
			scanf("%lld",&a);
			a=par(a);
			printf("%lld %lld\n",bnyk[a],jmlh[a]);
		}
	}
	return 0;
}
