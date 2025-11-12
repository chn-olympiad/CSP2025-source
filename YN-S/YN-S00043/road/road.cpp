#include<bits/stdc++.h>
long long n, m, k, in_sum;
long long c[20], cw[20][10100], mn[20], mn_n[10010];
long long ans_tot;
struct node
{
	long long to, w;
	bool operator<(const node &b)const
	{
		return this->w > b.w;
	}
};
struct st
{
	long long to, w;
	bool operator<(const st &b)const
	{
		return this->w > b.w;
	}
};
bool in[10100], use[20];
std::priority_queue<node> edge[10100], now, sav;
std::priority_queue<st> cw_s[20];


long long check()
{
	long long ans = 0;

	while (in_sum < n)
	{
		while (in[now.top().to])
		{
			now.pop();
		}
		int to = now.top().to, w = now.top().w;
		for (int i = 1; i <= k; i++)
		{
			if (!use[i])
			{
				continue;
			}
			while (in[cw_s[i].top().to])
			{
				cw_s[i].pop();
			}
			if (cw_s[i].top().w + mn[i] < w)
			{
				w = cw_s[i].top().w + mn[i];
				to = cw_s[i].top().to;
			}
		}
		if (!in[to])
		{
			ans += w;
			in[to] = 1;
			now.pop();
			while (!edge[to].empty())
			{
				if (!in[edge[to].top().to] && edge[to].top().w < mn_n[edge[to].top().to])
				{
					now.push(edge[to].top());
					mn_n[edge[to].top().to] = edge[to].top().w;
				}
				sav.push(edge[to].top());
				edge[to].pop();
			}
			while (!sav.empty())
			{
				edge[to].push(sav.top());
				sav.pop();
			}
			in_sum++;
			continue;
		}
		for (int i = 1; i <= k; i++)
		{
			if (mn[i] > cw[i][to])
			{
				mn[i] = cw[i][to];
			}
		}
		now.pop();
	}
	return ans;
}
void dfs(int pl)
{
	if (pl >= k)
	{
		long long res = 0;
		memset(mn_n, 0x3f, sizeof(mn_n));
		memset(in, 0, sizeof(in));
		in[1] = 1;
		in_sum = 1;
		for (int i = 1; i <= k; i++)
		{
			mn[i] = cw[i][1];
			if (use[i])
			{
				res += c[i];
			}
		}
		while (!now.empty())
		{
			now.pop();
		}
		for (int i = 1; i <= k; i++)
		{
			while (!cw_s[i].empty())
			{
				cw_s[i].pop();
			}
			for (int j = 1; j <= n; j++)
			{
				cw_s[i].push({j, cw[i][j]});
			}
		}
		while (!edge[1].empty())
		{
			now.push(edge[1].top());
			sav.push(edge[1].top());
			edge[1].pop();
		}
		while (!sav.empty())
		{
			edge[1].push(sav.top());
			sav.pop();
		}
		res += check();
		ans_tot = std::min(ans_tot, res);
	}
	else
	{
		use[pl] = 1;
		dfs(pl + 1);
		use[pl] = 0;
		dfs(pl + 1);
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		long long u = 0, v = 0, w = 0;
		scanf("%lld%lld%lld", &u, &v, &w);
		edge[u].push({v, w});
		edge[v].push({u, w});
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++)
		{
			scanf("%lld", &cw[i][j]);
			cw_s[i].push({i, cw[i][j]});
		}
	}
	in[1] = 1;
	while (!edge[1].empty())
	{
		now.push(edge[1].top());
		sav.push(edge[1].top());
		edge[1].pop();
	}
	while (!sav.empty())
	{
		edge[1].push(sav.top());
		sav.pop();
	}
	in_sum = 1;
	memset(mn_n, 0x3f, sizeof(mn_n));
	while (in_sum < n)
	{
		int to = now.top().to;
		long long w = now.top().w;
		if (!in[now.top().to])
		{
			ans_tot += w;
			in[to] = 1;
			now.pop();
			while (!edge[to].empty())
			{
				if (!in[edge[to].top().to] && edge[to].top().w < mn_n[edge[to].top().to])
				{
					now.push(edge[to].top());
					mn_n[edge[to].top().to] = edge[to].top().w;
				}
				sav.push(edge[to].top());
				edge[to].pop();
			}
			while (!sav.empty())
			{
				edge[to].push(sav.top());
				sav.pop();
			}
			in_sum++;
			continue;
		}
		now.pop();
	}
	dfs(1);
	printf("%lld\n", ans_tot);
	return 0;
}
