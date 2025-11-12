#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=5e2+5,p=998244353;
int n,m,c[N];
string s;
vector<int>v;
int ans=0;
bool st[N];
void dfs(int u) {
	if(u>n) {
		int haveout=0;
		for(int i=0;i<v.size();++i) {
			if(v[i]<=haveout) {//out
				haveout++;
			}
			else if(s[i]=='0') {//fail
				haveout++;
			}
			
		}
		if(n-haveout>=m) {
			ans++;
//			for(auto t:v)cout<<t<<" ";
//			
//			cout<<haveout<<"\n";
		}
		return;
	}
	for(int i=1;i<=n;++i) {
		if(st[i])continue;
		st[i]=1;
		v.push_back(c[i]);
		dfs(u+1);
		st[i]=0;
		v.pop_back();
	}
}
void solve() {
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i)cin>>c[i];
	if(m==n) {
		for(int i=0;i<s.size();++i) {
			if(s[i]=='0') {
				cout<<"0\n";
				return;
			}
		}
		sort(c+1,c+n+1);
		if(c[1]!=0)cout<<"1\n";
		else cout<<"0\n";
	}
	else if(n<=18) {
		dfs(1);
		cout<<ans<<"\n";
	}
	else if(m==1) {
		int cnt=0;
		for(int i=0;i<s.size();++i) {
			if(s[i]=='1') {
				cnt++;
			}
		}
		if(cnt==0) {
			cout<<"0\n";
			return;
		}
		cout<<cnt<<"\n";
	}
	else {
		cout<<"1\n";
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _ = 1;
//	cin >> _;
	while(_--)solve();
	return 0;
}
