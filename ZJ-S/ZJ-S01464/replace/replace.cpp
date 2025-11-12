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
int n , q , L1 , L2; 
pr hs[N][2] , ht[2][L] , pw[L];
string s[N][2] , t[N][2];
inline int add(const int &x , const int &y){return x + y >= MOD ? x + y - MOD : x + y;}
inline int neg(const int &x){return x ? MOD - x : 0;}
pr val(const char &ch){return {ch - 'a' + 1 , ch - 'a' + 1};}
pr operator + (const pr &a , const pr &b){return {add(a.fi , b.fi) , a.se + b.se};}
pr operator - (const pr &a , const pr &b){return {add(a.fi , neg(b.fi)) , a.se - b.se};}
pr operator * (const pr &a , const pr &b){return {(int)((ll)a.fi * b.fi % MOD) , a.se * b.se};}
pr Hash(int l , int r , int k){return ht[k][r] - ht[k][l - 1] * pw[r - l + 1];}
namespace BF
{
	string t[2];
	void Solve()
	{
		for(int i = 1 ; i <= q ; i++)		
		{
			t[0] = ::t[i][0];
			t[1] = ::t[i][1];
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
		return ;
	}
}
namespace B
{
	const int BL = L - 5;
	int ans[N];
	struct T{int x , l , r , id;}a[N] , qu[N];
	bool operator < (const T &a , const T &b){return a.x == b.x ? (a.l == b.l ? a.r < b.r : a.l < b.l) : a.x < b.x;}
	struct BIT
	{
		int c[L];
		void add(int x , int v)
		{
			for(int i = x ; i <= BL ; i += i & -i)
				c[i] += v;
		}
		int ask(int x)
		{
			int ans = 0;
			for(int i = x ; i ; i -= i & -i)
				ans += c[i];
			return ans;
		}
	}bit;
	void Solve()
	{
		// cerr << "B\n";
		for(int i = 1 ; i <= n ; i++)
		{
			int l = 0 , r = 0 , m = s[i][0].size();
			while(l < n && s[i][0][l] != 'b')l++;
			while(r < n && s[i][1][m - r - 1] != 'b')r++;
			int p = l , q = m - r - 1;
			a[i] = {p - q , l + 1 , r + 1 , -i};
		}
		for(int i = 1 ; i <= q ; i++)
		{
			int l = 0 , r = 0 , m = t[i][0].size();
			while(l < n && t[i][0][l] != 'b')l++;
			while(r < n && t[i][1][m - r - 1] != 'b')r++;
			int p = l , q = m - r - 1;
			qu[i] = {p - q , l + 1 , r + 1 , i};
		}
		sort(a + 1 , a + n + 1);
		sort(qu + 1 , qu + q + 1);
		// for(int i = 1 ; i <= n ; i++)
		// 	cerr << '(' << a[i].x << ' ' << a[i].l << ',' << a[i].r << ')';
		// cerr << '\n';
		// for(int i = 1 ; i <= q ; i++)
		// 	cerr << '(' << qu[i].x << ' ' << qu[i].l << ',' << qu[i].r << ')';
		// cerr << '\n';
		for(int i = 1 , l = 1; i <= q ; i++)
		{
			int dt = qu[i].x , j = i;
			while(j + 1 <= q && qu[j + 1].x == dt)j++;
			while(l <= n && a[l].x < dt)l++;
			if(l > n || a[l].x != dt)
			{
				for(int k = i ; k <= j ; k++)
					ans[qu[k].id] = 0;
			}
			else
			{
				int r = l , t = l;
				while(r + 1 <= n && a[r + 1].x == dt)r++;
				// cerr << i << ',' << j << " " << l << ',' << r << '\n';
				for(int k = i ; k <= j ; k++)
				{
					while(t <= r && a[t].l <= qu[k].l)
						bit.add(a[t++].r , 1);
					ans[qu[k].id] = bit.ask(qu[k].r);
				}
				while(t > l)bit.add(a[--t].r , -1);
			}
		}
		for(int i = 1 ; i <= q ; i++)
			cout << ans[i] << "\n";
		return ;
	}
}
int main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)
		cin >> s[i][0] >> s[i][1];
	for(int i = 1 ; i <= n ; i++)
	{
		L1 += s[i][0].size();
		for(int j = 0 ; j < 2 ; j++)
		{
			for(auto &c : s[i][j])
				hs[i][j] = hs[i][j] * P + val(c);
		}
	}
	pw[0] = {1 , 1};
	for(int i = 1 ; i <= L - 5 ; i++)
		pw[i] = pw[i - 1] * P;
	for(int i = 1 ; i <= q ; i++)
	{
		cin >> t[i][0] >> t[i][1];
		L2 += t[i][0].size();
	}
	bool spec = 1;
	auto chk = [&](const string &s)
	{
		int sz = s.size();
		return count(s.begin() , s.end() , 'a') == sz - 1 && count(s.begin() , s.end() , 'b') == 1;
	};
	for(int i = 1 ; i <= n ; i++)
		spec = spec && chk(s[i][0]) && chk(s[i][1]);
	for(int i = 1 ; i <= q ; i++)
		spec = spec && chk(t[i][0]) && chk(t[i][1]);
	// B::Solve();
	if(spec)B::Solve();
	else BF::Solve();
	// if((ll)n * L2 <= 5e7)BF::Solve();
	// else B::Solve();
	return 0;
}