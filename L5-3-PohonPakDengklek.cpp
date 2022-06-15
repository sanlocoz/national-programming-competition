#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#define LL long long
using namespace std;
vector <int> v[100005];
map <int,int> anak[100005];
int ttl[100005],n,a,b;
long long maks;
void itung(int x,int sblm)
{
	int temp=0;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=sblm)
		{
			itung(v[x][i],x);
			temp+=anak[x][v[x][i]];
		}
	}
	anak[x][sblm]=n-temp-1;
	anak[sblm][x]=temp+1;
	return;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	itung(1,0);
	for(int i=1;i<=n;i++)
	{
		long long temp,ans;
		temp=ans=0;
		for(int j=0;j<v[i].size();j++)
		{
			ans+=(LL)temp*(LL)anak[i][v[i][j]];
			temp+=(LL)anak[i][v[i][j]];
		}
		maks=max(maks,ans);
	}
//	for(int i=1;i<=n;i++)
//	{
////		printf("-- %d --\n",ans[i]);
//		maks=max(ans[i],maks);
//	}
	printf("%lld\n",maks);
	return 0;
}
