#include <algorithm>
#include <cstdio>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int p[505],n,m,temp,a,b,c,mst,ans,ttl,ctr;
queue <int> q;
pair <int,pair<int,int> > list[50005];
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
		scanf("%d%d%d",&a,&b,&c);
		list[i]=mp(c,mp(a,b));
	}
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
	}
	sort(list+1,list+1+m);
	ctr=0;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		a=par(list[i].sc.fs);
		b=par(list[i].sc.sc);
//		printf("%d --> %d , %d --> %d\n",list[i].sc.fs,a,list[i].sc.sc,b);
		if(a!=b)
		{
			p[a]=b;
			ctr++;
			mst+=list[i].fs;
			q.push(i);
		}
//		if(ctr==n-1)
//		{
//			break;
//		}
	}
//	while(q.size())
//	{
//		printf("%d\n",q.front());
//		q.pop();
//	}
	while(q.size())
	{
		for(int i=1;i<=n;i++)
		{
			p[i]=i;
		}
		temp=0;
		ctr=0;
		for(int i=1;i<=m;i++)
		{
			if(i!=q.front())
			{
				int a,b;
				a=par(list[i].sc.fs);
				b=par(list[i].sc.sc);
				if(a!=b)
				{
					p[a]=b;
					temp+=list[i].fs;
				}
				ctr++;
			}
//			if(ctr==n-1)
//			break;
		}
		if(temp!=mst/* && ctr==n-1*/)
		{
			ans++;
			ttl+=list[q.front()].fs;
		}
		q.pop();
	}
	printf("%d %d\n",ans,ttl);
	return 0;
}
