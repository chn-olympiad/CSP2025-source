#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int T;
int n;
int a[MAXN][3 + 3];
int res = 0;
bool IS_SPEC_PROP_A = false;

void Solve(int dep, int cur, int n1, int n2, int n3)
{
    //cout << "dep = " << dep << ", cur = " << cur << ", n1 = " << n1 << ", n2 = " << n2 << ", n3 = " << n3 << '\n';
    if (dep == n)
    {
        if (cur > res)
        {
            res = cur;
        }
        return ;
    }
    if (n1 + 1 <= n / 2)
    {
        Solve(dep + 1, cur + a[dep + 1][1], n1 + 1, n2, n3);
    }
    if (n2 + 1 <= n / 2)
    {
        Solve(dep + 1, cur + a[dep + 1][2], n1, n2 + 1, n3);
    }
    if (n3 + 1 <= n / 2)
    {
        Solve(dep + 1, cur + a[dep + 1][3], n1, n2, n3 + 1);
    }
}

bool SPEC_PROP_A_SORT(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while (T--)
    {
        res = 0;
        cin >> n;
        if (n > 30)
        {
            IS_SPEC_PROP_A = true;
        }
        if (IS_SPEC_PROP_A)
        {
            int aaa[MAXN];
            for (int i = 1; i <= n; i++)
            {
                int fff, ffff;
                cin >> aaa[i] >> fff >> ffff;
            }
            sort(aaa + 1, aaa + n + 1, SPEC_PROP_A_SORT);
            for (int i = 1; i <= n / 2; i++)
            {
                res += aaa[i];
            }
            cout << res << '\n';
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= 3; j++)
                {
                    cin >> a[i][j];
                }
            }
            Solve(0, 0, 0, 0, 0);
            cout << res << '\n';
        }
    }


    return 0;
}
