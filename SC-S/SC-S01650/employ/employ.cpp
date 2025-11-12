#include<bits/stdc++.h>
using namespace std;
const int NN=505;
int n,m,c[NN];
char s[NN];
#define ll long long
ll ans;
const ll Mod=998244353;
const int NMIN=18;
ll dp[2][1<<NMIN][NMIN+18];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	bool flagA=1;
	for(int i=1;i<=n;i++)flagA=flagA&&(s[i]=='1');
	ans=0;
	if(n<=18){
		int up=1<<n,now=0,nxt=1;
		dp[now][0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<up;j++){
				for(int k=0;k<=n;k++)dp[nxt][j][k]=0;
			}
			for(int j=0;j<up;j++){
				int cnt=__builtin_popcount(j);
				if(cnt!=i-1)continue;
				for(int k=1;k<=n;k++){
					if((j>>(k-1))&1)continue;
					int msk=j|(1<<(k-1));
					for(int x=0;x<=cnt;x++){
						ll d=dp[now][j][x];
						//cout<<j<<" "<<x<<" "<<cnt<<" "<<d<<'\n';
						if(x>=c[k]||s[i]=='0'){
							dp[nxt][msk][x+1]=(dp[nxt][msk][x+1]+d)%Mod;
						}else{
							dp[nxt][msk][x]=(dp[nxt][msk][x]+d)%Mod;
						}
					}
				}
			}
			swap(now,nxt);
		}
		for(int i=0;i<=n-m;i++)ans=(ans+dp[now][up-1][i])%Mod;
		cout<<ans;
	}
	return 0;
}
