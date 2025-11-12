#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,cnt;
int a[5555];
void dfs(int step,int sum,int maxx,int xuan){
	if(step>=n){
		if(xuan<3)return;
		else if(sum-maxx<=maxx)return;
		else{
			cnt++;
			cnt%=mod;
			return;
		}
	}
	dfs(step+1,sum,maxx,xuan);
	dfs(step+1,sum+a[step+1],a[step+1],xuan+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	cout<<cnt%mod;
	return 0;
}
