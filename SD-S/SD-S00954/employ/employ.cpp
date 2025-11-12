#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const int Mod=998244353;
ll dp[(1<<18)+5][20];
string s;
int n,m;
int c[505];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j)) cnt++;
			}
			for(int j=0;j<n;j++){
				if(!(i&(1<<j))){
					for(int k=0;k<=cnt;k++){
						if(s[cnt+1]=='0') dp[i|(1<<j)][k+1]=(dp[i|(1<<j)][k+1]+dp[i][k])%Mod;
						else{
							if(c[j+1]>k) dp[i|(1<<j)][k]=(dp[i|(1<<j)][k]+dp[i][k])%Mod;
							else dp[i|(1<<j)][k+1]=(dp[i|(1<<j)][k+1]+dp[i][k])%Mod;
						}
					}
				}
			}
		}
		ll ans=0;
		for(int i=0;i<=n-m;i++) ans=(ans+dp[(1<<n)-1][i])%Mod;
		cout<<ans;
		return 0;
	}
	else if(m==n){
		int fl=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||c[i]==0) fl=1;
			ans=ans*i%Mod;
		}
		if(fl==1) cout<<0;
		else cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
//2+1+3
