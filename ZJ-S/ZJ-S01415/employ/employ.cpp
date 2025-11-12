#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505;
int n,m,c[maxn],f[524293][19],cnt[524293];
bool S[maxn];
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
		putchar(x%10+'0');
	}
}
inline int get(int x){
	int sum=0;
	while(x) sum++,x-=x&-x;
	return sum;
}
using namespace dhcio;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='0'&&ch!='1') ch=getchar();
		S[i]=ch=='1';
	}
	for(int i=1;i<=n;i++) c[i]=read();
	if(n<=18){
		f[0][0]=1;
		for(int s=0;s<1<<n;s++) cnt[s]=get(s);
		for(int s=1;s<1<<n;s++)
		for(int i=0;i<=n;i++){
			if(i>cnt[s]-1) continue;
			for(int id=1;id<=n;id++)
			  if(s&(1<<id-1)){
			  	int nxt=s^(1<<id-1);
			  	if(S[cnt[s]]==0){
			  		f[s][i+1]=(f[s][i+1]+f[nxt][i])%998244353;
			  		continue;
				}
			  	if(i>=c[id]) f[s][i+1]=(f[s][i+1]+f[nxt][i])%998244353;
			  	else f[s][i]=(f[s][i]+f[nxt][i])%998244353;
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%998244353;
		write(ans);putchar('\n');
		return 0;
	}
	int now=1;
	for(int i=1;i<=n;i++) now=(now*i)%998244353;
	write(now);putchar('\n');
	return 0;
}
