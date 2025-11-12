#include<bits/stdc++.h>
#define int long long
#define __FAST_IO__ std::ios::sync_with_stdio(0),std::cin.tie(0)
#define __FILE_IO__ freopen("replace.in","r",stdin),freopen("replace.out","w",stdout)

const int N = 2e5+10;

int n,q;
std::string s[N][3];

inline void solve()
{
	std::cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		std::cin >> s[i][1] >> s[i][2];
	}
	
	for(int i = 1;i <= q;i++)
	{
		std::string t1,t2; std::cin >> t1 >> t2;
		int ans = 0;
		
		for(int i = 1;i <= n;i++)
		{
			for(int j = 0;j < t1.size()-s[i][1].size()+1;j++)
			{
				std::string tmp = t1;
				bool ok = 1;
				for(int k = 0;k < s[i][1].size();k++)
				{
					if(tmp[j+k] != s[i][1][k]) ok = 0;
				}
				if(!ok) continue;
				for(int k = 0;k < s[i][1].size();k++)
				{
					tmp[j+k] = s[i][2][k];
				}
				if(tmp == t2) ans++;
			}
		}
		std::cout << ans << '\n';
	}
}

signed main()
{
	__FILE_IO__;
	__FAST_IO__;
//	system("fc replace1.out replace1.ans"); 

	int T = 1;
	while(T--) solve();
	return 0;
}
