#include<bits/stdc++.h>
using namespace std;
const int maxn=500005,maxv=(1<<21)+5;
int n,k,a[maxn],L[maxn],f[maxn],sum[maxn],pos[maxv];
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
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]^a[i];
	memset(pos,-1,sizeof pos);
	pos[0]=0;
	for(int i=1;i<=n;i++){L[i]=pos[sum[i]^k];pos[sum[i]]=i;}
	for(int i=1;i<=n;i++){
		if(L[i]==-1) f[i]=0;else f[i]=f[L[i]]+1;
		f[i]=max(f[i],f[i-1]);
	}
	write(f[n]);putchar('\n');
	return 0;
}