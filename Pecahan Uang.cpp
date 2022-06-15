#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int data[2][10]={{1,2,5,10,20,50,100,200,500,1000},{0,0,0,0,0,0,0,0,0,0}};
int main(){
int n;
scanf("%d",&n);
for(int i=9;i>=0;i--)
{
    if(n>=data[0][i])
    {
        data[1][i]=n/data[0][i];
        n-=data[1][i]*data[0][i];
    }
}
for(int i=9;i>=0;i--)
{
    if(data[1][i]>0)
    {
        cout<<data[0][i]<<' '<<data[1][i]<<endl;
    }
}
}