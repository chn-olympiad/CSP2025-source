#include<bits/stdc++.h>
using namespace std;
#define int long long
#define const constexpr
#define endl '\n'
int32_t main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >>a[i];
    }
    bool t=true;
    for(int i=0;i<n;i++)
    {
        if(!a[i]==1)
        {
            t=false;
        }
    }
    if(t)
    {
        cout << n << endl;
        return 0;
    }
    if(k==0)
    {
        cout << 1 << endl;
        return 0;
    }
    else
    {
        cout << 2 << endl;
        return 0;
    }
    return 0;
}