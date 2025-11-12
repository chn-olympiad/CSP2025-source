// replace.cpp

/*
以下记t[j][1]=x，t[j][2]=y 


考虑dp。
设f[i]表示x的前i个字符的替换方案数
那么可以枚举一个j<i，若s[j~i]可以替换为 
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;

int n, q; 
array<string, 2> s[N];

void solve()
{
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		cin >> s[i][0] >> s[i][1];
	}
	if(n <= 100 && q <= 100){
		while(q --){
			string x, y; cin >> x >> y;
			ll cnt = 0;
			for(int u = 1; u <= n; u ++){
				int pos = x.find(s[u][0]);
				while(pos != string::npos){
					string ttt; int i, j;
					for(i = 0; i < pos; i ++) ttt.push_back(x[i]);
					for(i = pos, j = 0; i < x.size() && j < s[u][1].size(); i ++, j ++){
						ttt.push_back(s[u][1][j]);
					}
					for(; i < x.size(); i ++) ttt.push_back(x[i]);
					if(ttt == y) cnt ++;
//					cerr << i << ' ' << ttt << ' ' << pos << '\n';
					pos = x.find(s[u][0], pos+1);
				}
			}
			cout << cnt << '\n';
		}
	}
	else{
		while(q --){
			string x, y; cin >> x >> y;
			cout << 0 << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	solve();
	return 0;
}

/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
