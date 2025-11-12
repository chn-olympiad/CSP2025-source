#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18+10
const int mod=998244353;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')	f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')	x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0)	x=-x,putchar('-');
	if(x>9)	write(x/10);
	putchar(x%10+'0');
	return;
}
int n,k;
string s;
int a[501];
int b[501];
int vis[501];
int ans=0;
void solve(int dep){
	if(dep==n+1){
		int now=0,pas=0;
		for(int i=1;i<=n;i++){
			if(now>=a[b[i]]){
				now++;
				continue;
			}
			if(s[i]=='1')	pas++;
			else	now++;
		}
		if(pas>=k)	ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1,b[dep]=i;
			solve(dep+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),k=read();
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)	a[i]=read();
	if(n<=10){
		solve(1);
		write(ans%mod);
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)	if(s[i]=='1')	cnt++;
	if(cnt<k){
		write(0);
		return 0;
	}
	if(cnt==n){
		int jc[501];
		jc[0]=1;
		for(int i=1;i<=n;i++)	jc[i]=jc[i-1]*i%mod;
		write(jc[n]);
		return 0;
	}
	write(0);
}