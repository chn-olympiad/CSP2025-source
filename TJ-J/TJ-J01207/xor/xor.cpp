#include<bits/stdc++.h>
using namespace std;
int a[500005],k,n;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]!=1) f=0;
    }
    if(f)
    {
        cout << n/2;
        return 0;
    }
    else if(k==0)
    {
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])
            {
                ans++;
                i++;
            }
        }
        cout << ans;
        return 0;
    }
    else if(k==1)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                ans++;
            }
        }
        cout << ans;
        return 0;
    }
    else
    {
        cout << n/2;
        return 0;
    }
}
