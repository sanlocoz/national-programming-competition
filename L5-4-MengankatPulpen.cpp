#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <cassert>
using namespace std;
int n,m,tx[5][105],ty[5][105],x[5][105],y[5][105],tnd[105],p[105],ujung[5][105],ctr,ans,hsl;
map <int,short> list[205],cek;
map <int,int> gy,gx;
vector <int> vx,vy;
bool bisa(int a,int b)
{
	if(x[1][a]==x[2][a] && y[1][b]==y[2][b])
	{
		if((x[1][b]<=x[1][a] && x[1][a]<=x[2][b]) && (y[1][a]<=y[1][b] && y[1][b]<=y[2][a]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if(y[1][a]==y[2][a] && x[1][b]==x[2][b])
	{
		if((x[1][a]<=x[1][b] && x[1][b]<=x[2][a]) && (y[1][b]<=y[1][a] && y[1][a]<=y[2][b]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
int par(int x)
{
	if(p[x]==x)
	{
		return x;
	}
	p[x]=par(p[x]);
	return p[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&tx[1][i],&ty[1][i],&tx[2][i],&ty[2][i]);
		if(tx[1][i]>tx[2][i])
		{
			swap(tx[1][i],tx[2][i]);
		}
		if(ty[1][i]>ty[2][i])
		{
			swap(ty[1][i],ty[2][i]);
		}
		vx.push_back(tx[1][i]);
		vx.push_back(tx[2][i]);
		vy.push_back(ty[1][i]);
		vy.push_back(ty[2][i]);
		tnd[i]=1;
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	for(int i=0;i<vx.size();i++)
	{
		gx[vx[i]]=i;
	}
	for(int i=0;i<vy.size();i++)
	{
		gy[vy[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		tx[1][i]=gx[tx[1][i]];
		tx[2][i]=gx[tx[2][i]];
		ty[1][i]=gy[ty[1][i]];
		ty[2][i]=gy[ty[2][i]];
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(tnd[j])
			{
				if(ty[1][j]==ty[2][j] && ty[2][j]==ty[1][i] && ty[1][i]==ty[2][i])
				{
					if(tx[1][j]<=tx[2][i] && tx[1][i]<=tx[2][j])
					{
						tx[1][i]=min(tx[1][i],tx[1][j]);
						tx[2][i]=max(tx[2][i],tx[2][j]);
						tnd[j]=0;
					}
				}
				else if(tx[1][j]==tx[2][j] && tx[2][j]==tx[1][i] && tx[1][i]==tx[2][i])
				{
					if(ty[1][j]<=ty[2][i] && ty[1][i]<=ty[2][j])
					{
						ty[1][i]=min(ty[1][i],ty[1][j]);
						ty[2][i]=max(ty[2][i],ty[2][j]);
						tnd[j]=0;
					}
				}
			}
		}
	}
//	for(int i=1;i<=m;i++)
//	{
//		if(tnd[i])
//		printf("-- %d %d %d %d --\n",tx[1][i],ty[1][i],tx[2][i],ty[2][i]);
//	}

//	sampe sini harusnya udah bener

	ctr=0;
	for(int i=1;i<=m;i++)
	{
		if(tnd[i])
		{
			ctr++;
			x[1][ctr]=tx[1][i];
			x[2][ctr]=tx[2][i];
			y[1][ctr]=ty[1][i];
			y[2][ctr]=ty[2][i];
			ujung[1][ctr]=ujung[2][ctr]=0;
			cek[ctr]=0;
			p[ctr]=ctr;
		}
	}
	m=ctr;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(bisa(i,j))
			{
				p[par(j)]=par(i);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		p[i]=par(i);
		if(cek[p[i]]==0)
		{
			hsl++;
			cek[p[i]]=1;
		}
	}
	hsl--;
	if((n%2)==1)
	{
//		assert(false);
		for(int j=1;j<=m;j++)
		{
			int ans=0;
			for(int i=1;i<=m;i++)
			{
				if(p[i]==j)
				{
					list[x[1][i]][y[1][i]]++;
					list[x[2][i]][y[2][i]]++;
					if(list[x[1][i]][y[1][i]]%2==1)
					{
						ans++;
					}
					else
					{
						ans--;
					}
					if(list[x[2][i]][y[2][i]]%2==1)
					{
						ans++;
					}
					else
					{
						ans--;
					}
				}
			}
			hsl+=max(0,(ans-2)/2);
		}
	}
	printf("%d\n",hsl);
}
