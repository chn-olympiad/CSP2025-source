#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Int __int128
#define rep(i , a , b) for (int i = (a); i <= (b); i++)
#define drep(i , a , b) for (int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
const int maxn = 2e5+5;
ull base = 2333 , mod = 51152120903234377;
int n , m , len[maxn];
string s1 , s2 , s[2][maxn];
ull h[2][maxn] , h1[maxn*30] , h2[maxn*30] , p[maxn*30];
ull Hash(ull *h , int l , int r)
{
	if (r < l) return 0;
	return (h[r] - h[l-1]*p[r-l+1]);
}
signed main()
{
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	p[0]=1;
	rep(i , 1 , maxn*30-5)p[i]=p[i-1]*base;
	bool flag = 0;
	rep(i , 1 , n)
	{
		cin >> s1 >> s2;
		s[0][i]=s1,s[1][i]=s2;
		len[i]=s1.size();
		s1=" "+s1,s2=" "+s2;
		rep(j, 1 , len[i])
		{
			h[0][i]=(h[0][i]*base+(s1[j]-'a'+1));
			h[1][i]=(h[1][i]*base+(s2[j]-'a'+1));
			if (s1[j] > 'b' || s2[j] > 'b' )flag=1;
		}
	}
	while(m--)
	{
		cin >> s1 >> s2;
		if (s1.size() != s2.size()){cout << 0 << "\n";continue;}
		int m = s1.size();
		s1=" "+s1,s2=" "+s2;
		rep(i , 0 , m)h1[i]=h2[i]=0;
		rep(i , 1 , m)h1[i]=(h1[i-1]*base+(s1[i]-'a'+1));
		rep(i , 1 , m)h2[i]=(h2[i-1]*base+(s2[i]-'a'+1));
		int ans = 0;
		rep(i , 1 , n)
		{
			for (int j = 1; j + len[i] - 1 <= m; j++)
			{
				int l = j , r = j + len[i] - 1;
				ull t1 = Hash(h1 , l , r) , t2 = Hash(h2 , l , r);
				if (t1 == h[0][i] && 
					t2 == h[1][i] && 
					h1[l - 1] == h2[l - 1] &&
					Hash(h1 , r + 1 , m) == Hash(h2 , r + 1 , m))ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}