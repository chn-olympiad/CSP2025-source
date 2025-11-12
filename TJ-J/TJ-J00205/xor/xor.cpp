#include"bits/stdc++.h"
using namespace std;
int a[500010],b[500010],n,k,ans=-1;
int p(int l,int r){
	if(l==r) return a[r];
	return b[l-1]^b[r];
}
void dfs(int i,int s){
	if(i==n){
		ans=max(ans,s);
		return;
	}
	for(int j=i+1;j<=n;j++){
		for(int m=j;m<=n;m++){
			if(p(j,m)==k) dfs(m,s+1);
		}
	}
	ans=max(ans,s);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	dfs(0,0);
	if(ans==-1) ans=0;
	cout<<ans;
	return 0;
}

