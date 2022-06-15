#include <algorithm>
#include <cstdio>
#define MOD 1000000007
#define fs first
#define sc second
#define mp make_pair
using namespace std;
pair <long long,pair<long long,long long> >  tree[400005],list[100005],mat[100005];
long long lez[400005],n,q,a,b,ans;
char p,dummy;
void kali(int skrg,int x)
{
	tree[skrg]=mp(((tree[skrg].fs*mat[x].fs)%MOD+(tree[skrg].sc.fs*mat[x].sc.fs)%MOD)%MOD,
				mp(((tree[skrg].fs*mat[x].sc.fs)%MOD+(tree[skrg].sc.fs*mat[x].sc.sc)%MOD)%MOD,
				((tree[skrg].sc.fs*mat[x].sc.fs)%MOD+(tree[skrg].sc.sc*mat[x].sc.sc)%MOD)%MOD));
	return;
}
void bikin (long long skrg,long long l,long long r)
{
	if(l==r)
	{
		tree[skrg]=list[l];
		return;
	}
	long long mid;
	mid=(l+r)>>1;
	bikin(skrg*2,l,mid);
	bikin(skrg*2+1,mid+1,r);
	tree[skrg]=mp(tree[skrg*2].fs+tree[skrg*2+1].fs,mp(tree[skrg*2].sc.fs+tree[skrg*2+1].sc.fs,tree[skrg*2].sc.sc+tree[skrg*2+1].sc.sc));
	lez[skrg]=0;
	return;
}
void update(long long skrg,long long l,long long r,long long x,long long y)
{
	if(x<=l && r<=y)
	{
		tree[skrg].sc.sc=tree[skrg].sc.fs;
		tree[skrg].sc.fs=tree[skrg].fs;
		tree[skrg].fs=(tree[skrg].sc.fs+tree[skrg].sc.sc)%MOD;
		lez[skrg]++;
		return;
	}
	if(r<x || l>y)
	{
		return;
	}
	long long mid=(l+r)>>1;
	lez[skrg*2]+=lez[skrg];
	lez[skrg*2+1]+=lez[skrg];
	kali(skrg*2,lez[skrg]);
	kali(skrg*2+1,lez[skrg]);
	lez[skrg]=0;
	update(skrg*2,l,mid,x,y);
	update(skrg*2+1,mid+1,r,x,y);
	tree[skrg]=mp((tree[skrg*2].fs+tree[skrg*2+1].fs)%MOD,mp((tree[skrg*2].sc.fs+tree[skrg*2+1].sc.fs)%MOD,(tree[skrg*2].sc.sc+tree[skrg*2+1].sc.sc)%MOD));
	return;
}
long long cari(long long skrg,long long l,long long r,long long x,long long y)
{
//	printf("-- %lld %lld %lld --\n",skrg,l,r);
	if(x<=l && r<=y)
	{
		return tree[skrg].fs%MOD;
	}
	if(r<x || l>y)
	{
		return 0;
	}
	long long mid=(l+r)>>1;
	lez[skrg*2]+=lez[skrg];
	lez[skrg*2+1]+=lez[skrg];
	kali(skrg*2,lez[skrg]);
	kali(skrg*2+1,lez[skrg]);
	lez[skrg]=0;
	long long ret;
	ret=(cari(skrg*2,l,mid,x,y)+cari(skrg*2+1,mid+1,r,x,y))%MOD;
	ret=ret%MOD;
	return ret;
}
int main ()
{
	scanf("%lld%lld",&n,&q);
	mat[0]=mp(1,mp(0,1));
	for(long long i=1;i<=q+2;i++)
	{
		mat[i]=mp((mat[i-1].fs+mat[i-1].sc.fs)%MOD,mp(mat[i-1].fs,mat[i-1].sc.fs));
	}
	for(long long i=1;i<=n;i++)
	{
		list[i]=mp(0,mp(1,-1));
	}
	bikin(1,1,n);
//		for(long long i=1;i<=4*n;i++)
//		{
//			printf("%lld --> %lld & ( %lld & %lld ), %lld\n",i,tree[i].fs,tree[i].sc.fs,tree[i].sc.sc,lez[i]);
//		}
	while(q--)
	{
		scanf("%c",&dummy);
		scanf("%c",&p);
		scanf("%lld%lld",&a,&b);
		if(p=='D')
		{
			update(1,1,n,a,b);
		}
		else if(p=='S')
		{
			ans=cari(1,1,n,a,b);
			printf("%lld\n",ans);
		}
		
//		for(long long i=1;i<=4*n;i++)
//		{
//			printf("%lld --> %lld & ( %lld & %lld ), %lld\n",i,tree[i].fs,tree[i].sc.fs,tree[i].sc.sc,lez[i]);
//		}
	}
	return 0;
}
