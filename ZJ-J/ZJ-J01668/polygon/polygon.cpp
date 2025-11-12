#include<bits/stdc++.h>
using namespace std;
int n,a[5010],dp[5010][5010],ans=0,mx=0;
void dfs(int i,int s,int l,int c){
	if(i>n){
		if(c>=3){
			if(s>2*l){
				ans=(ans+1)%998244353;
			}
		}
		return;
	}
	dfs(i+1,s,l,c);
	dfs(i+1,s+a[i],a[i],c+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	if(mx<=1){
		for(int i=1;i<=n;i++){
			dp[1][i]=1;
		}
		for(int i=2;i<=n;i++){
			int s=0;
			for(int j=n-i+1;j>=1;j--){
				s+=dp[i-1][j+1];
				dp[i][j]=s;
				if(i>=3)ans=(ans+s)%998244353;
			}
		}
		cout<<ans;
	}else{
		dfs(1,0,0,0);
		cout<<ans;
	}
	
	return 0;
}
