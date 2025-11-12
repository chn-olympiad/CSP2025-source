#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
void dfs(long long x,long long y,long long z){
	if(y>a[x]){
		ans++;
		ans%=998244353;
	}
	if(z>=x){
		return ;
	}
	dfs(x,y+a[z],z+1);
	dfs(x,y,z+1);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,0,1);
	}
	cout<<ans;
	return 0;
}
