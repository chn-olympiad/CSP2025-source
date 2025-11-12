#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, a[5005], c;
void dfs(int id, int maxn, int sum, int choose)
{
    if (id == n+1)
    {
        if (sum > maxn*2 && choose > 2)
        {
            c = (c+1)%998244353;
        }
        return ;
    }
    dfs(id+1, a[id], sum+a[id], choose+1);
    dfs(id+1, maxn, sum, choose);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    dfs(1, -1, 0, 0);
    cout << c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
