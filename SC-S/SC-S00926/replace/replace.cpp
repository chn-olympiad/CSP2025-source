#include<bits/stdc++.h> 
using namespace std ;

#define int ll
typedef long long ll; 
typedef unsigned long long ull ;

#define sz(x) (int)(x.size()) 
#define eb emplace_back 
#define btpc(x) __builtin_popcount(x) 
#define btpcll(x) __builtin_popcountll(x)

#define ReadIn(s) freopen(s,"r",stdin)
#define OutPut(s) freopen(s,"w",stdout)

bool Mst ;

const int M=5e6+10 ;

const ull B=13331;

inline void read (int& x) {
	int sgn=0;char ch=getchar() ;x=0;
	while(!isdigit(ch)) sgn|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	sgn?x=-x:1;
}

int n,q;

char s[M] ;
char t[M] ;

pair<ull,ull> ha[M] ;

map<pair<ull,ull> ,int>mp ;

void solve() {
	read(n);read(q) ;
	for(int i=1;i<=n;i++) {
		ull ha1=0,ha2=0;
		scanf("%s",s+1) ;
		int l=strlen(s+1) ;
		for(int j=1;j<=l;j++) {
			ha1=ha1*B+s[j] ;
		}
		scanf("%s",s+1) ;
		for(int j=1;j<=l;j++) {
			ha2=ha2*B+s[j] ;
		}
		ha[i]=make_pair(ha1,ha2) ;
	}
	
	for(int i=1;i<=q;i++) {
		scanf("%s%s",s+1,t+1) ;
		int l=strlen(s+1) ;
		int st=1,e=l;
		for(int i=1;i<=l;i++) {
			if(s[i]!=t[i]) break ;
			st++ ;
		}
		for(int i=l;i;i--) {
			if(s[i]!=t[i]) break;
			e--;
		}
		
		mp.clear() ;
		
		for(int x=1;x<=l;x++) {
			ull ha1=0,ha2=0;
			for(int y=x;y<=l;y++) {
				ha1=ha1*B+s[y] ;
				ha2=ha2*B+t[y] ;
				if(x<=st&&y>=e) mp[make_pair(ha1,ha2)]++;
			}
		}
		
		int Ans = 0;
		
		for(int i=1;i<=n;i++) {
			Ans+=mp[ha[i]] ;
		}
		
		cout<<Ans <<"\n" ;
		
	}
	
}

bool Med ;

signed main() {
	ReadIn("replace.in");
	OutPut("replace.out");
	
	solve() ;
	
	cerr<<"\n" ;
	cerr<<1.0*clock () /CLOCKS_PER_SEC*1000<<" ms\n" ;
	cerr<<(&Med-&Mst) /1024.0/1024.0<<" mb\n" ;
	
	return 0;
}