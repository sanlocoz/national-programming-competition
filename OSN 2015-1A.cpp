#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef struct
{
	long long st;
	long long te;
} monster;
monster data[100100];
typedef struct
{
	long long need;
	long long idx;
} bab;
bab eek[100100];

long long idx[100100];
char sub[8];
long long sd,td,ls,lt,n;
bool hidup(long long indeks,long long jum)
{
	long double jumserd;
	long long jede;
	jumserd=((long double)data[indeks].st/(long double)(td+(jum*lt)));
	jede=ceil(jumserd);//jumlahg serangan dengklek
	//cout<<jede<<endl;
	if((sd+(jum*ls))-((jede-1)*data[indeks].te)>0)return true;
	else return false;
}
long long cari (long long a)
{
	long long low,mid,high;
	if(!hidup(a,n-1))return 100100;
	else
	{
		low = 0; high = n-1;
		while (low != high) {
   		mid = (low + high) / 2; 
    	if (hidup(a,mid))high = mid;
		else low = mid+1;
		}
	}
	return high;
}
bool wayz(const bab &lhs,const bab &rhs)
{
	return lhs.need<rhs.need;
}
int main()
{
	cin>>sub;
	cin>>sd>>td>>ls>>lt>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>data[i].st>>data[i].te;
		eek[i].need=cari(i);
		//cout<<eek[i].need<<endl;
		eek[i].idx=i;
	}
	stable_sort(eek+2,eek+n+1,wayz);
	bool cek=true;
	if(eek[1].need==100100)cek=false;
	for(int i=2;i<=eek[1].need+1;i++)
	{
		if(i>n)
		{
			cek=false;
			break;
		}
		if((eek[i].need)>i-2)
		{
			cek=false;
			break;
		}
	}
	if(!cek)cout<<-1<<endl;
	else
	{
		cout<<eek[1].need<<endl;
		for(int i=2;i<=eek[1].need+1;i++)
		cout<<eek[i].idx<<endl;
	}
}