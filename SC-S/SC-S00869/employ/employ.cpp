#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar('0'+x%10);
}
const int N=505,MOD=998244353;
int n,m,s[N],c[N],ord[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)s[i]=getchar()-'0';
	for(int i=1;i<=n;++i)c[i]=read(),ord[i]=i;
	int ans=0;
	do{
		int luqu=0,cnt=0;
		for(int i=1;i<=n;++i){
			if(cnt>=c[ord[i]]||s[i]==0)++cnt;
			else ++luqu;
		}
		ans+=(luqu>=m);
	}while(next_permutation(ord+1,ord+n+1));
	write(ans);
	return 0;
}