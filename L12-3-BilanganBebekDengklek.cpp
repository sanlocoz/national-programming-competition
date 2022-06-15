#include <algorithm>
#include <cstdio>
#define MOD 1000000007
using namespace std;
int n,ps[50],list[50],ans,x,y,z;
int f(int a)
{
	if(a>n)
	{
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d ",list[i]);
//		}
//		printf("\n");
//		for(int i=1;i<=n;i++)
//		{
//			printf("%d ",ps[i]);
//		}
//		printf("\n");
//		printf("\n");
		int cek=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k;l<=n;l++)
					{
						if(ps[j-1]-ps[i-1]==x && ps[k-1]-ps[j-1]==y && ps[l]-ps[k-1]==z)
						{
							cek=1;
//							printf("asdf");
							break;
						}
					}
					if(cek)
					{
						break;
					}
				}
				if(cek)
				{
					break;
				}
			}
			if(cek)
			{
				break;
			}
		}
		return cek;
	}
	int ret=0;
	for(int i=1;i<=10;i++)
	{
		list[a]=i;
		ps[a]=ps[a-1]+list[a];
		ret+=f(a+1);
		ret=ret%MOD;
	}
	return ret;
}
int main ()
{
	scanf("%d%d%d%d",&n,&x,&y,&z);
	if(x<=2 && y<=2 && z<=2)
	{
		ct[x]++;
		ct[y]++;
		ct[z]++;
		if(ct[1]==0)
		{
			
		}
		else if(ct[1]==1)
		{
			
		}
		else if(ct[1]==2)
		{
			
		}
		else if(ct[1]==3)
		{
			ans+=9*pow(10,n-4)%MOD*2;
			ans=ans%MOD;
			ans+=81*pow(10,n-5)%MOD*(n-4);
			ans=ans%MOD;
		}
		printf("%lld\n",ans);
		return 0;
	}
	ans=f(1);
	printf("%d\n",ans);
	return 0;
}
