#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10,mod=998244353;
int n,m,c[N],a[N],ans;
string s;
bool vis[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++) a[i+1]=a[i]+(s[i]-'0');
	for(int i=1;i<=n;i++) cin>>c[i];
	if(a[n]<m){
		cout<<0<<"\n";
		return 0;
	}
	ans=1;
	for(int i=n;i>=1;i--) ans=(ans*i)%mod;
	if(a[n]==m) cout<<ans<<"\n";
	else cout<<ans/2<<"\n";
	return 0;
}