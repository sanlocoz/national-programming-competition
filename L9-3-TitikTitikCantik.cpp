#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int y[3005],x[3005],n;
double ans;
double itung(int a,int b,int c)
{
	double ret;
	ret=x[a]*y[b];
	ret+=x[b]*y[c];
	ret+=x[c]*y[a];
	ret-=x[a]*y[c];
	ret-=x[b]*y[a];
	ret-=x[c]*y[b];
	ret=abs(ret);
	ret/=2;
	return ret;
}
int main ()
{
	ans=0;
//	double z;
//	z=sqrt(0.5);
//	printf("%lf\n",z);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				ans+=itung(i,j,k);
			}
		}
	}
	printf("%.1lf\n",ans);
	return 0;
}
