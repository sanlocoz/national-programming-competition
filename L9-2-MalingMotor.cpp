#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair<pair<long long,long long> , pair<long long,long long> > list[10005];
long long n,vis[10005],lol;
vector <long long> zz[10005],v[10005];
vector <pair<double,double> > ej;
priority_queue <pair<double,long long> > pq;
double cross(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
	long long aa,bb,cc,dd,temp;
	aa=x2-x1;
	bb=y2-y1;
	cc=x3-x2;
	dd=y3-y2;
	temp=aa*dd-bb*cc;
	if(temp>0)
	{
		return 1;
	}
	else if(temp<0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
pair<double,double> itung(long long aa,long long bb)
{
	double x1,x2,x3,x4,y1,y2,y3,y4;
	x1=list[aa].fs.fs;
	x2=list[aa].sc.fs;
	x3=list[bb].fs.fs;
	x4=list[bb].sc.fs;
	y1=list[aa].fs.sc;
	y2=list[aa].sc.sc;
	y3=list[bb].fs.sc;
	y4=list[bb].sc.sc;
	double x,y;
	x=(x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4);
	x/=(x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);
	y=(x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4);
	y/=(x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);
	return mp(x,y);
}
int main ()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld%lld",&list[i].fs.fs,&list[i].fs.sc,&list[i].sc.fs,&list[i].sc.sc);
	}
	for(long long i=1;i<=n;i++)
	{
		zz[i].push_back(ej.size());
		ej.push_back(mp(list[i].fs.fs,list[i].fs.sc));
		lol=ej.size();
//		printf("lol --> %d\n",lol);
		zz[i].push_back(ej.size());
		ej.push_back(mp(list[i].sc.fs,list[i].sc.sc));
		for(long long j=i+1;j<=n;j++)
		{
			double a,b,c,d;
			double x,y;
			a=cross(list[i].fs.fs,list[i].fs.sc,list[i].sc.fs,list[i].sc.sc,list[j].fs.fs,list[j].fs.sc);
			b=cross(list[i].fs.fs,list[i].fs.sc,list[i].sc.fs,list[i].sc.sc,list[j].sc.fs,list[j].sc.sc);
			c=cross(list[j].fs.fs,list[j].fs.sc,list[j].sc.fs,list[j].sc.sc,list[i].fs.fs,list[i].fs.sc);
			d=cross(list[j].fs.fs,list[j].fs.sc,list[j].sc.fs,list[j].sc.sc,list[i].sc.fs,list[i].sc.sc);
			if(a!=b && c!=d)
			{
				pair <double,double> pii;
				pii=itung(i,j);
				x=pii.fs;
				y=pii.sc;
//				printf("-- %d %d --\n",i,j);
			}
			else if(a==0 && b==0 && c==0 && d==0)
			{
				double x,y,x1,x2,x3,x4,y1,y2,y3,y4;
				x1=list[i].fs.fs;
				x2=list[i].sc.fs;
				x3=list[j].fs.fs;
				x4=list[j].sc.fs;
				y1=list[i].fs.sc;
				y2=list[i].sc.sc;
				y3=list[j].fs.sc;
				y4=list[j].sc.sc;
				if(x1==x3 && y1==y3)
				{
					x=x1;
					y=y1;
				}
				else if(x1==x4 && y1==y4)
				{
					x=x1;
					y=y1;
				}
				else if(x2==x3 && y2==y3)
				{
					x=x2;
					y=y2;
				}
				else if(x2==x4 && y2==y4)
				{
					x=x2;
					y=y2;
				}
			}
			else
			{
				continue;
			}
			zz[i].push_back(ej.size());
			zz[j].push_back(ej.size());
			ej.push_back(mp(x,y));
		}
	}
//	for(int i=0;i<ej.size();i++)
//	{
//		printf("%d --> %lf %lf\n",i,ej[i].fs,ej[i].sc);
//	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<zz[i].size();j++)
		{
			for(long long k=0;k<zz[i].size();k++)
			{
				if(k!=j)
				{
					v[zz[i][k]].push_back(zz[i][j]);
//					v[zz[i][j]].push_back(zz[i][k]);
				}
			}
		}
	}
//	for(int i=0;i<=8;i++)
//	{
//		printf("-- %d --\n",i);
//		for(int j=0;j<v[i].size();j++)
//		{
//			printf("    %d\n",v[i][j]);
//		}
//	}
	pq.push(mp(0,0));
	double ans;
	while(!pq.empty())
	{
		double jrk;
		long long skrg;
		jrk=-pq.top().fs;
		skrg=pq.top().sc;
//		printf("%lf %d\n",jrk,skrg);
		pq.pop();
		vis[skrg]=1;
		if(skrg==lol)
		{
			ans=jrk;
			break;
		}
		for(long long i=0;i<v[skrg].size();i++)
		{
			if(vis[v[skrg][i]]==0)
			{
				pq.push(mp(-(jrk+hypot((ej[skrg].fs-ej[v[skrg][i]].fs),(ej[skrg].sc-ej[v[skrg][i]].sc))),v[skrg][i]));
			}
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
