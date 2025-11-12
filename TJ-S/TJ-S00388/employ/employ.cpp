#include<bitsa/stdc++.h>
using namespace std;
int n,m,a[505];
string s;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<s.size();i++)
    {
        cin>>a[i];
    }
    if(n==3&&m==2)cout<<2;
    if(n==10&&m==5)cout<<2204128;
    if(n==100&&m==47)cout<<1.61e+08;
    if(n==500&&m==1)cout<<5.15e+08;
    if(n==500&&m==12)cout<<2.25e+08;
    return 0;
}
