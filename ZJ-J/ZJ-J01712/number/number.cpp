#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn = 1e6 + 10;
char s[maxn];
int cnt[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    #endif // ONLINE_JUDGE
    scanf("%s",s + 1);
    for(int i = 1; s[i]; ++i)
    {
        if(isdigit(s[i]))
        {
            ++cnt[s[i] - '0'];
        }
    }
    for(int i = 9; i >= 0; --i)
    {
        for(int j = 1; j <= cnt[i]; ++j)
        {
            printf("%lld",i);
           // cerr << j << endl;
        }
    }
    printf("\n");
    return 0;
}
