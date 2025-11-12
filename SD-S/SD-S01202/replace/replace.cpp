#include <bits/stdc++.h>
#define fi first
#define se second
#define mkp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF=0x3f3f3f3f3f3f3f3f, N=2e5+5, MOD1=1e9+663, MOD2=1e9+9;
ll n, T, cntb, cnta, p[N];
string s[N][2], t[N][2];
vector<ll> e[N], e1[N], e2[N];
pll a[N];
bool flag=1;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>T;
	for(ll i=1; i<=n; i++) {
		cin>>s[i][0]>>s[i][1];
		ll m=s[i][0].size();
		cnta=cntb=0;
		for(ll j=0; j<m; j++) {
			if(s[i][0][j]=='a') cnta++;
			if(s[i][0][j]=='b') cntb++;
		}
		if(!(cnta==m-1&&cntb==1)) flag=0;
		cnta=cntb=0;
		for(ll j=0; j<m; j++) {
			if(s[i][1][j]=='a') cnta++;
			if(s[i][1][j]=='b') cntb++;
		}
		if(!(cnta==m-1&&cntb==1)) flag=0;		
	}
	for(ll i=1; i<=T; i++) {
		cin>>t[i][0]>>t[i][1];
		ll m=t[i][0].size();
		cnta=cntb=0;
		for(ll j=0; j<m; j++) {
			if(t[i][0][j]=='a') cnta++;
			if(t[i][0][j]=='b') cntb++;
		}
		if(!(cnta==m-1&&cntb==1)) flag=0;
		cnta=cntb=0;
		for(ll j=0; j<m; j++) {
			if(t[i][1][j]=='a') cnta++;
			if(t[i][1][j]=='b') cntb++;
		}
		if(!(cnta==m-1&&cntb==1)) flag=0;		
	}
	if(flag) {
		for(ll i=1; i<=n; i++) {
			ll m=s[i][0].size(), pos1, pos2;
			for(ll j=0; j<m; j++)
				if(s[i][0][j]=='b') {
					pos1=j;
					break;
				}
			for(ll j=0; j<m; j++)
				if(s[i][1][j]=='b') {
					pos2=j;
					break;
				}	
			p[i]=pos2-pos1;
		}		
		sort(p+1, p+n+1);
		ll tot=unique(p+1, p+n+1)-p-1;
		for(ll i=1; i<=n; i++) {
			ll m=s[i][0].size(), pos1, pos2;
			for(ll j=0; j<m; j++)
				if(s[i][0][j]=='b') {
					pos1=j;
					break;
				}
			for(ll j=0; j<m; j++)
				if(s[i][1][j]=='b') {
					pos2=j;
					break;
				}	
			ll pp=lower_bound(p+1, p+tot+1, pos2-pos1)-p;
			e[pp].push_back(m);
			e1[pp].push_back(min(pos1, pos2));
			e2[pp].push_back(m-1-max(pos1, pos2));
		}
		for(ll i=1; i<=tot; i++) {
			sort(e[i].begin(), e[i].end());
			sort(e1[i].begin(), e1[i].end());
			sort(e2[i].begin(), e2[i].end());
		}
		p[tot+1]=INF;
		for(ll i=1; i<=T; i++) {
			ll m=t[i][0].size(), pos1, pos2;
			for(ll j=0; j<m; j++)
				if(t[i][0][j]=='b') {
					pos1=j;
					break;
				}
			ll mm=t[i][1].size();
			for(ll j=0; j<mm; j++)
				if(t[i][1][j]=='b') {
					pos2=j;
					break;
				}	
			if(mm!=m) {
				cout<<"0\n";
				continue;
			}				
			ll pp=lower_bound(p+1, p+tot+1, pos2-pos1)-p;
			if(p[pp]!=pos2-pos1) {
				cout<<"0\n";
				continue;
			}
			ll l=min(pos1, pos2), r=m-1-max(pos1, pos2);
			cout<<e[pp].size()+(upper_bound(e[pp].begin(), e[pp].end(), m)-e[pp].begin())
							-(upper_bound(e1[pp].begin(), e1[pp].end(), l)-e1[pp].begin())
							-(upper_bound(e2[pp].begin(), e2[pp].end(), r)-e2[pp].begin())<<'\n';
		}
		return 0;
	}
	return 0;
}
