#include <algorithm>
#include <cstdio>
using namespace std;
long long n,m,q,baris[100005],kolom[100005],p,r,k,e,a,b,c,d;
int main ()
{
	scanf("%lld%lld%lld",&n,&m,&q);
	while(q--)
	{
		scanf("%lld",&p);
		if(p==1)
		{
			scanf("%lld%lld",&r,&k);
			for(long long i=r;i<=n;i+=(i&-i))
			{
				baris[i]+=k;
			}
		}
		else if(p==2)
		{
			scanf("%lld%lld",&e,&k);
			for(long long i=e;i<=m;i+=(i&-i))
			{
				kolom[i]+=k;
			}
		}
		else if(p==3)
		{
			scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
			long long ans,y,x;
			ans=0;
			y=0;
			x=0;
			for(long long i=c;i>=1;i-=(i&-i))
			{
				y+=baris[i];
			}
			for(long long i=a-1;i>=1;i-=(i&-i))
			{
				y-=baris[i];
			}
			for(long long i=d;i>=1;i-=(i&-i))
			{
				x+=kolom[i];
			}
			for(long long i=b-1;i>=1;i-=(i&-i))
			{
				x-=kolom[i];
			}
			ans=y*(d-b+1)+x*(c-a+1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
