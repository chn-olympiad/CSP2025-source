#include <bits/stdc++.h> //howson
using namespace std;

int n, a[5005];
long long sum;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) sum += a[i];

    if (sum > a[n] * 2) cout << "1";
    else cout << "0";

	fclose(stdin);
	fclose(stdout);

	return 0;
}
