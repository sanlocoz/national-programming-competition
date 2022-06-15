#include <algorithm>
#include <cstdio>
#include <cmath>
#define eps 1e-10
#define INF 2000000000
#define pi 3.14159265
using namespace std;
long long n,a,b,x[1005],y[1005];
double bsr,kcl,ans;
int main ()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
	}
	x[n+1]=x[1];
	y[n+1]=y[1];
	bsr=0;
	kcl=INF;
	for(int i=1;i<=n;i++)
	{
		double temp1,temp2,hsl,alas,jrk;
		jrk=sqrt(pow(x[i]-a,2)+pow(y[i]-b,2));
		bsr=max(bsr,jrk);
		temp1=(((x[i]-x[i+1])*(a-x[i+1]))+((y[i]-y[i+1])*(b-y[i+1])));
		temp2=(((x[i+1]-x[i])*(a-x[i]))+((y[i+1]-y[i])*(b-y[i])));
		if(temp1<-eps)
		{
			hsl=sqrt(pow(a-x[i+1],2)+pow(b-y[i+1],2));
		}
		else if(temp2<-eps)
		{
			hsl=sqrt(pow(a-x[i],2)+pow(b-y[i],2));
		}
		else
		{
			alas=sqrt(pow(x[i]-x[i+1],2)+pow(y[i]-y[i+1],2));
			hsl=(x[i]-a)*(y[i+1]-b)-((x[i+1]-a)*(y[i]-b));
//			printf("-- %lf --\n",hsl);
			hsl=fabs(hsl);
			hsl/=alas;
		}
		kcl=min(kcl,hsl);
	}
//	printf("%lf %lf\n",kcl,bsr);
	ans=pow(bsr,2)-pow(kcl,2);
	ans*=pi;
	printf("%.6lf\n",ans);
	return 0;
}
