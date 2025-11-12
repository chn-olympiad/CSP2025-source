#include<bits/stdc++.h>
using namespace std;
//just stdc++14.:)
//unfinished
//expected score: 0pts
typedef long long LL;
const int N = 2e5 + 10;
string s[N][3], t[3];
int n, q;
bool st[N];
LL ss[N];
vector<int> vec;
LL ans = 0;

bool sub(string bi, string sm, int idx)
{
	for(int i = 0; i < sm.size(); i ++)
		if(bi[i + idx] != sm[i] || i < sm.size() - 1 && i + idx == bi.size() - 1)
			return false;
	return true;
}
int main()
{
	//init the code
freopen("replace.in", "r", stdin);
freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	//init
	//input
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) cin >> s[i][1] >> s[i][2];
	//body
	while(q --)
	{
		//init
		memset(st, 0, sizeof st);
		memset(ss, 0, sizeof ss);
		//input
		cin >> t[1] >> t[2];
		int minv = N, maxv = 0;
		//body
		for(int i = 0; i < t[1].size(); i ++)
		{
			st[i] = (t[1][i] == t[2][i]);
			if(st[i]) minv = min(minv, i), maxv = max(maxv, i);
			for(int i = 0; i < minv; i ++)
			{
				vec.clear();
				for(int j = 1; j <= n; j ++)
					if(s[j][1].size() >= maxv - i)
						vec.push_back(j);
				for(int v : vec)
					if(sub(t[1], s[v][1], i) && sub(t[2], s[v][2], i))
						ss[i + s[v][1].size()] += ss[i] + 1;
			}
		}
		//output
		for(int i = maxv + 1; i < t[1].size(); i ++) ans += ss[i];
		cout << ans << "\n";
	}
	
	
	return 0;
}
//rp++
