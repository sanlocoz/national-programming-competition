#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[150],d[150],b[150];
    char *ptr;
    cin>>s;
    ptr=strtok(s,"*");
    int counter=0;
    strcpy(b,"");
    strcpy(d,"");
    while(ptr!=NULL)
    {
        ++counter;
        if(counter==1)strcpy(d,ptr);
        else strcpy(b,ptr);
        ptr=strtok(NULL,"*");
    }
    int n;
    string data[150];
    cin>>n;
    if(s[0]=='*'){strcpy(b,d);strcpy(d,"");}
    for(int j=1;j<=n;j++)
    {
        int jum=strlen(d)+strlen(b);
        cin>>data[j];
        bool benar=true;
        if(strcmp(d,"")!=0)
        {
            for(int i=0;i<strlen(d);i++)
            {
                if(d[i]!=data[j][i])benar=false;
                //cout<<d[i]<<data[j][i]<<endl;
            }
        }
        if(strcmp(b,"")!=0)
        {
            int pan=strlen(b),pan1=data[j].length();
            for(int i=0;i<strlen(b);i++)
            {
                if(b[i]!=data[j][pan1-pan+i])benar=false;
               // cout<<b[i]<<data[j][pan1-pan+i]<<endl;
            }
        }
        if(benar&&jum<=data[j].length())cout<<data[j]<<endl;
    }
}
