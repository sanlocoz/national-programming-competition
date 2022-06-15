#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int n,a,b,c,d,ans,ctr,bwh,ttl;
vector <int> x;
vector <pair <pair<int,int> , pair<int,int> > > y;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		x.push_back(a);
		x.push_back(c);
		y.push_back(mp(mp(b,1),mp(a,c)));
		y.push_back(mp(mp(d,-1),mp(a,c)));
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	ans=0;
//	for(int i=0;i<x.size();i++)
//	{
//		printf("%d --> %d\n",i,x[i]);
//	}
	for(int i=1;i<x.size();i++)
	{
		ttl=0;
		ctr=0;
//		printf("-- %d --\n",x[i]);
		for(int j=0;j<y.size();j++)
		{
			if(y[j].sc.fs<=x[i-1] && y[j].sc.sc>=x[i])
			{
				if(ctr==0)
				{
					bwh=y[j].fs.fs;
				}
				ctr+=y[j].fs.sc;
//				printf("---- %d --> %d ----\n",y[j].fs.fs,ctr);
				if(ctr==0)
				{
//					printf("-- %d %d %d %d --\n",x[i],x[i-1],y[j].fs.fs,bwh);
					ttl+=(x[i]-x[i-1])*(y[j].fs.fs-bwh);
//					printf("easdf %d\n",ttl);
				}
			}
		}
		ans+=ttl;
	}
	printf("%d\n",ans);
	return 0;
}
