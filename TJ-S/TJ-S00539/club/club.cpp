#include <bits/stdc++.h>
using namespace std;

struct Student
{
	long long a, b, c;
} stu[100005];

long long ans = 0, cnt1, cnt2, cnt3, n;

void dfs(int i, int sum)
{
	if (i > n) return ;
	if (cnt1 + 1 <= n / 2)
	{
		ans = max(ans, sum + stu[i].a), cnt1++;
		dfs(i + 1, sum + stu[i].a);
		cnt1--;
	}
	if (cnt2 + 1 <= n / 2)
	{
		ans = max(ans, sum + stu[i].b), cnt2++;
		dfs(i + 1, sum + stu[i].b);
		cnt2--;
	}
	if (cnt3 + 1 <= n / 2)
	{
		ans = max(ans, sum + stu[i].c), cnt3++;
		dfs(i + 1, sum + stu[i].c);
		cnt3--;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &stu[i].a, &stu[i].b, &stu[i].c);
		}
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}
