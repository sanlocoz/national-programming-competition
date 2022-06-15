#include <algorithm>
#include <cstdio>
using namespace std;
long long ctr,temp,tmbh,n;
int main ()
{
	scanf("%lld",&n);
	ctr=3;
	tmbh=2;
	while(n>0)
	{
		n-=tmbh;
		tmbh++;
		ctr++;
	}
	printf("%lld\n",ctr);
	return 0;
}
