#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair <long long,long long> list[105];
vector <long long> v,z,hsl;
long long n,awal,ans;
double jwb;
long long cross(long long a,long long b,long long c,long long d,long long e,long long f)
{
	long long p,q,r,s,ret;
	p=c-a;
	q=d-b;
	r=e-c;
	s=f-d;
	ret=p*s-q*r;
	return ret;
}
bool cek1(long long x)
{
	long long x1,x2,x3,y1,y2,y3;
	x1=list[v[v.size()-2]].fs;
	x2=list[v[v.size()-1]].fs;
	x3=list[x].fs;
	y1=list[v[v.size()-2]].sc;
	y2=list[v[v.size()-1]].sc;
	y3=list[x].sc;
	if(cross(x1,y1,x2,y2,x3,y3)<=0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool cek2(long long x)
{
	long long x1,x2,x3,y1,y2,y3;
	x1=list[z[z.size()-2]].fs;
	x2=list[z[z.size()-1]].fs;
	x3=list[x].fs;
	y1=list[z[z.size()-2]].sc;
	y2=list[z[z.size()-1]].sc;
	y3=list[x].sc;
	if(cross(x1,y1,x2,y2,x3,y3)<=0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
long long itung()
{
	long long ret;
	ret=0;
	for(long long i=1;i<=n;i++)
	{
		ret+=list[i].fs*list[i+1].sc;
		ret-=list[i].sc*list[i+1].fs;
	}
//	printf("%lld\n",ret);
	ret=abs(ret);
	return ret;
}
int main ()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&list[i].fs,&list[i].sc);
	}
	list[n+1]=list[1];
	awal=itung();
//	printf("%lld\n",awal);
	sort(list+1,list+1+n);
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d --> %lld %lld\n",i,list[i].fs,list[i].sc);
//	}
	for(long long i=1;i<=n;i++)
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
	for(long long i=n;i>=1;i--)
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
	for(long long i=0;i<v.size();i++)
	{
		hsl.push_back(v[i]);
	}
	for(long long i=1;i<z.size();i++)
	{
		hsl.push_back(z[i]);
	}
	ans=0;
	for(long long i=0;i<hsl.size()-1;i++)
	{
		ans+=list[hsl[i]].fs*list[hsl[i+1]].sc;
		ans-=list[hsl[i]].sc*list[hsl[i+1]].fs;
	}
	ans=abs(ans);
	jwb=(ans-awal);
	jwb*=100;
	jwb/=ans;
//	printf("-- %lld %lld --\n",awal,ans);
	printf("%.4lf\n",jwb);
	return 0;
}
