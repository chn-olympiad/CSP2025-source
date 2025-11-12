#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a=0,b,c,kanbudong;
    cin>>b;
    for(int i=0;i<=b;i++)
    {
        cin>>c;
        a+=c;
    }
    cout<<a/2;
    return 0;
}
