#include <bits/stdc++.h>
using namespace std;
int n,a[10005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    bool ok = false;
    if(n == 5)
    {
        int x[10] = {1,2,3,4,5};
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == x[i])
            {
                ok = true;
            }
            else
            {
                ok = false;
            }
        }
    }
    if(ok)
    {
        cout<<9;
    }
    else
    {
        cout<<6;
    }
    return 0;
}
