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

inline void read(char*a){
	*a=gc();
	while(*a<=' '){
		*a=gc();
	}while(*a>' '){
		*++a=gc();
	}*a='\0';
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

ll n,m;
char s[555];
ll vis[555],c[555];
ll cnt=0,step=0,nn=0;

void dfs(ll u){
	if(step-nn==m){
		cnt++;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			ll f=0;
			if(nn>=c[i]||s[step]=='0'){
				f=1;
				nn++;
			}step++;
			dfs(i);
			nn-=f;
			step--;
			vis[i]=0;
		}
	}return;
}

void run(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n,m,s);
	for(ll i=1;i<=n;i++){
		read(c[i]);
	}dfs(0);
	write(cnt,'\n');
	return;
}

int main(){
	run();
	return 0;
} 
