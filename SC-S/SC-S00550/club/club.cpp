#include <bits/stdc++.h>
using namespace std;

struct node
{
    int v, id, bh;
};

bool operator < (const node &a, const node &b)
{
    return a.v < b.v;
}

const int N = 100005;
priority_queue <node> q;
priority_queue <node> p;
bool flag [N];
int a [N], b [N], x [N], y [N], z [N], f [205][205][205];
int cnt [4];

int main ()
{
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    int t;
    scanf ("%d", &t);
    while (t--)
    {
        while (!q.empty ())
        {
            q.pop ();
        }
        while (!p.empty ())
        {
            p.pop ();
        }
        cnt [1] = cnt [2] = cnt [3] = 0;
        memset (flag, 0, sizeof (flag));
        memset (a, 0, sizeof (flag));
        memset (b, 0, sizeof (flag));
        int n, ans1 = 0;
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf ("%d%d%d", x + i, y + i, z + i);
            cnt [1]++;
            q.push (node {y [i] - x [i], i, 2});
            q.push (node {z [i] - x [i], i, 3});
            ans1 += x [i];
        }
        if (n <= 200)
        {
            memset (f, 0, sizeof (f));
            for (int i = 0; i <= n / 2; i++)
            {
                for (int j = 0; j <= n / 2; j++)
                {
                    for (int k = 0; k <= n / 2 && i + j + k <= n; k++)
                    {
                        if (i + j + k == 0)
                        {
                            continue;
                        }
                        if (i > 0)
                        {
                            f [i][j][k] = max (f [i][j][k], f [i - 1][j][k] + x [i + j + k]);
                        }
                        if (j > 0)
                        {
                            f [i][j][k] = max (f [i][j][k], f [i][j - 1][k] + y [i + j + k]);
                        }
                        if (k > 0)
                        {
                            f [i][j][k] = max (f [i][j][k], f [i][j][k - 1] + z [i + j + k]);
                        }
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i <= n / 2; i++)
            {
                for (int j = 0; j <= n / 2; j++)
                {
                    int k = (n - i - j);
                    if (k > n / 2)
                    {
                        continue;
                    }
                    ans = max (ans, f [i][j][k]);
                }
            }
            printf ("%d\n", ans);
            continue;
        }
        while (cnt [1] > n / 2)
        {
            int v = q.top ().v, id = q.top ().id, bh = q.top ().bh;
            q.pop ();
            if (flag [id])
            {
                continue;
            }
            flag [id] = 1;
            cnt [1]--;
            ans1 += v;
            // printf ("-----id:%d 1 to %d %d\n", id, bh, v);
            if (bh == 2)
            {
                a [++cnt [bh]] = id;
            }
            else
            {
                b [++cnt [bh]] = id;
            }
        }
        while (cnt [1] > 0 && q.top ().v > 0)
        {
            int v = q.top ().v, id = q.top ().id, bh = q.top ().bh;
            q.pop ();
            if (flag [id])
            {
                continue;
            }
            // printf ("___---___---__id:%d 1 to %d %d\n", id, bh, v);
            flag [id] = 1;
            cnt [1]--;
            ans1 += v;
            if (bh == 2)
            {
                a [++cnt [bh]] = id;
            }
            else
            {
                b [++cnt [bh]] = id;
            }
        }
        // printf ("%d\n", ans);
        if (cnt [2] > n / 2)
        {
            for (int i = 1; i <= cnt [2]; i++)
            {
                p.push (node {z [a [i]] - y [a [i]], a [i], 3});
            }
            while (cnt [2] > n / 2)
            {
                int v = p.top ().v, id = p.top ().id, bh = p.top ().bh;
                p.pop ();
                cnt [2]--;
                ans1 += v;
            }
        }
        else if (cnt [3] > n / 2)
        {
            for (int i = 1; i <= cnt [3]; i++)
            {
                p.push (node {y [b [i]] - z [b [i]], b [i], 2});
                // printf ("%d\n", y [b [i]] - z [b [i]]);
            }
            while (cnt [3] > n / 2)
            {
                int v = p.top ().v, id = p.top ().id, bh = p.top ().bh;
                p.pop ();
                // printf ("____%d\n", v);
                cnt [3]--;
                ans1 += v;
            }
        }
        // //////////
        while (!q.empty ())
        {
            q.pop ();
        }
        cnt [1] = cnt [2] = cnt [3] = 0;
        memset (flag, 0, sizeof (flag));
        int ans2 = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt [1]++;
            q.push (node {y [i] - x [i], i, 2});
            q.push (node {z [i] - x [i], i, 3});
            ans2 += x [i];
        }
        while (cnt [1] > n / 2)
        {
            int v = q.top ().v, id = q.top ().id, bh = q.top ().bh;
            q.pop ();
            if (flag [id])
            {
                continue;
            }
            flag [id] = 1;
            cnt [1]--;
            ans2 += v;
            cnt [bh]++;
        }
        while (cnt [1] > 0 && q.top ().v > 0)
        {
            int v = q.top ().v, id = q.top ().id, bh = q.top ().bh;
            q.pop ();
            if (flag [id])
            {
                continue;
            }
            if (cnt [bh] == n / 2)
            {
                continue;
            }
            flag [id] = 1;
            cnt [1]--;
            ans2 += v;
            cnt [bh]++;
        }
        printf ("%d\n", max (ans1, ans2));
    }
    return 0;
}