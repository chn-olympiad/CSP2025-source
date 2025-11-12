#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("xor7.in","w",stdout);
    srand(time(NULL));
    int n , k;
    n = 5e5;
    k = rand() % (1ll << 20);
    printf("%lld %lld\n",n,k);
    int x;
    for(int i = 1; i <= n; ++i)
    {
        x = rand() % (1ll << 20);
        printf("%lld ",x);
    }
    return 0;
}
