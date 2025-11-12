#include<bits/stdc++.h>
#define int long long
#define __FAST_IO__ std::ios::sync_with_stdio(0),std::cin.tie(0)
#define __FILE_IO__ freopen("club.in","r",stdin),freopen("club.out","w",stdout)

#define pii std::pair<int,int> 
#define fi first
#define se second

inline void solve()
{
	int n; std::cin >> n;
	std::vector<std::vector<pii>> a(n+1,std::vector<pii>(4));
	
	for(int i = 1;i <= n;i++)
	{
		std::cin >> a[i][1].fi >> a[i][2].fi >> a[i][3].fi;
		a[i][1].se = 1, a[i][2].se = 2, a[i][3].se = 3;
		std::sort(a[i].begin()+1,a[i].end(),std::greater<pii>());
	}
	
	std::sort(a.begin()+1,a.end(),[](std::vector<pii> x,std::vector<pii> y){
		if(x[1] == y[1])
		{
			if(x[2] == y[2]) return x[3] > y[3];
			return x[2] > y[2];
		}
		return x[1] > y[1];
	});
	
	
	std::priority_queue<int> q;
	
	int ans = 0;
	std::vector<std::vector<int>> vec(4); 
	
	for(int i = 1;i <= n;i++)
	{
		ans += a[i][1].fi;
		vec[a[i][1].se].push_back(i);
	}
	
	if(std::max({(int)vec[1].size(),(int)vec[2].size(),(int)vec[3].size()}) > n/2)
	{
		for(int i = 1;i <= 3;i++)
		{
			if((int)vec[i].size() > n/2)
			{
				std::vector<int> tmp;
				for(int x : vec[i]) tmp.push_back(a[x][1].fi - a[x][2].fi);
				std::sort(tmp.begin(),tmp.end());
				int dlt = tmp.size() - n/2;
				for(int j = 0;j < dlt;j++) ans -= tmp[j];
			}
		}
	}
	std::cout << ans << '\n';
}

signed main()
{
	__FILE_IO__;
	__FAST_IO__;
//	system("fc club3.out club3.ans"); 

	int T = 1; std::cin >> T;
	while(T--) solve();
	return 0;
}
