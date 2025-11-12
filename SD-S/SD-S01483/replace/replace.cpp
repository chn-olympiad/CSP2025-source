#include <bits/stdc++.h>
/*
洛天依赐我力量
lxl赐我力量
珂朵莉赐我力量
奈芙莲赐我力量
瑟尼欧里斯赐我力量
二阶堂希罗赐我力量
樱羽艾玛赐我力量
ksm赐我力量
ykn赐我力量
ppp赐我力量
Roselia赐我力量
让我拿到7级钩吧！！！！！！
关注洛谷:978535(好像是)--Kayisama
*/
using namespace std;
#define lowbit(x) ((x)&(-(x)))
inline void read(){}
template <typename T,typename... R>
inline void read(T& r,R&... oth){
	r=0;T f=1;char c=getchar();
	while (c<'0' || c>'9') {
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9') r=(r<<3)+(r<<1)+(c&15),c=getchar();
	r*=f;
	read(oth...);
	return;
}
template<typename T>
T gcd(T a,T b){
	return b<=0?a:gcd(b,a%b);
}
template<typename T>
T exgcd(T a,T b,T& x,T& y){
	if (b<=0){
		x=1,y=0;
		return a;
	}
	T d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
template<typename T>
T qpow(T a,T n,T p){
	T res=1;
	for(;n;n>>=1ll){
		if (n&1ll) res=(res*a)%p;
		a=(a*a)%p;
	}
	return res;
}
//const int luotianyi=0x66ccff
#define int long long
const int maxn=6e6+5;
int n,q;
string s[maxn][3];
int ans;
bitset<maxn> vis;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n,q);
	for (int i=1;i<=n;i++){
		string sa,sb;cin>>sa>>sb;
		s[i][1]=sa,s[i][2]=sb;
	}
	while (q--){
		ans=0;vis=0;
		string ss,tt;cin>>ss>>tt;
		for (int i=0;i<ss.length();i++){
			for (int j=1;j<=n;j++){
				if (i+s[j][1].length()-1>ss.length()) continue;
				string ts=ss;
				for (int k=0;k<s[j][1].length();k++){
					if (ts[i+k]!=s[j][1][k]) goto nxt;
					ts[i+k]=s[j][2][k];
				}
				if (ts==tt) vis[j]=1;
				nxt:
				ss=ss;
			}
		}
		for (int i=1;i<=n;i++) if (vis[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/





