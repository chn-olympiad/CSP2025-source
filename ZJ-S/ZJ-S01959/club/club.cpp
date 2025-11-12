#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[100005][3];
int dp[305][305][305];//daoi,j ge0,k ge1
void solve(){
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			for(int k=1;k<n+1;k++){
				dp[i][j][k]=0;
			}
		}
	}
	ans=0;
	for(int i=1;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			for(int k=0;k<n+1;k++){
				dp[i][j][k]=dp[i-1][j][k]+a[i][2];
				if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][0]);
				if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][1]);
				//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
			}
		}
	}
	for(int j=0;j<=n/2;j++){
		for(int k=0;k<=n/2;k++){
			//cout<<j<<' '<<k<<' '<<dp[n][j][k]<<'%';
			if(n-k-j>=n/2) continue;
			ans=max(ans,dp[n][j][k]);
		}
	}
	cout<<ans<<endl;
}
void solve2(){
	priority_queue<int>q;
	for(int i=1;i<n+1;i++){
		q.push(a[i][0]);
	}
	while(q.size()>n/2){
		ans+=q.top();
		q.pop();
	}
	cout<<ans<<endl;
}
struct w{
	int a,b,c;
}f[100005];
bool operator < (w a,w b){
	return a.c<a.b;
}
void solve3(){
	ans=0;
	for(int i=1;i<n+1;i++){
		f[i].a=a[i][0],f[i].b=a[i][1],f[i].c=a[i][0]-a[i][1];
	}
	sort(f+1,f+n+1);
	for(int i=1;i<n+1;i++){
		if(i<=n/2) ans+=f[i].b;
		else ans+=f[i].a;
	}
	cout<<ans<<endl;
}
void work(){
	cin>>n;
	int x=0,y=0;
	for(int i=1;i<n+1;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];//system("fc .out .out >diff
		x+=a[i][1];
		y+=a[i][2];
	}
	if(n<200) solve();		
	else if(x==0 && y==0) solve2();
	else if(x==0) solve3();
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) work();
//	cout<<"&";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
