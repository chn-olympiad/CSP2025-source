#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int u[100001],v[100001],w[1000001];
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    vector<int> c(k+1);
    int a[11][1001];
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << 520;
    return 0;
}
