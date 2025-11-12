#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}return x;
}
char ch;
int n,m,s[510],dp[2][262146][510],g[510],ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		cin>>ch,s[i]=(ch^48);
	for(int i=1;i<=n;i++)
		g[i]=read();
	dp[1][0][0]=1;
	for(int day=1;day<=n;day++){
		memset(dp[day&1^1],0,sizeof(dp[day&1^1]));
			for(int j=0;j<(1<<n);j++){
				if(j&(1<<(k-1)))continue;
			for(int i=0;i<=day-1;i++){
				if(dp[day&1][j][i]==0)continue;
				for(int k=1;k<=n;k++){
					if(g[k]<=i||s[day]==0)dp[day&1^1][j|(1<<(k-1))][i+1]+=dp[day&1][j][i];
					else dp[day&1^1][j|(1<<(k-1))][i]+=dp[day&1][j][i];
				}
			}
		}
	}
	for(int i=0;i<=n-m;i++)
		ans+=dp[n&1^1][(1<<n)-1][i];
	cout<<ans;
}