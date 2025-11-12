//反悔贪心 
#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;
const int N=1e5+10;
int t,n;
long long dp[210][110][110];
int a[N],b[N],c[N];
void work1(){
	memset(dp,0,sizeof dp);	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n/2;j++){
			for(int u=0;u<=n/2;u++){
				int d=i-j-u;
				if(d>n/2) continue;
				if(j!=0)
				dp[i][j][u]=max(dp[i][j][u],dp[i-1][j-1][u]+a[i]);
				if(u!=0)
				dp[i][j][u]=max(dp[i][j][u],dp[i-1][j][u-1]+b[i]);
				if(d!=0)
				dp[i][j][u]=max(dp[i][j][u],dp[i-1][j][u]+c[i]);
			}
		}
	}
	long long ans=0;	
	for(int j=0;j<=n/2;j++)
		for(int u=0;u<=n/2;u++)
		if((n-u-j)<=n/2){
			ans=max(ans,dp[n][j][u]);
		}		
	cout<<ans<<"\n";
}
void work2(){
	sort(a+1,a+1+n);
	long long ans=0;
	for(int i=n;i>n/2;i--){
		ans+=a[i]; 
	}
	cout<<ans<<"\n";
}
void work3(){
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=max({a[i],b[i],c[i]});
	cout<<ans<<"\n";
} 
PII qnum[N];
void work4(){
	long long ans=0;
	
	for(int i=1;i<=n;i++){
		qnum[i]={a[i]-b[i],i};
	}
	sort(qnum+1,qnum+1+n);
	for(int i=1;i<=n/2;i++)
		ans+=b[qnum[i].second];
	for(int i=n/2+1;i<=n;i++)
		ans+=a[qnum[i].second];
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int flg=0,flg1=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0){
				flg=1;
			}
			if(c[i]!=0)
			flg1=1;
		}
			
		if(n<=200) work1();
		else if(flg==0) work2();
		else if(flg1==0) work4();
		else work3();
	}
	return 0;
} 