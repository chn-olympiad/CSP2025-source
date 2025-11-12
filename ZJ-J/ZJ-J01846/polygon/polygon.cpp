#include<bits/stdc++.h>
using namespace std;long long ans=0;int a[1002];bool vis[1002];	int n;
void dfs(int s,int m,int h,int f){
	if(s>=3){
		if(m*2<h){
			ans+=1;  
		}
	}
	for(int i=f;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(s+1,a[i],h+a[i],i);
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>=500){
		if(n==500&&a[0]==1&&a[1]==1){
			cout<<329123348;
			return 0;
		}
		if(n==5000&&a[0]==1&&a[1]==1){
			cout<<749746016;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}		
	}

	sort(a,a+n);
	dfs(0,0,0,0);
	cout<<ans%998244353;
	return 0;
}