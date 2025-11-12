//dhc 9:20 AK CSP-j
//zh  8:29 AK CSP-j
// /bx /bx /bx zh Orz Orz Orz
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int TT=998244353,maxn=5005,lim=10001;
int n,a[maxn],f[lim+5],sum,ans[maxn],now;
namespace dhcio{
	inline int read(){
		char ch=getchar();int ret=0,f=1;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
		while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
		return ret*f;
	}
	inline void write(int x){
		if(x<0) x=-x;
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
}
using namespace dhcio;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	sort(a+1,a+1+n);f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=min(lim,sum);j++) ans[i]=(ans[i]+f[j])%TT;
		f[lim]=f[lim]*2%TT;
		for(int j=min(lim-1,sum);j>=0;j--) f[min(lim,j+a[i])]=(f[min(lim,j+a[i])]+f[j])%TT;
	}
	for(int i=1;i<=n;i++) now=(now+ans[i])%TT;
	write(now);putchar('\n');
	return 0;
}