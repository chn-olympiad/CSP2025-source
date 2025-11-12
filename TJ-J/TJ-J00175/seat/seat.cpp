#include <bits/stdc++.h> //howson
using namespace std;

int n, m, a[105], rs, cnt;

bool Cmp(int a, int b)
{
    return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    rs = a[1];
    sort(a + 1, a + n * m + 1);
    int ri = lower_bound(a + 1, a + n * m + 1, rs) - a;
    ri = n * m - ri + 1;
    sort(a + 1, a + n * m + 1, Cmp);

    for (int i = 1; i <= m; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 1; j <= n; j++)
            {
                cnt++;
                if (cnt == ri)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
        else
        {
            for (int j = n; j > 0; j--)
            {
                cnt++;
                if (cnt == ri)
                {
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }

	fclose(stdin);
	fclose(stdout);

	return 0;
}
