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
const int maxn=505;
const int mod=998244353;
int n,m;
string s;
int c[maxn];
int ans; 
bitset<maxn> vis;
void dfs(int now,int pass){
	if (now==n+1) {
		//printf("%d %d\n",now,n-pass);
		if (n-pass>=m) ans=(ans+1)%mod;
		return;
	}
	for (int i=1;i<=n;i++){
		if (!vis[i]){
			vis[i]=1;
			if (c[i]<=pass || s[i-1]=='0') dfs(now+1,pass+1);
			else dfs(now+1,pass);
			vis[i]=0;
		}
	}
	return; 
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n,m);cin>>s;
	for (int i=1;i<=n;i++) read(c[i]);
	dfs(1,0);
	printf("%lld",ans%mod);
	return 0;
} 

//为了你唱下去
//Blessing for your everyday
//夏虫展翅向灼热光明 
//你是我万分之一的光 那么闪耀
//快去玩魔法少女的魔女裁判 



