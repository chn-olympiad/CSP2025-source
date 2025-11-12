#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
const int N=5e2+10,M=1e2+10,MOD=998244353;
ll n,m,ans,c[N],Jc[N];
bool s[N],vis[N];
void dfs(ll day,ll Through){
	if(Through>=m){
		ans=(ans+Jc[n-day])%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		if((day-Through)<c[i]&&s[day+1]) dfs(day+1,Through+1);
		else dfs(day+1,Through);
		vis[i]=false;
	}
}
ll get_max(){
	sort(c+1,c+1+n);
	ll len=1,cnt=0,maxx=0;
	for(int i=1;i<=n;i++){
		if(s[i]==false) len++;
	}
	len=lower_bound(c+len,c+1+n,1)-c;
	for(int i=1;i<=n&&len<=n;i++){
		if(s[i]==true){
			if(cnt<c[len]) maxx++;
			else cnt++;
			len++;
		}else cnt++;
	}
	return maxx;
}
void solve(){
	cin>>n>>m;
	string str; cin>>str;
	for(int i=0;i<str.size();i++) s[i+1]=str[i]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	if(get_max()<m){
		cout<<get_max();
		return;
	}
	Jc[0]=Jc[1]=1ll;
	for(int i=2;i<=n;i++) Jc[i]=(Jc[i-1]*i)%MOD;
	if(get_max()==n){
		cout<<Jc[n];
		return;
	}
	dfs(0,0);
	cout<<ans;
}
int main(){
	IOS;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
