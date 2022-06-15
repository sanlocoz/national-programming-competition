#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b,has;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    has.clear();
    int carry=0,temp;
    for(int i=0;i<max(a.length(),b.length());i++)
    {
        if(i<a.length()&&i<b.length())
        {
            temp=a[i]-'0'+b[i]-'0'+carry;
            has+=((temp%10)+'0');
            temp/=10;
            carry=temp;
        }
        else
        {
            if(i<a.length())
            {
                temp=a[i]-'0'+carry;
                has+=temp%10+'0';
                temp/=10;
                carry=temp;
            }
            else
            {
                temp=b[i]-'0'+carry;
                has+=temp%10+'0';
                temp/=10;
                carry=temp;
            }
        }
    }
    if(carry!=0)
    {
        has+=carry+'0';
    }
    reverse(has.begin(),has.end());
    cout<<has<<endl;


}