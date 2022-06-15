#include <algorithm>
#include <cstdio>
#include <vector>
#define fs first
#define sc second
#define mp make_pair
#define INF 1000000000
using namespace std;
long long mid,mask,list[10][105],n,hsl[105],cek;
pair<long long,pair<long long,long long> > ans;
vector <pair<pair<long long,long long> , pair<long long,long long> > > dpn,blkg;
void dfs1(long long dlm,long long a,long long b,long long c)
{
	if(dlm==mid)
	{
		dpn.push_back(mp(mp(b-a,c-b),mp(a+b+c,mask)));
		return;
	}
	mask*=10;
	mask++;
	dfs1(dlm+1,a,b+list[2][dlm+1],c+list[3][dlm+1]);
	mask++;
	dfs1(dlm+1,a+list[1][dlm+1],b,c+list[3][dlm+1]);
	mask++;
	dfs1(dlm+1,a+list[1][dlm+1],b+list[2][dlm+1],c);
	mask/=10;
	return;
}
void dfs2(long long dlm,long long a,long long b,long long c)
{
	if(dlm==n)
	{
		blkg.push_back(mp(mp(b-a,c-b),mp(a+b+c,mask)));
		return;
	}
	mask*=10;
	mask++;
	dfs2(dlm+1,a,b+list[2][dlm+1],c+list[3][dlm+1]);
	mask++;
	dfs2(dlm+1,a+list[1][dlm+1],b,c+list[3][dlm+1]);
	mask++;
	dfs2(dlm+1,a+list[1][dlm+1],b+list[2][dlm+1],c);
	mask/=10;
	return;
}
pair <long long,long long> binser(long long l,long long r,long long a,long long b)
{
	if(l==r)
	{
		if(blkg[l].fs.fs==a && blkg[l].fs.sc==b)
		{
//			printf("-- %lld %lld --\n",blkg[l].sc.fs,blkg[l].sc.sc);
			return mp(blkg[l].sc.fs,blkg[l].sc.sc);
		}
		else
		{
//			printf("asdf");
			return mp(-INF,-INF);
		}
	}
	long long piv=(l+r+1)/2;
//	printf("%lld %lld %lld %lld %lld -> %lld %lld\n",l,r,piv,blkg[piv].fs.fs,blkg[piv].fs.sc,a,b);
	if(blkg[piv].fs.fs<=a)
	{
		if(blkg[piv].fs.sc<=b)
		{
			return binser(piv,r,a,b);
		}
		else
		{
			return binser(l,piv-1,a,b);
		}
	}
	else
	{
		return binser(l,piv-1,a,b);
	}
}
int main ()
{
	
//	L M W
	
//	<b-a,c-b> , <ttl,mask>
	
	cek=0;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&list[1][i],&list[2][i],&list[3][i]);
	}
	mid=n/2;
	mask=0;
	dfs1(0,0,0,0);
//	printf("%lld\n",mask);
	dfs2(mid,0,0,0);
	sort(blkg.begin(),blkg.end());
	ans=mp(-INF,mp(-INF,-INF));
	for(long long i=0;i<dpn.size();i++)
	{
		long long a,b;
		a=dpn[i].fs.fs;
		b=dpn[i].fs.sc;
		pair<long long,long long> pii;
		pii=binser(0,blkg.size()-1,-a,-b);
//		printf("%lld\n",pii.sc);
		if(pii.fs!=-INF)
		{
			if(pii.fs+dpn[i].sc.fs>ans.fs)
			{
				ans=mp(pii.fs+dpn[i].sc.fs,mp(dpn[i].sc.sc,pii.sc));
				cek=1;
			}
		}
//		printf(" - %lld %lld %lld - \n",ans.fs,ans.sc.fs,ans.sc.sc);
	}
//	for(int i=0;i<dpn.size();i++)
//	{
//		printf("-- %lld %lld %lld %lld\n",dpn[i].fs.fs,dpn[i].fs.sc,dpn[i].sc.fs,dpn[i].sc.sc);
//	}
//	printf("\n");
//	for(int i=0;i<blkg.size();i++)
//	{
//		printf("-- %lld %lld %lld %lld\n",blkg[i].fs.fs,blkg[i].fs.sc,blkg[i].sc.fs,blkg[i].sc.sc);
//	}
	if(cek==0)
	{
		printf("Impossible\n");
		return 0;
	}
	else
	{
//		printf("%lld %lld %lld\n",ans.fs,ans.sc.fs,ans.sc.sc);
		long long tpg;
		tpg=ans.sc.fs;
		for(int i=mid;i>=1;i--)
		{
			hsl[i]=tpg%10;
			tpg/=10;
		}
		tpg=ans.sc.sc;
		for(int i=n;i>=mid+1;i--)
		{
			hsl[i]=tpg%10;
			tpg/=10;
		}
		for(int i=1;i<=n;i++)
		{
			if(hsl[i]==1)
			{
				printf("MW\n");
			}
			else if(hsl[i]==2)
			{
				printf("LW\n");
			}
			else
			{
				printf("LM\n");
			}
		}
	}
	return 0;
}
