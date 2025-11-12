#include<bits/stdc++.h>
using namespace std;


const int N=210,BN=1e5+10;
int dp[N][N][N];
int n,ans=0;
int a1[BN],a2[BN],a3[BN];

void solve1(){
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j*2<=n;j++){
			for(int k=0;k*2<=n;k++){
				int sum3=i-j-k;
				if(sum3*2>n)continue; 
				if(j>=1)dp[i][j][k]=max(dp[i-1][j-1][k]+a1[i],dp[i][j][k]); 
				if(k>=1)dp[i][j][k]=max(dp[i-1][j][k-1]+a2[i],dp[i][j][k]); 
				if(sum3>=1)dp[i][j][k]=max(dp[i-1][j][k]+a3[i],dp[i][j][k]); 
				ans=max(ans,dp[i][j][k]);
			} 
		} 
	} 
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)
		for(int j=0;j*2<=n;j++)
			for(int k=0;k*2<=n;k++)
				dp[i][j][k]=0;
} 

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first-a.second>b.first-b.second;
}

void solve2(){
	ans=0;
	int sum1=0,sum2=0,sum3=0;
	for(int i=1;i<=n;i++)
		sum1+=a1[i],sum2+=a2[i],sum3+=a3[i];
	if(sum2==0&&sum3==0){
		sort(a1+1,a1+n+1);
		for(int i=n;i>=n/2+1;i--)
			ans+=a1[i];
//		cout<<ans<<'\n';
	} 
	else{
		vector<pair<int,int>> su;
		su.push_back({114514,0});
		for(int i=1;i<=n;i++)
			su.push_back({a1[i],a2[i]});
		sort(su.begin(),su.end(),cmp);
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans+=su[i].first;
			else ans+=su[i].second;
//			cout<<su[i].first<<' '<<su[i].second<<' '<<ans<<'\n';
		}
		cout<<ans<<'\n';
	} 
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a1[i]>>a2[i]>>a3[i];
	if(n<=200)solve1();
	else solve2();
	
	for(int i=1;i<=n;i++)
		a1[i]=a2[i]=a3[i]=0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	cin>>t;
	while(t--)solve();
	
	return 0;
} 