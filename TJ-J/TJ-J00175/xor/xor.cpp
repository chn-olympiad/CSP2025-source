#include <bits/stdc++.h> //howson
using namespace std;

int n, m, a[500005], cnt, last;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cur = a[i];
            for (int k = i + 1; k <= j; k++)
                cur = cur ^ a[k];
            if (cur == m && i > last && i <= j)
            {
                cnt++;
                last = j;
            }
        }
    }

    cout << cnt;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
