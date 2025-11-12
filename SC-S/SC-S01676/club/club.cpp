#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+5;
const int mod=1e9+7;
int n,a[mx][4],b[mx];
long long ans;
void dfs(int step,int d1,int d2,int d3,int c[]){
	if(step==n){
		long long re=0;
		for(int i=1;i<=n;i++){
			re+=c[i];
	//		cout<<c[i]<<" ";
		}
	//	cout<<'\n';
		ans=max(ans,re);
		return;
	}
	for(int i=step+1;i<=n;i++){
		if(d1<n/2){
			c[step+1]=a[step+1][1];
			dfs(step+1,d1+1,d2,d3,c);
		}
		if(d2<n/2){
			c[step+1]=a[step+1][2];
			dfs(step+1,d1,d2+1,d3,c);
		}
		if(d3<n/2){
			c[step+1]=a[step+1][3];
			dfs(step+1,d1,d2,d3+1,c);
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0)flag1=1;
			if(a[i][3]!=0)flag2=1;
		}
		ans=0;
		memset(b,0,sizeof b);
		if(flag1==0&&flag2==0){
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n;i>=n/2+1;i--)ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		dfs(0,0,0,0,b);
		cout<<ans<<'\n';
	}
	return 0;
}