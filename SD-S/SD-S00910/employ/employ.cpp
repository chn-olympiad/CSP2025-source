#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const ll N=509;
ll n,m,ans;
string s;
ll c[N];
ll d[N];
ll cnt3;
ll jc(int n){
	ll ans=1;
	for(int i=2;i<=n;i++){
		ans=(ans*i)%mod;
	}
	return ans;
}
bool check(){
	ll cnt1=0;
	ll cnt2=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			cnt1++;
		}
		else{
			if(cnt1>=c[d[i]]){
				cnt1++;
			}
			else
				cnt2++;
		}
	}
	return cnt2>=m;
}
void dfs(ll id){
	if(id>n){
		if(check()){
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(d[i]) continue;
		d[i]=id;
		dfs(id+1);
		d[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[i]==0){
				cout<<1;
				return 0;
			}
		}
		cout<<jc(n)<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
