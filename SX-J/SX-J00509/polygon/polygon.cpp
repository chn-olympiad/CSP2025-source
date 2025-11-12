#include<bits/stdc++.h>
using namespace std;
#define P 998244353
//At least I get 40pts.
// (applause)
int n,a[5005],ans;
void dfs(int dep,int sm,int mx){
	if(dep>n){
		if(sm>2*mx){
			ans++;
			ans%=P;
		}
		return;
	}
	dfs(dep+1,sm+a[dep],max(mx,a[dep]));
	dfs(dep+1,sm,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans%P;
	return 0;
}
