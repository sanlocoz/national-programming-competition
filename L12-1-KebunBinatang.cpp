#include <algorithm>
#include <cstdio>
using namespace std;
int n,c,ans,e[205],f,l,a,takut[205][205],suka[205][205];
int main ()
{
	scanf("%d%d",&n,&c);
	for(int i=1;i<=c;i++)
	{
		scanf("%d%d%d",&e[i],&f,&l);
		e[i]--;
		for(int j=1;j<=f;j++)
		{
			scanf("%d",&a);
			a--;
			takut[i][a%n]=1;
		}
		for(int j=1;j<=l;j++)
		{
			scanf("%d",&a);
			a--;
			suka[i][a%n]=1;
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		int ctr;
		ctr=0;
		for(int j=1;j<=c;j++)
		{
			int cek;
			cek=0;
			for(int k=0;k<=4;k++)
			{
				if(takut[j][(e[j]+k)%n]==1 && (i&(1<<((e[j]+k)%n))))
				{
					cek=1;
				}
				if(suka[j][(e[j]+k)%n]==1 && !(i&(1<<((e[j]+k)%n))))
				{
					cek=1;
				}
			}
			if(cek==1)
			{
				ctr++;
			}
		}
		ans=max(ans,ctr);
	}
	printf("%d\n",ans);
	return 0;
}
