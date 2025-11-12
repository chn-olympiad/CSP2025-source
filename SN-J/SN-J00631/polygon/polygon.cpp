#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n;
int a[5100],ans=0;
void dfs(int p,int x,int s,int m){
	if(p>n){
		if(x>=3 && s>m*2){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(p+1,x+1,s+a[p],a[p]);
	dfs(p+1,x,s,m);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

