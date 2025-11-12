#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
int ans;
int a[5010];
int v[5010];
int m[5010];
void dfs(int step,int sum,int maxx,int last){
	if(sum>maxx*2&&step>=3){
		ans++;
		ans%=mod;
	}
	if(step==n)return;
	if(sum+v[n]-v[last]<=a[n]*2)return;
	for(int i=last+1;i<=n;i++){
		dfs(step+1,sum+a[i],max(maxx,a[i]),i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		v[i]=v[i-1]+a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}