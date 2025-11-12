#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string s;
ll c[510],f[510];
bool vis[510];
const ll mod=998244353;
ll ans;
void check(){
	ll cnt1=0;//已经录用的人数 
	ll cnt2=0;//被劝退的人数
	for(ll i=1;i<=n;i++){
		if(cnt2>=f[i]){
			cnt2++;
		}
		else if(s[i-1]=='0'){
			cnt2++;
		}
		else if(s[i-1]=='1'){
			cnt1++;
		}
		if(cnt1>=m){
			ans++;
			ans%=mod;
			break;
		}
	} 
	return ;
}
void dfs(ll x){
	if(x>n){
		check();
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			f[x]=c[i];
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	dfs(1);
	cout<<ans;
	return 0;
}
