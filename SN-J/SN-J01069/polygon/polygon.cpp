#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5050;
int read () {
	int f=1,x=0;char ch=getchar ();
	while (!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while (isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
void write (int x) {
	if(x<0) {putchar('-');x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+48);
}
int ttmp=0;
int n,m,a[N],dp[N];
const int mod=998244353;
void dfs (int nx,int sum,int now,int ns) {
	if(now>nx) {
		if(sum<ns) ttmp++;
		ttmp%=mod;
		return ;
	} if(sum<ns) {
		int s=nx-now,x=1;
		for(int i=1;i<=s;i++) 
			x*=2,x%=mod;
		ttmp+=x;
		ttmp%=mod;
		return ;
	}
	dfs(nx,sum,now+1,ns+a[now]);
	dfs(nx,sum,now+1,ns);
}
signed main () {
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	if(a[n]==1) {//test 15-20
		int ans=1;
		for(int i=1;i<n;i++)
			ans*=2,ans%=mod;
		cout<<(mod+ans-n)%mod<<'\n';
	} 
	else
	 {//otherwise
		int sum=a[1]+a[2];
		for (int i=3;i<=n;i++) {
			ttmp=0;
			dfs(i-1,a[i],1,0);
			dp[i]+=ttmp;
			dp[i]+=dp[i-1];
			sum+=a[i];
			dp[i]%=mod;
		} cout<<dp[n]<<'\n';
	}
	return 0;
}
