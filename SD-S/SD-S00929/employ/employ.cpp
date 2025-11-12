#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(auto i=(a);i<=(b);i++)
#define REP(i,a,b) for(auto i=(a);i>=(b);i--)
#define FORK(i,a,b,k) for(auto i=(a);i<=(b);i+=(k))
#define REPK(i,a,b,k) for(auto i=(a);i>=(b);i-=(k))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
#define mkpr make_pair
#define fi first
#define se second
#define gc getchar()
#define pc putchar
#define pln pc(10);
#define eb emplace_back
template<class T>
void ckmx(T& a,T b){
	a=max(a,b);
}
template<class T>
void ckmn(T& a,T b){
	a=min(a,b);
}
template<class T>
T gcd(T a,T b){
	return !b?a:gcd(b,a%b);
}
template<class T>
T lcm(T a,T b){
	return a/gcd(a,b)*b;
}
template<class T>
void read(T& x){
	x=0;
	int f=1;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=gc;
	}
	x*=f;
}
template<class T>
void write(T x){
	if(x<0){
		pc('-');
		x=-x;
	}
	if(x>=10)write(x/10);
	pc(x%10^48);
}
template<class T>
void writeln(T x){
	write(x);
	pln
}
void io(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
bool at(int s,int i){
	return (s&(1<<i-1));
}
const int mod=998244353;
const int maxn=505;
int n,m;
int c[maxn];
char s[maxn];
int f[1<<20][20];
void solve(int id_of_testcases){
	read(n);
	read(m);
	scanf("%s",s+1);
	FOR(i,1,n){
		read(c[i]);
	}
	int all=(1<<n)-1;
	f[0][0]=1;
	FOR(msk,0,all){
		int pos=__builtin_popcount(msk)+1;
		FOR(num,0,pos-1){
			FOR(i,1,n){
				if(at(msk,i)){
					continue;
				}
				if(s[pos]=='1'&&pos-1-num<c[i]){
					(f[msk|(1<<i-1)][num+1]+=f[msk][num])%=mod;
				}else{
					(f[msk|(1<<i-1)][num]+=f[msk][num])%=mod;
				}
			}
		}
	}
	int ans=0;
	FOR(i,m,n){
		(ans+=f[all][i])%=mod;
	}
	printf("%d\n",(ans%mod+mod)%mod);
}
int main(){
	io();
	int T;
	T=1;
	FOR(_,1,T){
		solve(_);
	}
	return 0;
}

