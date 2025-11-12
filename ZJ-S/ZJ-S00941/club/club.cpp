#include <bits/stdc++.h>
using namespace std;
#define int long long
struct info{
	int a,b,c;
	//pair<int,int> nums[4];
	bool vis;
} num[100005];
/*bool cmp(info a,info b){
	return a.nums[0].first>b.nums[0].first;
}*/
int n;
namespace CASE1{
	int dp[2][35][35][35];
	void solve(){
		memset(dp,0,sizeof(dp));
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int a=0;a<=n/2;a++){
				for(int b=0;b<=n/2 && b<=n-a;b++){
					for(int c=0;c<=n/2 && c<=n-a-b;c++){
						//cout<<(i&1)<<' '<<a<<' '<<b<<' '<<c<<' '<<(i&1^1)<<endl;
						if(a) dp[i&1][a][b][c]=max(dp[i&1^1][a-1][b][c]+num[i].a,dp[i&1][a][b][c]);
						if(b) dp[i&1][a][b][c]=max(dp[i&1^1][a][b-1][c]+num[i].b,dp[i&1][a][b][c]);
						if(c) dp[i&1][a][b][c]=max(dp[i&1^1][a][b][c-1]+num[i].c,dp[i&1][a][b][c]);
						ans=max(dp[i&1][a][b][c],ans);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
namespace CASE2{
	bool cmp1(info a,info b){
		return a.a>b.a;
	}
	void solve(){
		sort(num+1,num+1+n,cmp1);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=num[i].a;
		}
		cout<<ans<<endl;
	}
}
namespace CASE3{
	int dp[2][105][105];
	void solve(){
		memset(dp,0,sizeof(dp));
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int a=0;a<=n/2;a++){
				for(int b=0;b<=n/2 && b<=n-a;b++){
					//cout<<(i&1)<<' '<<a<<' '<<b<<' '<<c<<' '<<(i&1^1)<<endl;
					if(a) dp[i&1][a][b]=max(dp[i&1^1][a-1][b]+num[i].a,dp[i&1][a][b]);
					if(b) dp[i&1][a][b]=max(dp[i&1^1][a][b-1]+num[i].b,dp[i&1][a][b]);
					ans=max(dp[i&1][a][b],ans);
				}
			}
		}
		cout<<ans<<endl;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		//clubnum[1]=clubnum[2]=clubnum[3]=0;
		cin>>n;
		bool flag1=1,flag2=1;int flag3;
		for(int i=1;i<=n;i++){
			cin>>num[i].a>>num[i].b>>num[i].c;
			if(num[i].b||num[i].c) flag1=0;
			if(num[i].c) flag2=0;
			flag3+=max(num[i].a,max(num[i].b,num[i].c));
/*			num[i].nums[1]=make_pair(aa,1);
			num[i].nums[2]=make_pair(bb,2);
			num[i].nums[3]=make_pair(cc,3);*/
			//sort(num[i].nums+1,num[i].nums+3+1,greater<pair<int,int> >());
		}
		//sort(num+1,num+1+n,cmp);
		if(n<=35) CASE1::solve();
		else if(flag1) CASE2::solve();
		else if(flag2 && n<=205) CASE3::solve();
		else cout<<flag3<<endl;
	}
	return 0;
}

