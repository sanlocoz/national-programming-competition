#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int p[1005],n,cek,ctr,tnd[1005][1005],m,jrk[1005][1005];
pair<int,pair<int,int> > list[1000005];
vector <int> v[1005];
int itung(int a,int c,int b)
{
	if(jrk[a][b]!=-1)
	{
		return jrk[a][b];
	}
	printf("asdf %d %d %d",a,c,b);
	if(a==b)
	{
		printf(" 0\n");
		return 0;
	}
	if(jrk[a][c]==-1 || jrk[c][b]==-1)
	{
		printf(" -1\n");
		return -1;
	}
	else
	{
		printf(" --> %d \n",jrk[a][c]+jrk[c][b]);
		return jrk[a][c]+jrk[c][b];
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
int main ()
{
	scanf("%d",&n);
	cek=1;
	ctr=0;
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&tnd[i][j]);
			if(i>j)
			{
				if(tnd[i][j]!=tnd[j][i])
				{
					cek=0;
				}
				list[++ctr]=mp(tnd[i][j],mp(i,j));
			}
			jrk[i][j]=-1;
			if(i==j)
			{
				jrk[i][j]=0;
			}
		}
	}
	if(cek==0)
	{
		printf("Tidak\n");
		return 0;
	}
	m=n*(n-1);
	m/=2;
	sort(list+1,list+1+m);
	for(int i=1;i<=m;i++)
	{
		printf("         %d --> %d , %d && %d\n",i,list[i].fs,list[i].sc.fs,list[i].sc.sc);
		int a,b,c,d;
		a=list[i].sc.fs;
		b=list[i].sc.sc;
		c=par(a);
		d=par(b);
//		printf("-- %d %d --\n",c,d);
		if(c!=d)
		{
			p[c]=d;
			jrk[a][b]=list[i].fs;
			jrk[b][a]=list[i].fs;
			for(int j=1;j<=n;j++)
			{
				printf("--- %d\n",j);
				jrk[j][a]=jrk[a][j]=itung(j,b,a);
				jrk[j][b]=jrk[b][j]=itung(j,a,b);
			}
//			v[a].push_back(b);
//			v[b].push_back(a);
		}
		else
		{
			printf("-- %d --\n",i);
			for(int j=1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					printf("%d %d --> %d\n",j,k,jrk[j][k]);
				}
			}
			if(jrk[a][b]!=list[i].fs)
			{
				printf("%d %d %d--> ",i,a,b);
				printf("Tidak\n");
				return 0;
			}
		}
	}
	printf("Ya\n");
	return 0;
}
