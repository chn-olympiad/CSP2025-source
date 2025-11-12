#include<bits/stdc++.h>
#define rint register int
using namespace std;
//bool soha;
const int mxn=114514;
int n,a[mxn][4],dp[201][114][114];
//bool kkksc03;
inline int read(){
    int x=0;bool f=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar())if(c=='-')f=1;
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return f?-x:x;
}
void solve(){
	n=read();
	for(rint i=1;i<=n;i++){
		a[i][1]=read();a[i][2]=read();a[i][3]=read();
	}
	int ans=-1e9;
	for(rint i=0;i<=n;i++){
		for(rint j=0;j<=n/2;j++){
			for(rint k=0;k<=n/2;k++)dp[i][j][k]=0;
		}
	}
	for(rint i=1;i<=n;i++){
		for(rint j=0;j<=n/2;j++){
			for(rint k=0;k<=n/2;k++){
				if(i-j-k<0)continue;
				if(i-j-k>n/2)continue;
				dp[i][j][k]=-1e9;
				if(j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
				if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
				if(i-j-k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				if(i==n)ans=max(ans,dp[i][j][k]);
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	//printf("%lfMB\n",(&kkksc03-&soha)/1024.0/1024.0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
	t=read();
	while(t--)solve(); 
    return 0;
}
/*
	Code is far away from
bug with the animal protecting
*/