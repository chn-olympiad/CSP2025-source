#include<bits/stdc++.h>
using namespace std;
int n,a[10005],z;
void dfs(int dep,int maxx,int s){
	if(maxx>n){
		return;
	}
	if(dep>maxx-2){
		dfs(1,maxx+1,a[1]);
	}
	if(s>a[maxx]){
		z=(z+1)%998244353;
	}
	dfs(dep+1,maxx,s+a[dep]);
	dfs(dep+1,maxx,s);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,3,a[1]+a[2]);
	cout<<z;

	return 0;
}

