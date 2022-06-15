#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair <pair<int,int> , int> list[10005];
vector <int> v,z;
int n,m,a,b,pager,ans,vis[10005],cek,ctr;
long long cross(int a,int b,int c,int d,int e,int f)
{
	long long p,q,r,s,ret;
	p=c-a;
	q=d-b;
	r=e-c;
	s=f-d;
	ret=p*s-q*r;
	return ret;
}
bool cek1(int x)
{
	int x1,x2,x3,y1,y2,y3;
	x1=list[v[v.size()-2]].fs.fs;
	x2=list[v[v.size()-1]].fs.fs;
	x3=list[x].fs.fs;
	y1=list[v[v.size()-2]].fs.sc;
	y2=list[v[v.size()-1]].fs.sc;
	y3=list[x].fs.sc;
	if(cross(x1,y1,x2,y2,x3,y3)<=0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool cek2(int x)
{
	int x1,x2,x3,y1,y2,y3;
	x1=list[z[z.size()-2]].fs.fs;
	x2=list[z[z.size()-1]].fs.fs;
	x3=list[x].fs.fs;
	y1=list[z[z.size()-2]].fs.sc;
	y2=list[z[z.size()-1]].fs.sc;
	y3=list[x].fs.sc;
	if(cross(x1,y1,x2,y2,x3,y3)<=0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int main ()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		list[i]=mp(mp(a,b),0);
	}
	for(int i=m+1;i<=m+n;i++)
	{
		scanf("%d%d",&a,&b);
		list[i]=mp(mp(a,b),1);
	}
	sort(list+1,list+1+m+n);
//	for(int i=1;i<=m+n;i++)
//	{
//		printf("%d --> %d %d\n",i,list[i].fs.fs,list[i].fs.sc);
//	}
	pager=1;
	ctr=m;
	while(pager && ctr>=3)
	{
		for(int i=1;i<=m+n;i++)
		{
			if(vis[i]==0)
			{
				while(v.size()>=2)
				{
					if(cek1(i))
					{
						v.pop_back();
					}
					else
					{
						break;
					}
				}
				v.push_back(i);
			}
		}
		for(int i=m+n;i>=1;i--)
		{
			if(vis[i]==0)
			{
				while(z.size()>=2)
				{
					if(cek2(i))
					{
						z.pop_back();
					}
					else
					{
						break;
					}
				}
				z.push_back(i);
			}
		}
		cek=0;
//		printf("\n");
		for(int i=1;i<v.size()-1;i++)
		{
			vis[v[i]]=1;
//			printf("-- %d --\n",v[i]);
			if(list[v[i]].sc)
			{
				if(cross(list[v[i-1]].fs.fs,list[v[i-1]].fs.sc,list[v[i]].fs.fs,list[v[i]].fs.sc,list[v[i+1]].fs.fs,list[v[i+1]].fs.sc))
				{
					pager=0;
				}
			}
//			printf("%d --> %d %d\n",v[i],list[v[i]].fs.fs,list[v[i]].fs.sc);
		}
//		printf("---\n");
		vis[z[0]]=1;
		vis[v[0]]=1;
//		printf("-- %d --\n",z[0]);
//		printf("-- %d --\n",v[0]);
		if(list[v[0]].sc)
		{
			if(cross(list[z[z.size()-1]].fs.fs,list[z[z.size()-1]].fs.sc,list[v[0]].fs.fs,list[v[0]].fs.sc,list[v[1]].fs.fs,list[v[1]].fs.sc))
			{
				pager=0;
			}
		}
		if(list[z[0]].sc)
		{
			if(cross(list[v[v.size()-1]].fs.fs,list[v[v.size()-1]].fs.sc,list[z[0]].fs.fs,list[z[0]].fs.sc,list[z[1]].fs.fs,list[z[1]].fs.sc))
			{
				pager=0;
			}
		}
		for(int i=1;i<z.size()-1;i++)
		{
			vis[z[i]]=1;
//			printf("-- %d --\n",z[i]);
			if(list[z[i]].sc)
			{
				if(cross(list[z[i-1]].fs.fs,list[z[i-1]].fs.sc,list[z[i]].fs.fs,list[z[i]].fs.sc,list[z[i+1]].fs.fs,list[z[i+1]].fs.sc))
				{
					pager=0;
				}
			}
//			printf("%d --> %d %d\n",z[i],list[z[i]].fs.fs,list[z[i]].fs.sc);
		}
		ans+=pager;
		while(v.size())
		{
			if(list[v.size()-1].sc==0)
			{
				ctr--;
			}
			v.pop_back();
		}
		while(z.size())
		{
			if(list[z.size()-1].sc==0)
			{
				ctr--;
			}
			z.pop_back();
		}
		ctr+=2;
//		printf("\n");
	}
	printf("%d\n",ans);
	return 0;
}
