#include<bits/stdc++.h>
using namespace std;
#define for1(i,a,b) for(int i=(a);i<=(b);i++)
#define for2(i,a,b) for(int i=(a);i<(b);i++)
#define for3(i,a,b) for(int i=(a);i>=(b);i--)
#define for4(i,a) for(auto &i:(a))
#define puba push_back
#define pii pair<int,int>
#define ll long long
#define int long long
#define mem(a,b) memset((a),(b),sizeof((a)))
const int N=505,mod=998244353;
int n,m,c[N],dp[1<<18][20];
string s;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for2(i,0,n) cin>>c[i];
	if(m==n){
		int ans=1;
		for2(i,0,n){
			if(c[i]==0||s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for1(i,1,n) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	bool flag=1;
	for2(i,0,n) if(s[i]=='0') flag=0;
	if(flag==1){
		int tot=0;
		for2(i,0,n) if(c[i]==0) tot++;
//		cout<<tot<<"\n";
		if(tot==m){
			int ans=1;
			for1(i,1,n) ans=ans*i%mod;
		}else cout<<0;
		return 0;
	}
	dp[0][0]=1;
	for2(i,1,1<<n){
		for2(j,0,n){
			if((i>>j)&1){
				int to=i^(1<<j);
				int pre=__builtin_popcount(to);//pre person
				for1(k,0,m){
					if(!dp[to][k]) continue;
//					cout<<c[pre]
					if(pre-k>=c[j]||s[pre]=='0'){
//						cout<<i<<"-"<<k<<" "<<to<<" "<<dp[to][k]<<"\n";
						dp[i][k]+=dp[to][k];
						if(dp[i][k]>=mod) dp[i][k]-=mod;
					}else if(k<m){
//						cout<<i<<"^"<<k+1<<" "<<to<<" "<<dp[to][k]<<"\n";
						dp[i][k+1]+=dp[to][k];
						if(dp[i][k+1]>=mod) dp[i][k+1]-=mod;
					}
				}
			}
		}
//		for1(j,0,m) cout<<dp[i][j]<<" ";
//		cout<<"\n";
	}
	cout<<dp[(1<<n)-1][m];
	
	return 0;
}