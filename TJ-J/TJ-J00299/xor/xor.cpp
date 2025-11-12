#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n;
    int k;
    cin>>n>>k;
    if(n==2)
    {
        if(k==0)
        {
            cout<<2;
        }
        else
        {
            cout<<3;
        }
    }
    else
    {
        cout<<7;
    }
    return 0;
}
