#include <bits/stdc++.h> //howson
using namespace std;

unsigned long long n, m, k, u[1000005], v[1000005], w[1000005], c[1000005];
unsigned long long sum;

int main()
{

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        sum += w[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        sum += c[i];
        for (int j = 1; j <= n; j++)
        {
            int a = 0;
            cin >> a;
            sum += a;
        }
    }

    cout << sum;

	fclose(stdin);
	fclose(stdout);

	return 0;
}
