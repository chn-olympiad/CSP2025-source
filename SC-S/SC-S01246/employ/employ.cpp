#include<bits/stdc++.h>
#define ll long long
#define Suika 0
using namespace std;
const int N=20010,M=1000010;
const ll mod=998244353;
int n,m;
ll ans;
string s;
int c[30],p[30];
bool vis[30];
void dfs(int pos) {
	if(pos==n+1) {
		int sum=0;
		for(int i=1; i<=n; i++) {
			if(sum>=c[p[i]]||s[i-1]=='0') sum++;
		}
		if(n-sum>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(!vis[i]) {
			vis[i]=1;
			p[pos]=i;
			dfs(pos+1);
			vis[i]=0;
		}
	}
}
int main() {
	double bgn=clock();
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return Suika;
} 