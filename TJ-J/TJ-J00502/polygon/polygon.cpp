#include<bits/stdc++.h>
using namespace std;
int n,ans,gs=3;
int a[500909];
void dfs(int x,int now,int k,int p){
	
	if(x>n || now==gs){
		if(p>2*k &&now==gs){
			ans=(ans+1)%998244353;
		}
		return;
	}
	x=x+1;
	dfs(x,now,k,p);
	x=x-1;
	k=max(k,a[x]);
	p=p+a[x];
	x=x+1;
	now++;
	dfs(x,now,k,p);
	return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(;gs<=n;gs++){
		dfs(1,0,0,0);
	}
	cout<<ans;
    return 0;
}
