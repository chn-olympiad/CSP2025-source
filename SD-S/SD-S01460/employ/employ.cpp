#include<bits/stdc++.h>
#define int long long
#define __FAST_IO__ std::ios::sync_with_stdio(0),std::cin.tie(0)
#define __FILE_IO__ freopen("employ.in","r",stdin),freopen("employ.out","w",stdout)

inline void solve()
{
	int n,m; std::cin >> n >> m;
	std::vector<int> p(n+1),c(n+1);
	std::string s; std::cin >> s; s = ' ' + s;
	 
	for(int i = 1;i <= n;i++) p[i] = i;
	for(int i = 1;i <= n;i++) std::cin >> c[i];
	
	int ans = 0;
	do
	{
		int cnt = 0;
		int lq = 0;
		for(int i = 1;i <= n;i++)
		{
			if(cnt >= c[p[i]]) {cnt++; continue;}
			if(s[i] == '1') lq++;
			else cnt++;	
		}
		if(lq >= m) ans++;
	}
	while(std::next_permutation(p.begin()+1,p.end()));
	std::cout << ans ;
}

signed main()
{
	__FILE_IO__;
	__FAST_IO__;
//	system("fc employ1.out employ1.ans"); 

	int T = 1;
	while(T--) solve();
	return 0;
}
