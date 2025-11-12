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
const int maxn=1e5+5;
int T;
int n;
priority_queue<int> c[10];
int ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while (T--){
		read(n);
		while (!c[1].empty()) c[1].pop();
		while (!c[2].empty()) c[2].pop();
		while (!c[3].empty()) c[3].pop();
		ans=0;
		for (int i=1;i<=n;i++){
			int a,b,cc;read(a,b,cc);
			int maxx=max(a,max(b,cc));
			if (maxx==a) c[1].push(max(b,cc)-maxx);
			else if (maxx==b) c[2].push(max(a,cc)-maxx);
			else if (maxx==cc) c[3].push(max(a,b)-maxx);
			ans+=maxx;
		}
		for (int i=1;i<=3;i++){
			if (c[i].size()>n/2){
				while (c[i].size()>n/2)
					ans+=c[i].top(),c[i].pop();
			}
		}
		printf("%lld\n",ans);
	}


	return 0;
}


//15:03左右 A掉所有样例 




