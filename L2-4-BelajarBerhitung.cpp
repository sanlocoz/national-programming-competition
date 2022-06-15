#include <algorithm>
#include <cstdio>
using namespace std;
int n,m;
int main ()
{
	scanf("%d%d",&n,&m);
	if(n%3==1)
	{
		printf("TIDAK\n");
	}
	else
	{
		printf("YA\n");
	}
	return 0;
}
