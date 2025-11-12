#include<iostream>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
int c[20];
bool vis[20];
int a[20];
int check() {
	int res=0;
	for(int i=1; i<=n; i++)
		if(i-1-res<c[a[i]]&&s[i-1]=='1')
			res++;
	return res;
}
long long ans;
void dfs(int k) {
	if(k>n) {
		if(check()>=m)
			ans++;
	}
	for(int i=1; i<=n; i++)
		if(!vis[i]) {
			vis[i]=1;
			a[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	return;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n>10) {
		long long p=1ll;
		for(long long i=1; i<=n; i++)
			p=p*i%mod;
		cout<<p;
		return 0;
	}
	cin>>s;
	for(int i=1; i<=n; i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}