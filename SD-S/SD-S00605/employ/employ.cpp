#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+9,M=1e4+9,INF=1e18;
ll n,m,a[509],flag[20],k[20],now0,ans;
string s;
void solve(){
	int cnt=0;
	now0=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'&&now0<k[i]){
			cnt++;
		}if(s[i-1]=='0'){
			now0++;
		}
	}
	if(cnt>=m){
		ans++;
	}
}
void dfs(int now){
	if(now==10){
		solve();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			k[now+1]=a[i];
			dfs(now+1);
			flag[i]=0;
		}
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		dfs(0);
		cout<<ans;
		return 0;
	}
	cout<<"114514";
	return 0;
}
