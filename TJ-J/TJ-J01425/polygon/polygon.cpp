#include<bits/stdc++.h>
using namespace std;
int n,a[5005],qzh[5005];
long long ans,c[5003][5003];
bool f=0;
void dfs(int mx,int now,int add,int t){
	if(t>=3&&add>a[mx]){
		ans++;
		ans%=998244353;
		for(int i=1;i<now;i++){
			ans+=1ll*c[now][i+1];
			ans%=998244353;
		}
		return;
	}
	if(now==1)return;
	for(int i=now-1;i>=1;i--)
		if(qzh[i]+add>mx)
			dfs(mx,i,add+a[i],t+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a[1];
	c[1][1]=1ll;
	qzh[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
		qzh[i]=a[i]+qzh[i-1];
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=998244353;
		}
	}
	for(int j=1;j<=n+1;j++){
		c[n+1][j]=c[n][j]+c[n][j-1];
		c[n+1][j]%=998244353;
	}
	sort(a+1,a+n+1);
	if(f==0){
		for(int i=3;i<=n;i++){
			ans+=1ll*c[n+1][i+1];
			ans%=998244353;
		}
		cout<<ans;
	}
	else for(int i=3;i<=n;i++)
		if(qzh[i-1]>a[i])
			dfs(i,i,0,1);
	cout<<ans;
	return 0;
}
