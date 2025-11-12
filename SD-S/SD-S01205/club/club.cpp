#include<bits/stdc++.h>
using namespace std;

#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif

typedef long long ll;
typedef pair<ll,ll>pll;

inline ll max(const ll&a,const ll&b,const ll&c){
	return max(a,max(b,c));
}

inline ll min(const ll&a,const ll&b,const ll&c){
	return min(a,min(b,c));
}

template<typename T>
inline void read(T&a){
	a=0;
	bool f=0;
	char c=gc();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=1;
		}c=gc();
	}while(c>='0'&&c<='9'){
		a=(a<<3)+(a<<1)+(c&15);
		c=gc();
	}a=f?~a+1:a;
	return;
}

template<typename T,typename...Tp>
inline void read(T&a,Tp&...b){
	read(a);
	read(b...);
	return;
}

template<typename T>
inline void write(T a){
	if(a<0){
		pc('-');
		a=~a+1;
	}if(a>=10){
		write(a/10);
	}pc(a%10+'0');
	return;
}

inline void write(char a){
	pc(a);
	return;
}

template<typename T,typename...Tp>
inline void write(T a,Tp...b){
	write(a);
	write(b...);
	return;
}

ll t,n,a[111111][5],cnt[5];
ll ans=0;

void dfs(ll u,ll ret){
	if(u==n){
		ans=max(ans,ret);
		return;
	}
	for(ll i=1;i<=3;i++){
		if(cnt[i]>=n/2){
			continue;
		}
		cnt[i]++;
		dfs(u+1,ret+a[u+1][i]);
		cnt[i]--;
	}return;
}

void run(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		ans=0;
		for(ll i=1;i<=n;i++){
			read(a[i][1],a[i][2],a[i][3]);
		}dfs(0,0);
		write(ans,'\n');
	}
	return;
}

int main(){
	run();
	return 0;
} 
