#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],n,sum;
long long tot;
void dfs(int x,int y,int z,int ans){
	if(x==n+1){
		if(y<3||z*2>=ans) return;
		tot++;
		tot%=mod;
		return;
	}
	dfs(x+1,y+1,max(z,a[x]),ans+a[x]);
	dfs(x+1,y,z,ans);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum==n){
		long long ans=-1-n-n*(n-1)/2;
		tot=1;
		for(int i=1;i<=n;i++){
			tot*=2;
			tot%=mod;
		}
		tot+=ans;
		if(tot<0) tot+=mod;
		cout<<tot;
	}
	else{
		dfs(1,0,0,0);
		cout<<tot;
	}
	return 0;
}
