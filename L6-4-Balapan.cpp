#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int p[100005],n,m,grup,ttl,ans;
pair <int,pair<int,int> > list[100005];
int par(int x)
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		p[i]=i;
		scanf("%d%d%d",&list[i].sc.fs,&list[i].sc.sc,&list[i].fs);
		ttl+=list[i].fs;
		list[i].fs=-list[i].fs;
	}
//	printf("%d\n",ttl);
	sort(list+1,list+1+m);
	grup=n;
	ans=0;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		a=par(list[i].sc.fs);
		b=par(list[i].sc.sc);
		if(a!=b)
		{
//			printf("-- %d %d %d --\n",-list[i].fs,list[i].sc.fs,list[i].sc.sc);
			grup--;
			p[a]=b;
			ans-=list[i].fs;
		}
		if(grup==1)
		{
			break;
		}
	}
	ttl-=ans;
	printf("%d\n",ttl);
	return 0;
}
