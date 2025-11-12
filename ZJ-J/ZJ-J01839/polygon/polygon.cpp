#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5003],f[5003],cnt;
int c[5003][5003];
void dfs(int k,int sum,int c){
	if(k==n+1)return;
	if(c>=2&&a[k]<sum){
		cnt++;
		cnt%=mod;
	}
	dfs(k+1,sum+a[k],c+1);
	dfs(k+1,sum,c);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		cout<<(a[1]+a[2]>a[3]);
	}
	else if(a[n]==1){
		int ans=0;
		for(int i=0;i<=n;i++){
			c[i][0]=1;
			for(int j=1;j<=i;j++){
				c[i][j]=c[i-1][j]+c[i-1][j-1];
				if(i==n&&j>=3){
					ans+=c[i][j];
					ans%=mod;
				}
			}
		}
		cout<<ans;
	}
	else{
		dfs(1,0,0);
		cout<<cnt;
	} 
	return 0;
}

