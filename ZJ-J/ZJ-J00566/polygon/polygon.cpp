#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001]={};
int ans=0;
int dfs(int sum,int k){
	int i;
	for(i=k+1;i<=n;i++){
		if(sum>a[i]&&i<=n){
			ans++;
		}
		dfs(sum+a[i],i);
	}
	
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	int i,j;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			dfs(a[i]+a[j],j);
		}
	}
	cout<<ans;
	return 0;
}
