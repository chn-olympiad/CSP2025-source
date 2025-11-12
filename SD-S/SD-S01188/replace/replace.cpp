#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N = 200005,P = 5000005,K = 131;
int n,q,cnt,mn[N],mx[N],sz[N];
ull pw[P],hhs[2][P];
vector<ull>hs[2][N];
string s[N][2];
unordered_map<ull,int>mp;
inline bool cmp(int k,int i,int l,int r,int nl,int nr)
{
//	cout << k << ' ' << i << ' ' << l << ' ' << r << ' ' << nl << ' ' << nr << ' ' << (hhs[k][r]-hhs[k][l-1]) << ' '  <<(hs[k][i][nr]-hs[k][i][nl-1])*pw[l-nl] << '\n';
	if (l > r && nl > nr) return 1;
	if (nl > nr) return 0;
	if (l < nl) return (hhs[k][r]-hhs[k][l-1])*pw[nl-l] == hs[k][i][nr]-hs[k][i][nl-1];
	return hhs[k][r]-hhs[k][l-1] == (hs[k][i][nr]-hs[k][i][nl-1])*pw[l-nl];
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i < P; i++)
		pw[i] = pw[i-1]*K;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
		sz[i] = s[i][0].size();
		s[i][0] = ' '+s[i][0],s[i][1] = ' '+s[i][1];
		mn[i] = 999999999,mx[i] = -1;
		for (int j = 1; j <= sz[i]; j++)
			if (s[i][0][j] != s[i][1][j]) mn[i] = min(mn[i],j),mx[i] = max(mx[i],j);
		hs[0][i].push_back(0),hs[1][i].push_back(0);
		for (int j = 1; j <= sz[i]; j++)
			hs[0][i].push_back(hs[0][i][j-1]+s[i][0][j]*pw[j]),
			hs[1][i].push_back(hs[1][i][j-1]+s[i][1][j]*pw[j]);
	}
	while (q--)
	{
		string x,y;
		cin >> x >> y;
		int ssz = x.size();
		if (ssz != y.size())
		{
			cout << 0 << '\n';
			continue;
		}
		x = ' '+x,y = ' '+y;
		int mmn = 999999999,mmx = -1;
		for (int j = 1; j <= ssz; j++)
		{
			if (x[j] != y[j]) mmn = min(mmn,j),mmx = max(mmx,j);
			hhs[0][j] = hhs[0][j-1]+x[j]*pw[j];
			hhs[1][j] = hhs[1][j-1]+y[j]*pw[j];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!cmp(0,i,mmn,mmx,mn[i],mx[i]) || !cmp(1,i,mmn,mmx,mn[i],mx[i]))
				continue;
		//	cout << sz[i] << ' ' << mmn << ' ' << mmx << ' ' << mn[i] << ' ' << mx[i] << '\n';
			if (mmx+sz[i]-mx[i] <= ssz && mmn-(mn[i]-1) >= 1 &&
				cmp(0,i,mmn-(mn[i]-1),mmn-1,1,mn[i]-1) && cmp(0,i,mmx+1,mmx+sz[i]-mx[i],mx[i]+1,sz[i]))
				ans++;
		//	cout << ans << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
