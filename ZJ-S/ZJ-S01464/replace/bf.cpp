#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , ull> pr;
const int N = 2e5 + 5 , L = 5e6 + 5;
const int P1 = 131 , P2 = 13331 , MOD = 1e9 + 9;
const pr P(P1 , P2);
int n , q; 
pr hs[N][2] , ht[2][L] , pw[L];
string s[N][2] , t[2];
inline int add(const int &x , const int &y){return x + y >= MOD ? x + y - MOD : x + y;}
inline int neg(const int &x){return x ? MOD - x : 0;}
pr val(const char &ch){return {ch - 'a' + 1 , ch - 'a' + 1};}
pr operator + (const pr &a , const pr &b){return {add(a.fi , b.fi) , a.se + b.se};}
pr operator - (const pr &a , const pr &b){return {add(a.fi , neg(b.fi)) , a.se - b.se};}
pr operator * (const pr &a , const pr &b){return {(int)((ll)a.fi * b.fi % MOD) , a.se * b.se};}
pr Hash(int l , int r , int k){return ht[k][r] - ht[k][l - 1] * pw[r - l + 1];}
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)
		cin >> s[i][0] >> s[i][1];
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 0 ; j < 2 ; j++)
		{
			for(auto &c : s[i][j])
				hs[i][j] = hs[i][j] * P + val(c);
		}
	}
	pw[0] = {1 , 1};
	for(int i = 1 ; i <= L - 5 ; i++)
		pw[i] = pw[i - 1] * P;
	while(q--)
	{
		cin >> t[0] >> t[1];
		int m = t[0].size();
		for(int k = 0 ; k < 2 ; k++)
		{
			ht[k][0] = {0 , 0};
			for(int i = 1 ; i <= m ; i++)
				ht[k][i] = ht[k][i - 1] * P + val(t[k][i - 1]);
		}
		int pr = 0 , sf = 0;
		while(pr < m && t[0][pr] == t[1][pr])pr++;
		while(sf < m && t[0][m - 1 - sf] == t[1][m - 1 - sf])sf++;
		int ans = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			int sz = s[i][0].size();
		 	for(int l = max(m - sf - sz , 0) + 1 ; l <= min(pr , m - sz) + 1 ; l++)
		 		//l <= pr + 1 ; m - sf <= r = l + sz - 1 <= m
		 	{
		 		int r = l + sz - 1;
		 		if(
		 			// l <= pr + 1 && m - sf <= r && 
		 		 	hs[i][0] == Hash(l , r , 0) && hs[i][1] == Hash(l , r , 1))
		 		{
		 		 	// cerr << i << ' ' << l << ',' << r << '\n';
					ans++;
		 		}
		 	}
		}
		cout << ans << "\n";
	}
	return 0;
}