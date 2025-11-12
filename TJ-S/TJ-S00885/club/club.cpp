#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t, n, a[100005][5], deps[5], ans;
struct node
{
	int val, dep;
};
bool cmp(node nd1, node nd2)
{
	return nd1.val > nd2.val;
}
void dfs(int id, int sum)
{
	if (id == n+1)
	{
		ans = max(ans, sum);
		return ;
	}
	node b[5];
	for (int i = 1; i <= 3; i++)
	{
		b[i].val = a[id][i];
		b[i].dep = i;
	}
	sort(b+1, b+4, cmp);
	for (int i = 1; i <= 3; i++)
	{
		deps[b[i].dep]++;
		if (deps[b[i].dep] <= n/2)
		{
			dfs(id+1, sum+b[i].val);
		}
		deps[b[i].dep]--;
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
    	ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
        	for (int j = 1; j <= 3; j++)
        	{
        		cin >> a[i][j];
			}
        }
        dfs(1, 0);
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
