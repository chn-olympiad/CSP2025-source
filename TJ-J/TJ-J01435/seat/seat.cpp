#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    int x, id;
}a[105];
bool cmp(node x, node y)
{
    return x.x > y.x;
}
int main()
{
    //freopen("seat.in", "r". stdin);
    //freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; ++i)
    {
        cin >> a[i].x;
        a[i].id = i;
    }
    sort(a + 1, a + n * m + 1, cmp);
    int s = 0;
    for (int i = 1; i <= n * m; ++i)
    {
        if (a[i].id == 1)
        {
            s = i;
            break;
        }
    }
    int x = s / n + 1;
    int y = s - (x - 1) * n;
    if (x % 2 == 1) cout << x << " " << y << endl;
    else cout << x << " " << n - y + 1 << endl;
    return 0;
}
