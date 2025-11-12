#include<bits/stdc++.h>
#define ll long long
#define debug printf("!!!\n")
using namespace std;
ll read(){
	char c=getchar();
	ll x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-') f=-1;
	}
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(ll x,char c){
	write(x);putchar(c);
}
const ll N=5005,mod=998244353,V=1e4;
ll n,a[N],f[2][V+5][2],ans,pw[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();pw[0]=1;
	for(ll i=1;i<=n;i++) pw[i]=(pw[i-1]<<1)%mod;
	for(ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(ll i=0;i<a[1];i++) f[1][i][1]=1;
	for(ll i=2;i<=n;i++){
		ll now=i&1,lst=!now;
		for(ll j=0;j<=V;j++){
			f[now][j][0]=(f[lst][j][0]+f[lst][j][1])%mod;
			if(j>=a[i]) f[now][j][1]=(f[lst][j-a[i]][0]+f[lst][j-a[i]][1])%mod;
			else f[now][j][1]=pw[i-1];
		}
		if(i>=3) ans=(ans+f[now][2*a[i]][1])%mod;
	}
	write(ans,'\n');
	return 0;
}
/*
5
1 2 3 4 5
*/
