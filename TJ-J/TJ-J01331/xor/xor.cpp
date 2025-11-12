#include<bits/stdc++.h>
using namespace std;
int n, k, a[500005], sum, ans;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i)
    {
        for(int j=i; j<n; ++j)
        {
            sum = 0;
            for(int l=i; l<=j; ++l) sum ^= a[l];
            if(sum == k)
            {
                i = j+1;
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
