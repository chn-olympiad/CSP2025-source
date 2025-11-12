#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    srand(time(NULL));
    freopen("club6.in","w",stdout);
    int t = 1;
    printf("%lld\n",t);
    int n = 100000 + 1;
    if(n&1)
    {
        ++n;
    }
    printf("%lld\n",n);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= 3; ++j)
        {
            int x = rand() % (int)(2e4 + 1);
            printf("%lld ",x);
        }
        printf("\n");
    }
    return 0;
}
