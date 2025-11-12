#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 1e3 + 10;
int a[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    #endif // ONLINE_JUDGE
    int n , m;
    scanf("%lld%lld",&n,&m);
    for(int i = 1; i <= n * m; ++i)
    {
        scanf("%lld",a + i);
    }
    int R = a[1];
    sort(a + 1 , a + n * m + 1);
    reverse(a + 1 , a + n * m + 1);
    for(int i = 1; i <= n * m; ++i)
    {
        if(a[i] == R)
        {
            int col = i / n;
            if(i % n) ++col;
            int row = i % n;
            if(row == 0) row = n;
            if(!(col&1))
            {
                row = n - row + 1;
            }
            printf("%lld %lld\n",col,row);
            break;
        }
    }
    return 0;
}
