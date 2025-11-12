#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353; 
int n;
int r[5010];
int p[5010];
int pp[5010];
int ans=0;
void dfs(int sum,int i,int step,int maxx){
	if(i>n){
		if(step>=3&&sum>2*maxx){
			ans++;
			ans%=mod;
//			cout<<sum<<" "<<i<<" "<<step<<"\n";
		}
		return;
	}
	dfs(sum,i+1,step,maxx);
	dfs(sum+r[i],i+1,step+1,max(maxx,r[i]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+1+n);
	dfs(0,0,0,0);
	cout<<ans/2;
	return 0;
}
