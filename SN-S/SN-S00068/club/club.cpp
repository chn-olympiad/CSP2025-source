#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int T,n;
int a[100005][4];
int b[100005];
int dp[505][255][255];
bool check1(){
	for(int i=1;i<=n;i++)
		if(a[i][2]>0 || a[i][3]>0) return false;
	return true;
}
bool check2(){
	for(int i=1;i<=n;i++)
		if(a[i][3]>0) return false;
	return true;
}
bool cmp(int x,int y){return x>y;}
int solve1(){
	for(int i=1;i<=n;i++)
		b[i]=a[i][1];
	sort(b+1,b+1+n,cmp);
	int res=0;
	for(int i=1;i<=n/2;i++)
		res+=b[i];
	return res;
}
int solve2(){
	int res=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i][2]-a[i][1];
		res+=a[i][1];
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n/2;i++)
		res+=b[i];
	return res;
}
void work(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	if(check1()){
		cout<<solve1()<<'\n';
		return;	
	}
	if(check2()){
		cout<<solve2()<<'\n';
		return;	
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=min(n/2,i);j++)
			for(int k=max(0ll,i-j-n/2);k<=min(i-j,n/2);k++){
				int l=i-j-k;
				dp[i][j][k]=0;
				if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
				if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
				if(l>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
			}
	int ans=0;
	for(int j=0;j<=n/2;j++)
		for(int k=max(0ll,n-j-n/2);k<=min(n-j,n/2);k++)
			ans=max(ans,dp[n][j][k]);
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
		work();
	return 0;
}
