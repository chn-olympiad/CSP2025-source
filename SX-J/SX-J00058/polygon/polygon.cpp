#include<bits/stdc++.h>
using namespace std;
int n;
int a[5003];
int t[5003];
long long ans=0;
void dfs(int depth,int num,int maxn,int sum){
	if(depth>n){
		if(sum-maxn>maxn&&num>=3)ans++;
		return;
	}dfs(depth+1,num+1,max(maxn,a[depth]),sum+a[depth]);

	dfs(depth+1,num,maxn,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}dfs(1,0,0,0);
	cout<<ans<<endl;
	return 0;
}