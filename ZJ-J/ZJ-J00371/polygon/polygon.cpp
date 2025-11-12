#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long yb[2][50005][4];
long long ans=0;
/*
void dfs(int step,int sum,int maxn,int b){
	if(sum+a[step+1]>a[step+1]*2&&b+1>=3)ans++;
	if(step>n)return ;
	dfs(step+1,sum+a[step+1],a[step+1],b+1);
	dfs(step+1,sum,maxn,b);
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	/*if(n<=20){
		dfs(1,0,0,0);
		dfs(1,a[1],a[1],1);
		cout<<ans;
		return 0;
	}*/
	yb[0][0][0]=1;yb[1][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			yb[i%2][j][3]=yb[(i+1)%2][j][3];
			yb[i%2][j][2]=yb[(i+1)%2][j][2];
			yb[i%2][j][1]=yb[(i+1)%2][j][1];
		}
		for(int j=a[i];j<50005;j++){//50005
			yb[i%2][j][3]=yb[(i+1)%2][j][3]+yb[(i+1)%2][j-a[i]][2]+yb[(i+1)%2][j-a[i]][3];
			yb[i%2][j][2]=yb[(i+1)%2][j][2]+yb[(i+1)%2][j-a[i]][1];
			yb[i%2][j][3]%=998244353;
			//cout<<i<<' '<<j<<' '<<yb[i%2][j][2]<<' '<<yb[i%2][j][3]<<'\n';
		}
		yb[i%2][a[i]][1]=yb[(i+1)%2][a[i]][1]+1;
		for(int j=2*a[i]+1;j<50005;j++){
			ans+=yb[i%2][j][3];
			ans%=998244353;
		}
		//cout<<ans<<"\n\n";
	}
	cout<<ans;
}