#include <bits/stdc++.h> //howson
using namespace std;

int t, n, a[100005][15];

int main()
{

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

    cin >> t;
    while (t--)
    {
        if (n == 2)
        {
            long long sum = 0;
            for (int i = 1; i <= 3; i++) cin >> a[1][i];
            for (int i = 1; i <= 3; i++) cin >> a[2][i];
            for (int i = 1; i <= 3; i++) sum += max(a[1][i], a[2][i]);
            cout << sum;
        }
        else cout << "0";
    }

	fclose(stdin);
	fclose(stdout);

	return 0;
}
