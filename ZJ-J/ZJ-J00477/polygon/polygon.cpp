#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[5010];
vector<int>vs;//selected
ll ans;
void solve(){
	ll sum=0,ma=0;
	for(auto x:vs){
		sum+=x;
		ma=max(ma,1LL*x);
	}
	if(sum>2*ma){
		ans++;
		ans%=998244353;
	}
}//dont touch


void dfs(int u,int top,int lsti){ //already selected u sticks  entire top sticks  last one is a[lsti]
	if(u==top){
		solve();
		return;
	}
	for(int i=lsti+1;i<=n;i++){
		vs.push_back(a[i]);
		dfs(u+1,top,i);
		vs.pop_back();
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(0,i,0);
		vs.clear();
	}
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}