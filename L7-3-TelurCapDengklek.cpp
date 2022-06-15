#include <algorithm>
#include <cstdio>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
long long r,c,list[2005][205],aa[10],bb[10],a,b,d,vis[2005][205],y,x,ans;
priority_queue <pair <long long,pair<long long,long long> > > pq;
int main ()
{
	scanf("%lld%lld",&r,&c);
	aa[1]=1;
	aa[2]=-1;
	for(long long i=1;i<=r;i++)
	{
		for(long long j=1;j<=c;j++)
		{
			scanf("%lld",&list[i][j]);
		}
	}
	a=1;
	b=1;
	scanf("%lld",&d);
	for(long long i=0;i<=r+1;i++)
	{
		vis[i][0]=vis[i][c+1]=1;
	}
	for(long long j=0;j<=c+1;j++)
	{
		vis[0][j]=vis[r+1][j]=1;
	}
	while(d--)
	{
		while(!pq.empty())
		{
			pq.pop();
		}
		pq.push(mp(-list[a][b],mp(a,b)));
		long long temp=-1;
		scanf("%lld%lld",&y,&x);
		for(long long i=1;i<=r;i++)
		{
			for(long long j=1;j<=c;j++)
			{
				vis[i][j]=0;
			}
		}
		vis[a][b]=1;
		while(!pq.empty())
		{
			long long sd,sy,sx;
			sd=pq.top().fs;
			sy=pq.top().sc.fs;
			sx=pq.top().sc.sc;
//			printf("-- %lld %lld %lld --\n",sd,sy,sx);
			pq.pop();
			for(long long i=1;i<=2;i++)
			{
				if(vis[sy][sx+aa[i]]==0)
				{
					if(sy==y && sx+aa[i]==x)
					{
						temp=-sd;
						break;
					}
					vis[sy][sx+aa[i]]=1;
//					printf("    --- %lld %lld %lld ---\n",sd-list[sy][sx+aa[i]],sy,sx+aa[i]);
					pq.push(mp(sd-list[sy][sx+aa[i]],mp(sy,sx+aa[i])));
				}
			}
			if(sx==c || sx==1)
			{
				for(long long i=1;i<=2;i++)
				{
					if(vis[sy+aa[i]][sx]==0)
					{
						if(sy+aa[i]==y && sx==x)
						{
							temp=-sd;
							break;
						}
						vis[sy+aa[i]][sx]=1;
//					printf("    --- %lld %lld %lld ---\n",sd-list[sy+aa[i]][sx],sy+aa[i],sx);
						pq.push(mp(sd-list[sy+aa[i]][sx],mp(sy+aa[i],sx)));
					}
				}
			}
			if(temp!=-1)
			{
				break;
			}
		}
		a=y;
		b=x;
		ans+=max(0LL,temp);
//		printf("-- %lld %lld --\n",temp,ans);
	}
	ans+=list[y][x];
	printf("%lld\n",ans);
	return 0;
}
