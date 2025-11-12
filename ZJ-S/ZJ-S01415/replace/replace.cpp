#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1000005;
int n,Q,hshv[maxn][2],siz[maxn],hsht[maxn][2],w[maxn];
char s1[maxn],s2[maxn];
char t1[maxn],t2[maxn];
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
using namespace dhcio;
inline int get(int flg,int L,int R){return hsht[R][flg]-hsht[L-1][flg]*w[R-L+1];}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),Q=read();
	w[0]=1;
	for(int i=1;i<=1000000;i++) w[i]=w[i-1]*27;
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);siz[i]=len;
		for(int j=1;j<=len;j++) hshv[i][0]=hshv[i][0]*27+(s1[j]-'a'+1);
		for(int j=1;j<=len;j++) hshv[i][1]=hshv[i][1]*27+(s2[j]-'a'+1);
	}
	while(Q--){
		scanf("%s%s",t1+1,t2+1);
		int len=strlen(t1+1);
		for(int i=1;i<=len;i++) hsht[i][0]=hsht[i-1][0]*27+(t1[i]-'a'+1);
		for(int i=1;i<=len;i++) hsht[i][1]=hsht[i-1][1]*27+(t2[i]-'a'+1);
		int ans=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j+siz[i]-1<=len;j++)
		  ans+=(get(0,1,j-1)==get(1,1,j-1)&&get(0,j+siz[i],len)==get(1,j+siz[i],len)&&get(0,j,j+siz[i]-1)==hshv[i][0]&&get(1,j,j+siz[i]-1)==hshv[i][1]);
		printf("%lld\n",ans);
	}
	return 0;
}
