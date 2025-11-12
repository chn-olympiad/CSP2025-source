#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[5005],maxx,ans;
void dfs(int step,int sum,int ma){
	if(step==n+1){
		if(ma*2<sum) ans++;
		ans%=Mod;
		return;
	}
	dfs(step+1,sum+a[step],max(ma,a[step]));
	dfs(step+1,sum,ma);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=Mod;
		}
		ans=ans-1-n-(n-1)*n/2;
	}
	else{
		dfs(1,0,0);
	}
	cout<<ans;
	return 0;
}

