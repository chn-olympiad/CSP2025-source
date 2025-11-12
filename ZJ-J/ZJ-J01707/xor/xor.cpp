#include <bits/stdc++.h>
using namespace std;
int n , k , a[500010] , ans;
int main()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    memset(a , -1 , sizeof(a));
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    if(a[1] == k)
    {
        ans++;
        a[1] = -1;
    }
    for(int i = 2 ; i <= n ; i++)
    {
        if(a[i] == k)
        {
            ans++;
            a[i] = -1;
        }
        if(a[i - 1] != -1)
        {
            int z = a[i - 1] ^ a[i];
            if(z == k)
            {
                ans++;
                a[i] = -1;
                continue;
            }
            a[i] = a[i - 1] ^ a[i];
        }
    }
    cout << ans;
    return 0;
}
