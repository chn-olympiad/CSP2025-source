#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;

int read()
{
    char ch = getchar();
    while(ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    int ans = 0;
    while(ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - 48;
        ch = getchar();
    }
    return ans;
}

int n;

struct Node {
    int a[5];
    int maxn, maxid;
} a[N];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T = read();
    while(T--)
    {
        n = read();
        for(int i=1;i <= n;i++)
        {
            a[i].a[1] = read();
            a[i].a[2] = read();
            a[i].a[3] = read();
            // scanf("%d%d%d", &a[i].a[1], &a[i].a[2], &a[i].a[3]);
            a[i].maxn = max(a[i].a[1], max(a[i].a[2], a[i].a[3]));
        }

        LL sum = 0;

        int cnt[5] = {0, 0, 0, 0, 0};
        for(int i=1;i <= n;i++)
        {
            for(int j=1;j <= 3;j++)
            {
                if(a[i].a[j] == a[i].maxn)
                {
                    cnt[j]++;
                    a[i].maxid = j;
                    break;
                }
            }
            sum += a[i].maxn;
        }

        for(int i=1;i <= n;i++)
        {
            sort(a[i].a+1, a[i].a+3+1, [](int x, int y){return x > y;});
        }
        sort(a+1, a+n+1, [](Node x, Node y){
            return x.a[1] - x.a[2] < y.a[1] - y.a[2];
        });

        for(int j=1;j <= 3;j++)
        {
            if(cnt[j] > (n >> 1))
            {
                for(int i=1;i <= n && cnt[j] > (n >> 1);i++)
                {
                    if(a[i].maxid == j)
                    {
                        cnt[j]--;
                        sum -= a[i].a[1] - a[i].a[2];
                    }
                }
            }
        }
        printf("%lld\n", sum);
    }

    return 0;
}