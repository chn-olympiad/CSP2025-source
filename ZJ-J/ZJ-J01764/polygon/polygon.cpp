#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[100010],ans=0;
bool check(int som,int maxx,int cnt){
	if(cnt>2*maxx&&som>=3){
		return 1;
	}else return 0;
}
void dfs(int x,int som,int maxx,int cnt){
	if(x==n-1){
		if(som<1) return ;
	}
	if(x==n+1){
		if(check(som,maxx,cnt)){
			ans++;
			ans=ans%MOD;
		}
		return ;
	}
	dfs(x+1,som+1,max(maxx,a[x]),cnt+a[x]);
	dfs(x+1,som,maxx,cnt);
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
