#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],f[5001][5001],d[5001],ans,m=998244353;
bool v[5001][5001];
long long dfs(int s,int k){
	if(s<0){
		return d[k-1]; 
	}if(v[s][k]!=0){
		return f[s][k];
	}v[s][k]=1;
	for(int i=k-1;i>=1;i--){
		f[s][k]+=dfs(s-a[i],i);
		f[s][k]=f[s][k]%m;
	}return f[s][k]%m;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	d[0]=1;
	for(int i=1;i<=n+1;i++){
		d[i]=d[i-1]*2;
		d[i]%=m;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=n;i>=3;i--){
		ans+=dfs(a[i],i);
		ans=ans%m;
	}cout<<ans;
	return 0;
}

