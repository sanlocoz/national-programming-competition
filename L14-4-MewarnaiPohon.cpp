#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> v[300005];
int list[300005],itung[300005],p[300005],n,q,a,b,ans;
void cari(int b,int sblm)
{
	for(int i=0;i<v[b].size();i++)
	{
		if(v[b][i]!=sblm)
		{
			cari(v[b][i],b);
		}
	}
	itung[list[b]]++;
}
int main ()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&list[i]);
	}
	p[1]=1;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a);
		p[i]=a;
		v[a].push_back(i);
	}
	if(n<=1000 && q<=1000)
	{
		while(q--)
		{
			scanf("%d%d",&a,&b);
			if(a==0)
			{
				ans=0;
				for(int i=0;i<=100;i++)
				{
					itung[i]=0;
				}
				cari(b,-1);
				for(int i=0;i<=100;i++)
				{
					if(itung[i]%2)
					{
						ans++;
					}
				}
				printf("%d\n",ans);
			}
			else
			{
				list[b]=a;
			}
		}
	}
	else
	{
		
	}
	return 0;
}
