#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN=20,mod=998244353;

int n,m,dp[MAXN][1<<MAXN],c[MAXN],ans,num[1<<MAXN];
char s[MAXN];

void add(int &x,int y){x+=y;x>=mod?x-=mod:1;return;}

int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	for(int i=1;i<(1<<MAXN);i++) num[i]=num[i>>1]+(i&1);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	dp[0][(1<<n)-1]=1;
	for(int t=(1<<n)-1;t;t--){
		for(int i=0;i<=n;i++) if(dp[i][t]){
			for(int x=0;x<n;x++) if(t&(1<<x)){
				if(i>=c[x]) add(dp[i+1][t^(1<<x)],dp[i][t]);
				else if(s[n-num[t]]=='0') add(dp[i+1][t^(1<<x)],dp[i][t]);
				else add(dp[i][t^(1<<x)],dp[i][t]);
			}
		}
	}
	for(int i=0;n-i>=m;i++) add(ans,dp[i][0]);
	cout<<ans<<endl;
	return 0;
}
