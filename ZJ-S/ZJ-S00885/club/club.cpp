#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n, T;

struct ldt
{
	long long a;
	long long b;
	long long c;
	bool operator<(ldt &b)
	{
		if (this->a != b.a) return this->a < b.a;
		if (this->b != b.b) return this->b < b.b;
		return this->c < b.c;
	}
} z[N];

vector<ldt> abig, bbig, cbig;

long long dfs(long long a, long long b, long long c)
{
	long long ans = 0;
	long long now = a + b + c;
	if (now >= n) return 0;
	if (a < (n >> 1)) ans = max(ans, dfs(a+1, b, c) + z[now + 1].a);
	if (b < (n >> 1)) ans = max(ans, dfs(a, b+1, c) + z[now + 1].b);
	if (c < (n >> 1)) ans = max(ans, dfs(a, b, c+1) + z[now + 1].c);
	return ans;
}

int main()
{
	freopen("club.in",  "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		abig.clear();
		bbig.clear();
		cbig.clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &z[i].a, &z[i].b, &z[i].c);
			if (z[i].a >= z[i].b && z[i].a >= z[i].c) abig.push_back(z[i]);
			else if (z[i].b >= z[i].c) bbig.push_back(z[i]);
			else cbig.push_back(z[i]);
		}
		if (abig.size() <= (n >> 1) && bbig.size() <= (n >> 1) && cbig.size() <= (n >> 1))
		{
			long long ans = 0;
			for (auto i : abig)
			{
				ans += i.a;
			}
			for (auto i : bbig)
			{
				ans += i.b;
			}
			for (auto i : cbig)
			{
				ans += i.c;
			}
			printf("%lld\n", ans);
			continue;
		}
		printf("%lld\n", dfs(0, 0, 0));
	}
	return 0;
}

