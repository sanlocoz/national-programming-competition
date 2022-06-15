#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
map <double,int> list;
long long n,y[2005],x[2005],ans;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y[i],&x[i]);
	}
	ans=n;
	ans*=n-1;
	ans/=2;
	ans*=n-2;
	ans/=3;
	for(int i=1;i<=n;i++)
	{
		list.clear();
		for(int j=i+1;j<=n;j++)
		{
			double a;
			a=y[i]-y[j];
			if(x[i]-x[j]==0)
			{
				a=-999;
			}
			else
			{
				a/=x[i]-x[j];
			}
			ans-=list[a];
			list[a]++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
