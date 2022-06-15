#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
vector <long long> v,z;
pair <long long,long long> list[100005];
long long s,d,f,tempa,tempb,n;
double r,ans;
bool cek1(long long x)
{
	double m1,m2,x1,x2,x3,y1,y2,y3;
	x1=list[v[v.size()-2]].fs-r;
	x2=list[v[v.size()-1]].fs-r;
	x3=list[x].fs-r;
	y1=list[v[v.size()-2]].sc;
	y2=list[v[v.size()-1]].sc;
	y3=list[x].sc;
	m2=y3-y2;
	m2/=x3-x2;
	m1=y2-y1;
	m1/=x2-x1;
	if(m2>=m1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool cek2(long long x)
{
	double m1,m2,x1,x2,x3,y1,y2,y3;
	x1=list[z[z.size()-2]].fs+r;
	x2=list[z[z.size()-1]].fs+r;
	x3=list[x].fs+r;
	y1=list[z[z.size()-2]].sc;
	y2=list[z[z.size()-1]].sc;
	y3=list[x].sc;
	m2=y3-y2;
	m2/=x3-x2;
	m1=y2-y1;
	m1/=x2-x1;
//	printf("-- %lld --> %lf %lf ",x,m2,m1);
	if(m2>=m1)
	{
//		printf("1\n");
		return true;
	}
	else
	{
//		printf("0\n");
		return false;
	}
}
int main ()
{
	scanf("%lld%lld%lld%lld",&s,&f,&n,&d);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&list[i].fs,&list[i].sc);
	}
	tempa=0;
	tempb=0;
	r=d;
	r/=2;
	list[n+1]=mp(s+r,0);
	list[n+2]=mp(f-r,0);
//	printf("%d\n",n);
	n+=2;
	sort(list+1,list+1+n);
	for(long long i=1;i<=n;i++)
	{
//		printf("-- %d --> %d %d --\n",i,list[i].fs,list[i].sc);
		if(list[i].sc>=list[tempb].sc)
		{
			tempb=i;
		}
		if(list[i].sc>list[tempa].sc)
		{
			tempa=i;
		}
	}
//	v.push_back(1);
	for(long long i=1;i<=tempa;i++)
	{
		if(v.size()<=1)
		{
			v.push_back(i);
			continue;
		}
		else
		{
			while(v.size()>1 && cek1(i))
			{
//				printf(" - %d\n",v[v.size()-1]);
				v.pop_back();
			}
			v.push_back(i);
		}
	}
	for(long long i=tempb;i<=n;i++)
	{
		if(z.size()<=1)
		{
			z.push_back(i);
			continue;
		}
		else
		{
			while(z.size()>1 && cek2(i))
			{
				z.pop_back();
			}
//			printf("-- %lld --\n",i);
			z.push_back(i);
		}
	}
//	ans+=hypot(list[v[0]].sc,list[v[0]].fs-r-s);
	for(long long i=1;i<v.size();i++)
	{
		ans+=hypot(list[v[i]].sc-list[v[i-1]].sc,list[v[i]].fs-list[v[i-1]].fs);
//		printf("--%lld %lld --\n",v[i-1],v[i]);
	}
	for(long long i=1;i<z.size();i++)
	{
		ans+=hypot(list[z[i]].sc-list[z[i-1]].sc,list[z[i]].fs-list[z[i-1]].fs);
//		printf("--- %lld %lld ---\n",z[i-1],z[i]);
	}
//	printf("%lld %lld\n",tempa,tempb);
//	ans+=hypot(list[z[z.size()-1]].sc,f-list[z[z.size()-1]].fs-r);
	ans+=d;
	ans+=list[tempb].fs-list[tempa].fs;
	printf("%.3lf\n",ans);
	return 0;
}
