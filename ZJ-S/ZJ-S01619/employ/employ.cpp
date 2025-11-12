#include<bits/stdc++.h>
#define maxn int(505)
#define ll long long
using namespace std;
const ll mod = 998244353;
ll n, m, ans, c[maxn], p[maxn];
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ans=1;
	cin>>s;
	s="#"+s;
	bool flag=true;
	for(int i = 1; i <= n; i++) {
		if(s[i]=='0') {
			flag=false;
			break;
		}
	}
	for(int i = 1; i <= n; i++)
		cin>>c[i];
	for(int i = 1; i <= n; i++) 
		p[i]=i;
	if(m==n) {
		if(!flag) {
			cout<<0<<endl;
			return 0;
		}
		for(int i = 1; i <= n; i++) {
			if(c[i]==0) {
				flag=false;
				break;
			}
		}
		if(!flag) {
			cout<<0<<endl;
			return 0;
		}
		ans=1;
		for(int i = 1; i <= n; i++) ans=ans*i%mod;
		cout<<ans<<endl;
		return 0;
	}
	if(m==1 && n>10) {
		ans=1;
		sort(c+1, c+n+1, less<int>());
		for(int i = 1; i <= n; i++) {
			ans*=(n-c[i]+1)-(i-1);
			if((n-c[i]+1)-(i-1)<=0) {
				ans=0;
			}
			ans%=mod;
		}
		ll anst=1;
		for(int i = 1; i <= n; i++) anst=anst*i%mod;
		cout<<(anst-ans+mod)%mod<<endl;
		return 0;
	}
	sort(p+1, p+n+1);
	ll ans=0;
	 do {
//		for(int i = 1; i <= n; i++) {
//			cout<<p[i]<<' ';
//		} cout<<endl;
		int cnt=0;
		for(int i = 1; i <= n; i++) {
			if(s[i]=='0'
			|| cnt>=c[p[i]]) {
				cnt++;
			}
		}
		if(n-cnt>=m) ans++;
	}while(next_permutation(p+1, p+n+1));
	cout<<ans%mod<<endl;
	return 0;
}
