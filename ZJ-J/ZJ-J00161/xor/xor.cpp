#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 4000005
#define inf 20000000005
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0'; ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int a[maxn];
int qz[maxn];
int dp[maxn];
int n,k;
int maximum[maxn];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	qz[0]=0;
	n=read(); k=read();
	for(int i=1;i<=n;i++)a[i]=read(),qz[i]=qz[i-1]^a[i];
	for(int i=0;i<=n;i++)dp[i]=0;
	for(int i=0;i<=4000000;i++)maximum[i]=-inf;
	maximum[0]=0;
	for(int i=1;i<=n;i++){
		int tar=qz[i]^k;
		dp[i]=max(dp[i-1],maximum[tar]+1);
		maximum[qz[i]]=max(maximum[qz[i]],dp[i]);
	}
	write(dp[n]); cout<<'\n';
	return 0;
}
