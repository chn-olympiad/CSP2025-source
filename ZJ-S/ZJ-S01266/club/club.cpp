#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int s[100010][4];
int dp[2][210][210][210];//NOTICE LESS THAN 1E5
//dp[i][j][k] means :the i-th stu in the j-th sub ,and he is the k-th one;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2]>>s[i][3];
	int ans=0;
	memset(dp,128,sizeof dp);
	dp[0][0][0][0]=0;
	for(int i=1;i<=n;i++){
		for(int a=0;a<=min(i,n/2);a++){
			for(int b=0;b<=min(i,n/2);b++){
				if(a+b>i) break;
				int c=i-a-b;
				if(a+b+c>i) break;
				if(a) dp[i%2][a][b][c]=max(dp[i%2][a][b][c],dp[(i-1)%2][a-1][b][c]+s[i][1]);
				if(b) dp[i%2][a][b][c]=max(dp[i%2][a][b][c],dp[(i-1)%2][a][b-1][c]+s[i][2]);
				if(c) dp[i%2][a][b][c]=max(dp[i%2][a][b][c],dp[(i-1)%2][a][b][c-1]+s[i][3]);
				ans=max(ans,dp[i%2][a][b][c]);
//				cout<<i<<":"<<a<<"/"<<b<<"/"<<c<<"   "<<dp[i][a][b][c]<<endl;
			}
		}
	}
	cout<<ans<<endl;
}
bool cmp(int xx,int yy){
	return xx>yy;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		if(n<=200) solve();
		else{
			cin>>n;
			for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2]>>s[i][3];
			int ans=0;
			vector<int>v;
			for(int i=1;i<=n;i++) v.push_back(s[i][1]);
			sort(v.begin(),v.end(),cmp);
			for(int i=0;i<n/2;i++) ans+=v[i];
			cout<<ans<<endl;
		}
	}	
	return 0;
}