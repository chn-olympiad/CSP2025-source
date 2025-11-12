#include<bits/stdc++.h>
using namespace std;
int n,a[5005],flag=0,ans=0,mod=998244353;
void dfs(int sum,int Max,int k,int s){
	if(s==n+1){
		if(k>=3&&sum>Max*2){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(sum+a[s],max(Max,a[s]),k+1,s+1);
	dfs(sum,Max,k,s+1);
	return;
}
int C(int x,int y){
	long long num1=1,num2=1;
	for(int i=x;i>=x-y+1;i--){
		num1*=i;
		num1/=num2;
		num2++;
		num1%=mod;
	}
	return num1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(flag==1||n<=20){
		dfs(0,0,0,1);
		cout<<ans;
	}
	else{
		for(int i=3;i<=n;i++){
			ans+=C(n,i);
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}
