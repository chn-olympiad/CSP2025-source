#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,xn=505;int s,d,a[xn],b[xn],C[xn][xn],dp[xn][xn],c[xn],w1[xn],ans;
char ch;
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF)n=(n<<1)+(n<<3)+(ch&15),ch=getchar();
	n*=w;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(s),read(d);
	for(int g=1;g<=s;g++){
		ch=getchar();while(ch!='0'&&ch!='1')ch=getchar();a[g]=ch&1;
	}
	for(int g=1;g<=s;g++)read(b[g]);
	for(int g=0;g<=s;g++){
		C[g][0]=C[g][g]=1;for(int h=1;h<g;h++)C[g][h]=(C[g-1][h-1]+C[g-1][h])%mod;
	}
	for(int g=1;g<=s;g++)c[b[g]]++;for(int g=1;g<=s;g++)c[g]+=c[g-1];
	w1[0]=1;for(int g=1;g<=s;g++)w1[g]=1ll*w1[g-1]*g%mod;dp[0][0]=1;
	for(int g=1;g<=s;g++)if(!a[g]){
		for(int h=0;h<g;h++)for(int j=s-c[h];j>=0;j--)dp[h][j+1]=(dp[h][j+1]+dp[h][j])%mod,
			dp[h][j]=1ll*dp[h][j]*(c[h]-g+j+1)%mod;
		for(int h=g-1;h>=0;h--){
			for(int j=0;j<=s-c[h];j++)for(int v=0;v<=j&&v<=c[h+1]-c[h];v++)
				dp[h+1][j-v]=(dp[h+1][j-v]+1ll*dp[h][j]*C[j][v]%mod*
					C[c[h+1]-c[h]][v]%mod*w1[v])%mod;
			for(int j=0;j<=s-c[h];j++)dp[h][j]=0;
		}
	}
	else for(int h=g-1;h>=0;h--){
		for(int j=0;j<=s-c[h];j++)for(int v=0;v<=j&&v<=c[h+1]-c[h];v++)
			dp[h+1][j-v]=(dp[h+1][j-v]+1ll*dp[h][j]*(c[h]-g+j+1)%mod*C[j][v]%mod*
				C[c[h+1]-c[h]][v]%mod*w1[v])%mod;
		for(int j=s-c[h];j;j--)dp[h][j]=dp[h][j-1];dp[h][0]=0;
	}
	for(int g=0;g<=s-d;g++)ans=(ans+1ll*dp[g][s-c[g]]*w1[s-c[g]])%mod;cout<<ans;
	return 0;
}
