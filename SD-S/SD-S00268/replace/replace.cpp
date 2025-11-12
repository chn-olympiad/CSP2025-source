bool M1;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define look_memory cerr<<abs(&M1-&M2)/1024.0/1024<<"MB\n";

namespace syr
{
	const ull M = 131;
	const ll N = 2e5+10;
	const ll N2 = 5e6+10;
	ll n, q, ans, lenmax;
	ull p[N2];
	string t1, t2;
	vector <pair<ull, ull>> v[N2];
	void work()
	{
		cin>>n>>q;
		for (ll i=1; i<=n; i++) {
			cin>>t1>>t2;
			ll len = t1.length();
			ull s1 = 0, s2 = 0;
			for (ll j=0; j<len; j++) {
				s1 = s1*M + t1[j]-'a'+1;
				s2 = s2*M + t2[j]-'a'+1;
			}
			v[len].push_back({s1, s2});
			lenmax = max(lenmax, len);
//			cout<<s1<<" "<<s2<<'\n';
		}
		p[0] = 1;
		for (ll i=1; i<=lenmax; i++) p[i]=p[i-1]*M;
		while (q--) {
			ans = 0;
			cin>>t1>>t2;
			ll len = t1.length();
			if (len != t2.length()) {
				cout<<0<<'\n';
				continue;
			}
			ull tmp1 = 0, tmp2 = 0;
			for (ll i=0; i<len; i++) {
				tmp1 = tmp1*M + t1[i]-'a'+1;
				tmp2 = tmp2*M + t2[i]-'a'+1;
			}
			for (ll i=1; i<=len; i++) {
				for (ll j=0; j<v[i].size(); j++) {
					ull x = v[i][j].first;
					ull y = v[i][j].second;
					ull tmp = 0;
					for (ll k=0; k<i; k++) tmp = tmp*M+t1[k]-'a'+1;
					if (tmp==x && tmp1-x*p[len-i]+y*p[len-i]==tmp2) ans++;
					for (ll k=i; k<len; k++) {
						tmp = (tmp-(t1[k-i]-'a'+1)*p[i-1])*M+t1[k]-'a'+1;
						if (tmp==x && tmp1-x*p[len-k-1]+y*p[len-k-1]==tmp2) ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}

bool M2;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	look_memory;
	syr::work();
	return 0;
}

