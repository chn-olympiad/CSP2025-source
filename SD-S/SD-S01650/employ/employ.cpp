#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<chrono>
#include<cstdio>
#include<random>
#include<string>
#include<ctime>
#define INF 0x3f3f3f3f
using namespace std;
#ifdef __linux__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif
inline bool blank(const char x){
	return !(x^32)||!(x^10)||!(x^13)||!(x^9);
}
template<typename Tp>
inline void read(Tp &x){
	x=0;
	bool f=1;
	char ch=gc();
	for(;ch<'0'||'9'<ch;ch=gc())
		if(ch=='-') f=0;
	for(;'0'<=ch&&ch<='9';ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	x=(f?x:~x+1);
}
inline void read(char &x){
	for(;blank(x)&&(x^-1);x=gc());
}
inline void read(char *x){
	char ch=gc();
	for(;blank(ch)&&(ch^-1);ch=gc());
	for(;!blank(ch)&&(ch^-1);ch=gc())
		*x++=ch;
	*x=0;
}
inline void read(string &x){
	x="";
	char ch=gc();
	for(;blank(ch)&&(ch^-1);ch=gc());
	for(;!blank(ch)&&(ch^-1);ch=gc())
		x+=ch;
}
template<typename T,typename ...Tp>
inline void read(T &x,Tp &...y){
	read(x),read(y...);
}
mt19937 rnd(time(0));
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	unsigned long long x=rnd();
	printf("%llu",x);
	return 0;
}

