#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5001],ans; 
void dfs(int sum,int x,int k,int l){
	if(x>n){
		if(l>=3 and a[k]*2<sum){
			ans++;
		}
		return;
	}
	dfs(sum+a[x],x+1,x,l+1);
	dfs(sum,x+1,k,l);
}
int dis[5001][5001];
int c(int k,int n){
	if(k==1) return n;
	if(k==n) return 1;
	if(dis[n][k]!=0) return dis[n][k];
	int c1=c(k,n-1),c2=c(k-1,n-1);
	dis[n][k]=(0ll+c1+c2)%MOD;
	return dis[n][k];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
	}
	if(n>20){
		for(int i=3;i<=n;i++){
			ans=(0ll+ans+c(i,n))%MOD;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(0,1,0,0);
	cout<<ans;
	return 0;
}
