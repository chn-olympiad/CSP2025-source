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

inline void read (int& x) {
	int sgn=0;char ch=getchar() ;x=0;
	while(!isdigit(ch)) sgn|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	sgn?x=-x:1;
}

const int M=3e5+10 ;
const int p=998244353;

int expow(int x,int y) {
	int res=1;
	for(;y;y>>=1,x=x*x%p) if(y&1) res=res*x%p;
	return res;
}
inline int Inv(int x) {
	return expow(x,p-2) ;
}

int fr[M] ;
int ifr[M] ;

void Init (int M=M-1) {
	fr[0]=ifr[0]=1;
	for(int i=1;i<=M;i++) fr[i]=fr[i-1]*i%p;
	ifr[M] =Inv(fr[M]) ;
	for(int i=M-1;i;i--) ifr[i]=ifr[i+1]*(i+1)%p;
}
inline int C(int n,int m) {
	if(n<0||m<0||n<m) return 0;
	return fr[n]*ifr[m]%p*ifr[n-m]%p;
}

int n,m;

char s[M] ;
int c[M] ;
int sum[M] ;

int f[2][510][510] ;

void solve() {
	read(n);read(m) ;
	scanf("%s",s+1) ;
	for(int i=1;i<=n;i++) {
		int x;read(x) ;c[x]++;
	}
	
	sum[0]=c[0];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+c[i] ;
	
	int s0=0;
	
	int Ans=0;
	
	f[0][0][0]=1;
	for(int i=0,o=1;i<n;i++,o^=1) {
		for(int j=0;j<m;j++) {
			for(int k=0;k<=j;k++) f[o][j][k]=0;
		}
		s0+=(s[i+1]=='0') ;
		for(int j=0;j<m;j++) {
			for(int k=0;k<=j;k++) {
				if(!f[o^1][j][k]) continue;
				int s=c[i-j+1] ;
				for(int t=0;t<=k&&t<=s;t++) {
					if(::s[i+1]=='1') (f[o][j][k-t]+=f[o^1][j][k]*(sum[i-j]+k-i+s0)%p*C(s,t)%p*C(k,t)%p*fr[t])%=p;
					else (f[o][j][k-t]+=f[o^1][j][k]*C(s,t)%p*C(k,t)%p*fr[t])%=p;
				}
				if(::s[i+1]=='1') {
					if(j==m-1) {
						(Ans+=f[o^1][j][k]*C(sum[n]-sum[i-j],k+1)%p*fr[k+1]%p*fr[s0+n-i-1])%=p;
					}
					else (f[o][j+1][k+1]+=f[o^1][j][k])%=p;
				} 
			}
		}
		
		
		
//		for(int j=0;j<=i;j++) {
//			for(int k=0;j+k<=i;k++) cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<"\n";
//		}
		
	}
	
	cout<<Ans%p;
	
}

bool Med ;

signed main() {
	
	ReadIn("employ.in");
	OutPut("employ.out");
//	
	Init() ;
//	
	solve() ;
	
	cerr<<"\n" ;
	cerr<<1.0*clock () /CLOCKS_PER_SEC*1000<<" ms\n" ;
	cerr<<(&Med-&Mst) /1024.0/1024.0<<" mb\n" ;
	
	return 0;
}