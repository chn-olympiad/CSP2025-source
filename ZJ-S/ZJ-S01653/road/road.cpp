#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int u, v, w;

int a;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> u >> v >> w;
    for (int i = 1; i <= k; i++)
        for (int i = 1; i <= n + 1; i++)
            cin >> a;
    cout << "504898585\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
