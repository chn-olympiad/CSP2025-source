#include<bits/stdc++.h> 

const int N = 1e5 + 1;

int a[N][3];
std::vector<int> vec;
int ans = 0;
int n;

void dfs(int depth, int a1, int a2, int a3, int d, int res)
{
	if(a1 > depth || a2 > depth || a3 > depth)
		return;
	if(d == n)
	{
		ans = std::max(res, ans);
		return;
	}
	//---
	dfs(depth, a1 + 1, a2, a3, d + 1, res + a[d][0]);
	dfs(depth, a1, a2 + 1, a3, d + 1, res + a[d][1]);
	dfs(depth, a1, a2, a3 + 1, d + 1, res + a[d][2]);
	//---
}
void solve()
{
	std::memset(a, 0, sizeof a);
	ans = 0;
	bool isZero = true;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
		vec.push_back(-a[i][0]);
		if(isZero && !(a[i][1] == a[i][2] && a[i][2] == 0))
			isZero = false;		
	}
	if(isZero)
	{
		//puts("------");
		std:sort(vec.begin(), vec.end());
		for(int i = 0; i < n/2; i++)
			ans += -vec[i];
	}
	else if(n >= 30)
	{
		for(int i = 0; i < n; i++)
		{
			ans += std::max(a[i][0], std::max(a[i][1], a[i][2]));
		}
	}
	else
		dfs(n / 2, 0, 0, 0, 0, 0);
	std::cout << ans <<'\n';
}

int main()
{
	std::freopen("club.in", "r", stdin);
	std::freopen("club.out", "w", stdout);
	
	int T;
	std::cin >> T;
	while(T--)
	{
		solve();
	}
	return 0;
}
