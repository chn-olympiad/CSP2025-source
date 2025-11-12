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

const ll p=107;

const ll md=5e6+7;

ll n,q;
char s[5555555],t[5555555],t1[5555555],t2[5555555];
ll sl[222222],slen[222222],fid[5555555];
ll has[5555555],hap[2][5555555];
ll pw[5555555];
ll hasx[222222];

inline ll make_hash(ll*ha,ll l,ll r){
	if(l==0){
		return ha[r];
	}return (ha[r]+md-(ha[l-1]*pw[r-l])%md)%md;
}

void run(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	memset(fid,-1,sizeof(fid));
	read(n,q);
	for(ll i=1;i<=n*2;i++){
		sl[i]=sl[i-1]+slen[i-1];
		read(s+sl[i]);
		slen[i]=strlen(s+sl[i]);
	}ll lens=strlen(s);
	pw[0]=1;
	for(ll i=1;i<lens;i++){
		pw[i]=(pw[i-1]*p)%md;
	}has[0]=s[0];
	for(ll i=1;i<lens;i++){
		has[i]=((has[i-1]+s[i])%md;
	}for(ll i=1;i<=2*n;i++){
		hasx[i]=make_hash(has,sl[i],sl[i]+slen[i]-1);
		if(i%2){
			fid[hasx[i]]=i;
		}
	}//write(slen[1],' ',slen[2],'\n');
	//write(hasx[1],' ',hasx[2],'\n');
	ll cnt=0;
	while(q--){
		cnt=0;
		read(t1,t2);
		ll len=strlen(t1);
		for(ll i=lens;i<len;i++){
			pw[i]=(pw[i-1]*p)%md;
		}hap[0][0]=t1[0];
		hap[0][1]=t2[0];
		for(ll i=1;i<len;i++){
			hap[0][i]=((hap[0][i-1]*pw[i])%md+t1[i])%md;
		}for(ll i=1;i<len;i++){
			hap[1][i]=((hap[1][i-1]*pw[i])%md+t2[i])%md;
		}//write(make_hash(hap[0],0,len-1),' ',make_hash(hap[1],0,len-1),'\n');
		for(ll i=0;i<len;i++){
			for(ll j=i;j<len;j++){
				ll ha=make_hash(hap[0],i,j);
				if(fid[ha]!=-1&&hasx[fid[ha]+1]==make_hash(hap[1],i,j)){
					cnt++;
				}
			}
		}write(cnt,'\n');
	}
	return;
}

int main(){
	run();
	return 0;
} 
