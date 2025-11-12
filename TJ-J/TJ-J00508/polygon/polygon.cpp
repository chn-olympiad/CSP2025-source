#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define int long long
int mod=998244353;
int cnt=0;
int n;
int a[5010];
void dfs(int step,int maxx,int s,int choice){
	if(step>n){
		if(maxx*2<s&&choice>=3)cnt++;
		cnt%=mod;
		return;
	}else{
		dfs(step+1,max(maxx,a[step]),s+a[step],choice+1);
		if(n-step+choice>2)dfs(step+1,maxx,s,choice);
	}
}
int c[5010][5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=5000;i++){
		c[i][i]=1;
		c[i][1]=i;
	}
	for(int i=1;i<=5000;i++){
		for(int j=2;j<=5000;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=mod;
		}
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=3){
		int sum=0;int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
			sum+=a[i];
		}
		if(sum>maxx*2)cout << 1;
		else cout << 0;
	} 
	else if(n<=22){
		dfs(1,0,0,0);
		cout << cnt;
	}
	else{
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=c[n][i];
			ans%=mod;
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
