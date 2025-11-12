#include<iostream>
using namespace std;
int n,ans;
int a[5010]={};
void dfs(int k,int sum,int amax,int c){
	if(k>=3 && sum>amax*2){
		ans=(ans+1)%998244353;
	}
	if(c==n-1){
		return ;
	}
	for(int i=c+1;i<n;i=i+1){
		dfs(k+1,sum+a[i],max(amax,a[i]),i);
	}
}
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i=i+1){
		cin>>a[i];
	}
	dfs(0,0,-1,-1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
