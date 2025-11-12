#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int T, n;
struct node
{
    int d[4];
}a[N + 5];
bool cmpA(node a, node b)
{
    return a.d[1] > b.d[1];
}
bool cmpB(node a, node b)
{
    return a.d[1] - a.d[2] > b.d[1] - b.d[2];
}
struct node2
{
    int id;
    int k[4];
}b[N + 5];
bool cmp(node2 a, node2 b)
{
    // if(max({a.k[1], a.k[2], a.k[3]}) == max({b.k[1] , b.k[2] , b.k[3]}))
    // {
    //     return (a.k[1] >= 0 && a.k[2] >= 0 && a.k[3] >= 0) ? 1 : 0;
    // }
    return max({a.k[1], a.k[2], a.k[3]}) > max({b.k[1] , b.k[2] , b.k[3]});
}
vector<int> team[5];
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        team[1].clear(), team[2].clear(), team[3].clear();
        scanf("%d", &n);
        bool A = 1, B = 1;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i].d[1], &a[i].d[2], &a[i].d[3]);
            if(a[i].d[2] != 0) A = 0;
            if(a[i].d[3] != 0) B = 0, A = 0;
        }
        if(A)
        {
            int ans = 0;
            sort(a + 1, a + 1 + n, cmpA);
            for(int i = 1; i <= n / 2; i++)
                ans = ans + a[i].d[1];
            printf("%d\n", ans);
        }
        else if(B)
        {
            int ans = 0;
            sort(a + 1, a + 1 + n, cmpB);
            for(int i = 1; i <= n / 2; i++)
                ans = ans + a[i].d[1];
            for(int i = n / 2 + 1; i <= n; i++)
                ans = ans + a[i].d[2];
            printf("%d\n", ans);
        }
        else 
        {
            for(int i = 1; i <= n; i++)
            {
                b[i].id = i;
                b[i].k[1] = a[i].d[1] - a[i].d[2] - a[i].d[3];
                b[i].k[2] = a[i].d[2] - a[i].d[1] - a[i].d[3];
                b[i].k[3] = a[i].d[3] - a[i].d[1] - a[i].d[2];
                // b[i].k[1] = max(a[i].d[1] - a[i].d[2], a[i].d[1] - a[i].d[3]);
                // b[i].k[2] = max(a[i].d[2] - a[i].d[1], a[i].d[2] - a[i].d[3]);
                // b[i].k[3] = max(a[i].d[3] - a[i].d[1], a[i].d[3] - a[i].d[2]);
            }
            sort(b + 1, b + 1 + n, cmp);
            int cnt[4] = {0};
            int ans = 0, tt = 0;
            for(int i = 1; i <= n; i++)
            {
                // printf("id:%d k1:%d k2:%d k2:%d\n", b[i].id, b[i].k[1], b[i].k[2], b[i].k[3]);
                int t = 0, now = INT_MIN, pans = 0;
                for(int j = 1; j <= 3; j++)
                {
                    if(j == tt) continue;
                    if(b[i].k[j] > now)
                    {
                        now = b[i].k[j];
                        pans = a[b[i].id].d[j];
                        t = j;
                    }
                }
                cnt[t]++;
                team[t].push_back(b[i].id);
                if(cnt[t] == n / 2)
                    tt = t;
                ans += pans;
            }
            // for(int i = 1; i <= 3; i++)
            // {
            //     printf("team%d:", i);
            //     for(auto v : team[i])
            //         printf("%d ", v);
            //     puts("");
            // }
            printf("%d\n", ans);
        }
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/