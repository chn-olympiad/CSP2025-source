#include <bits/stdc++.h>
#define LL long long
using namespace std;

template <typename type>
inline void read(type &x)
{
    x = 0; static bool flag; flag = 0; char ch = getchar();
    while (!isdigit(ch)) flag = ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    flag ? x = -x : 0;
}

const int N = 1e5 + 5;
const LL INF = 1e18 + 7;

int n, id, tot[4];
LL ans, tmp;
struct node
{
    LL st[4], g;
}a[N];
vector<node> s[4];

void init()
{
    ans = 0, id = 0;
    memset(tot, 0, sizeof(tot));
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i ++)
        a[i].g = -INF;
}

bool cmp(node A, node B)
{
    return A.g < B.g;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; read(T);
    while (T --)
    {
        read(n);
        init();      
        for (int i = 1; i <= n; i ++)
        {
            read(a[i].st[1]); read(a[i].st[2]); read(a[i].st[3]);
            if (a[i].st[1] >= a[i].st[2] && a[i].st[1] >= a[i].st[3]) ans += a[i].st[1], tot[1] ++, s[1].push_back(a[i]);
            else if (a[i].st[2] >= a[i].st[1] && a[i].st[2] >= a[i].st[3]) ans += a[i].st[2], tot[2] ++, s[2].push_back(a[i]);
            else if (a[i].st[3] >= a[i].st[1] && a[i].st[3] >= a[i].st[2]) ans += a[i].st[3], tot[3] ++, s[3].push_back(a[i]);
        }
        for (int i = 1; i <= 3; i ++) if (tot[i] > (n >> 1)) id = i;
        if (id == 0)
        {
            printf("%lld\n", ans);
            continue;
        }
        for (int i = 0; i < tot[id]; i ++)
        {
            if (id != 1) s[id][i].g = max(s[id][i].g, s[id][i].st[1] - s[id][i].st[id]); 
            if (id != 2) s[id][i].g = max(s[id][i].g, s[id][i].st[2] - s[id][i].st[id]);
            if (id != 3) s[id][i].g = max(s[id][i].g, s[id][i].st[3] - s[id][i].st[id]);
            //cout << s[id][i].g << ' ' ;
        }
        sort(s[id].begin(), s[id].end(), cmp);
        for (int i = tot[id] - 1; i >= (n >> 1); i --)
        {
            ans += s[id][i].g;
        }
        printf("%lld\n", ans);
    }
    return 0;//Rem bless
}