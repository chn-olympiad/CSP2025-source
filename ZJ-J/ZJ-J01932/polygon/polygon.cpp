#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ans;
int n;
int a[5520];
void dfs(int x,int sum,int mx,int cnt){
	if(x>n){
		if(sum>mx*2 && cnt>=3){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(x+1,sum+a[x],max(mx,a[x]),cnt+1);
	dfs(x+1,sum,mx,cnt);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	dfs(1,0,-1,0);
	cout<<ans;
	return 0;
}