#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],ans;
void dfs(int fa,int sum){
	for(int i=fa+1;i<=n;i++){
		if(sum>a[i]) ans++,ans%=mod;
		dfs(i,sum+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
