#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[5005],ans;
void dfs(int dep,int s,int mxn){
	if(dep==n+1){
		if(s!=0&&s>2*mxn){
			ans=(ans+1)%998244353;
		}
		return;
	}
	dfs(dep+1,s,mxn);
	dfs(dep+1,s+a[dep],max(mxn,a[dep]));
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,0,-1);
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
