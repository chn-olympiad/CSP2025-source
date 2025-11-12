#include<bits/stdc++.h>
typedef long long ll;
typedef __int128 lll;
typedef double db;
typedef long double ld;
#define fir first
#define sec second
#define pb push_back
#define ppc __builtin_popcountll
using namespace std;
void rd(){}
template<typename T,typename ...U> void rd(T &x,U &...arg){
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	x*=f;rd(arg...);
}
void rds(char *s){
	int c=getchar();
	while(c<'0'||c>'1') c=getchar();
	while(c>='0'&&c<='1') *s=char(c),s++,c=getchar();
	*s='\0';
}

const int maxn=505,maxv=1005,P=998244353;
template<typename T> inline void inc(T &x,T y){(x+=y)>=P?(x-=P):0;}
template<typename T> inline T mod(T n){return n>=P?n-P:n;}
//inline ll fpow(ll n,ll x);

ll fac[maxv];
ll c[maxv][maxv],dw[maxv][maxv];
inline ll C(int n,int m){
	if(n==m) return 1;
	if(n<m||m<0) return 0;
	return c[n][m];
}
inline ll DW(int n,int m){
	if(n<m||m<0) return 0;
	return dw[n][m];
}

int N,M,pre[maxn],a[maxn];
char s[maxn];

ll f[2][maxn][maxn];

namespace sub1{
void __main(){
	cerr<<"sub1\n";

	int id[15]={},ans=0;
	iota(id+1,id+N+1,1);
	do{
		int n=0;
		for(int i=1;i<=N;i++){
			if(s[i]=='1'&&a[id[i]]>i-1-n)
				n++;
		}
		if(n>=M) ans++;
	}
	while(next_permutation(id+1,id+N+1));

	printf("%d\n",ans);
}
}//namespace sub1

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	for(int i=0;i<maxv;i++){
		c[i][0]=1;
		dw[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=mod(c[i-1][j-1]+c[i-1][j]),
			dw[i][j]=dw[i][j-1]*(i-j+1)%P;
	}
	fac[0]=1;
	for(int i=1;i<maxv;i++) fac[i]=fac[i-1]*i%P;

	rd(N,M);
	rds(s+1);
	for(int i=1;i<=N;i++) rd(a[i]),pre[a[i]]++;

//	if(N<=10){
//		sub1::__main();
//		return 0;
//	}

	for(int i=1;i<=N+1;i++) pre[i]+=pre[i-1];

	int t=0;
	f[0][0][0]=1;
	for(int i=1,n1=0;i<=N;i++){
//		cerr<<"i = "<<i<<"\n";
		t^=1;
		for(int j=0;j<=n1;j++){
			for(int k=0;k<i;k++){
				auto &F=f[!t][j][k];
				if(!F) continue;
//				cerr<<"j = "<<j<<", k = "<<k<<", f = "<<F<<"\n";
				if(s[i]=='0'){
					int num=pre[i-j]-pre[i-j-1];
					for(int x=0;x<=min(num,k);x++){
						if(k-x>pre[N]-pre[i-j]) continue;
						ll coef=C(num,x)*DW(k,x)%P;
						if(pre[i-j]>i-1-(k-x))
							inc(f[t][j][k-x],F*coef%P*(pre[i-j]-(i-1-(k-x)))%P);
						if(pre[N]-pre[i-j]-(k-x)>0)
							inc(f[t][j][k-x+1],F*coef%P);
					}
				}
				else{
					int num=pre[i-j]-pre[i-j-1];
					for(int x=0;x<=min(num,k);x++){
						if(k-x>pre[N]-pre[i-j]) continue;
						ll coef=C(num,x)*DW(k,x)%P;
						if(pre[i-j-1]>i-1-k){
//							cerr<<"to "<<j<<" "<<k-x<<", __F = "<<F*coef%P*(pre[i-j-1]-(i-1-k))%P<<", x = "<<x<<", coef = "<<coef<<"\n";
							inc(f[t][j][k-x],F*coef%P*(pre[i-j-1]-(i-1-k))%P);//do not hire
						}
					}
					if(pre[N]-pre[i-j-1]>k){
//						cerr<<"hire, to "<<j+1<<" "<<k+1<<"\n";
						inc(f[t][j+1][k+1],F);//hire
					}
				}
				F=0;
			}
		}
		n1+=s[i]=='1';
//		for(int j=0;j<=n1;j++)
//			for(int k=0;k<=i;k++)
//				cerr<<f[t][j][k]<<" \n"[k==i];
//		cerr<<"\n";
	}

	ll ans=0;
	for(int i=M;i<=N;i++){
		for(int j=0;j<=N;j++)
			inc(ans,f[t][i][j]*fac[j]%P);
	}
	printf("%lld\n",ans);
	return 0;
}

