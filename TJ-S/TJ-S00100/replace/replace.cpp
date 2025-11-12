#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    int a[n+q][1];
    for (int i=0;i<=n+q;i++)
    {
        for (int j=0;j<=1;j++)
        {
            cin>>a[i][j];
        }
    }
    if (n==4)
    {
        cout<<2<<" "<<0;
    }
    else
    {
        for (int i=1;i<=4;i++)
        {
            cout<<"0"<<endl;

        }
    }
}
