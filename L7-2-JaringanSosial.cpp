#include <algorithm>
#include <cstdio>
#include <vector>
#define INF -1000000000
using namespace std;
int n,m,u[2005],a,b,list[5][2005],cek,ta,tb;
vector <int> v[2005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&u[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
	{
		list[1][i]=INF;
		list[2][i]=INF;
	}
	list[1][1]=u[1];
	for(int _=1;_<n;_++)
	{
		for(int i=min(_,2);i<=n;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				for(int k=1;k<=2;k++)
				{
					list[k%2+1][v[i][j]]=max(list[k][i]+(k*2-3)*u[v[i][j]],list[k%2+1][v[i][j]]);
				}
			}
		}
	}
	cek=0;
	ta=list[1][1];
	tb=list[2][1];
	if(ta-u[1]>=u[1]*2 || tb+u[1]>=u[1]*2)
	{
		cek=2;
	}
//	for(int i=1;i<=n;i++)
//	{
//		printf("-- %d %d --\n",list[1][i],list[2][i]);
//	}
	for(int _=1;_<=n;_++)
	{
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				for(int k=1;k<=2;k++)
				{
					list[k%2+1][v[i][j]]=max(list[k%2+1][v[i][j]],list[k][i]+(k*2-3)*u[v[i][j]]);
				}
			}
		}
		if(list[1][1]>ta  || list[2][1]>tb)
		{
			cek=2;
		}
	}
	if(cek==2)
	{
		printf("YA\n");
	}
	else
	{
		printf("TIDAK\n");
	}
	return 0;
}
