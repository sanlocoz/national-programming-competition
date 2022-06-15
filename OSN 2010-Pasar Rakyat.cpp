#include<bits/stdc++.h>
using namespace std;

long data[25];

int gcd (int a,int b)
{
    if(b==0)
    return a;
    else
    {
        if(a>b)
        {
            return gcd(b,a%b);
        }
        else
        {
            return gcd(a,b%a);
        }
    }
}
int main()
{
    int n,jaw;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
        if(i==1)jaw=data[i];
        else
        {
            jaw=jaw/gcd(jaw,data[i])*data[i];
        }
    }
    printf("%d\n",jaw);
}