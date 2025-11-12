#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct tree
{
    int r,v;
}
vector<tree> t[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        t[a].r = b;
        t[a].v = c;
        t[b].r = a;
        t[b].v = c;
    }
    cout << a + 2 * b - c;
    return 0;
}