#include <bits/stdc++.h>
using namespace std;
#define int long long
const int p = 998244353, base = 131, inv = 922042494;
int n, q;
map<pair<int, int>, int> cnt;
map<pair<int, int>, vector<int> > v; 
pair<int, int> d[200005], rg[200005];
string s[200005][2];
vector<int> hsh[200005][2];
int qp(int A, int B)
{
	if(B == 0) return 1;
	if(B == 1) return A;
	int t = qp(A, B>>1);
	if(B & 1) return t*t%p*A%p;
	return t*t%p;
}
int H(string S)
{
	int res = 0;
	for(auto i:S)
	{
		res = (res*base+i-'a'+1)%p;
	}
	return res;
}
int qry(int k, int op, int l, int r)
{
	if(l == 0) return hsh[k][op][r];
	return (hsh[k][op][r]-hsh[k][op][l-1]+p)%p*qp(inv,l)%p;
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
		int L = s[i][0].length();
		int l = 0, r = L-1;
		hsh[i][0].push_back(s[i][0][0]-'a'+1);
		hsh[i][1].push_back(s[i][0][1]-'a'+1);
		while(s[i][0][l] == s[i][1][l] && l < L) l++;
		while(r > 0 && s[i][0][r] == s[i][1][r]) r--;
		for(int j = 1; j < L; j++)
		{
			hsh[i][0].push_back((hsh[i][0][j-1]*base+s[i][0][j]-'a'+1)%p);
			hsh[i][1].push_back((hsh[i][1][j-1]*base+s[i][1][j]-'a'+1)%p);
		}
		if(l != L)
		{
			int h1 = 0, h2 = 0;
			for(int j = l; j <= r; j++)
			{
				h1 = (h1*base+s[i][0][j]-'a'+1)%p;
				h2 = (h2*base+s[i][1][j]-'a'+1)%p;
			}
			d[i] = {h1, h2};
			rg[i] = {l, r};
			cnt[d[i]]++;
			v[d[i]].push_back(i);
		}
	}
	while(q--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int L = s1.length();
		if(L != s2.length())
		{
			cout << "0\n";
			continue;
		}
		int l = 0, r = L-1;
		while(s1[l] == s2[l] && l < L) l++;
		while(r > 0 && s1[r] == s2[r]) r--;
		assert(l != L);
		int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
		for(int i = l; i <= r; i++)
		{
			h1 = (h1*base+s1[i]-'a'+1)%p;
			h2 = (h2*base+s2[i]-'a'+1)%p;
		}
		cout << cnt[{h1, h2}] << '\n';
	} 
	return 0;
}

