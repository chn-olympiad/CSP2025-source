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
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
const int maxn=1e5+5;
int a[maxn][3];
int n;
vi rem[3];
void clear(){
	FOR(i,0,2)rem[i].clear();
}
void solve(int id_of_testcases){
	read(n);
	FOR(i,1,n){
		FOR(j,0,2){
			read(a[i][j]);
		}
	}
	int ans=0;
	FOR(i,1,n){
		int mx=0;
		FOR(j,0,2)ckmx(mx,a[i][j]);
		FOR(j,0,2){
			if(a[i][j]==mx){
				rem[j].eb(i);
				break;
			}
		}
		ans+=mx;
	}
//	printf("preans %d\n",ans);
	FOR(i,0,2){
		if(rem[i].size()>n/2){
			for(int& v:rem[i]){
				int tmp=v;
				v=0;
				FOR(j,0,2){
					if(i==j)continue;
					ckmx(v,a[tmp][j]);
				}
				v=v-a[tmp][i];
			}
			sort(rem[i].begin(),rem[i].end());
			while(rem[i].size()>n/2){
				ans+=rem[i].back();
				rem[i].pop_back();
			}
			break;
		}
	}
	printf("%d\n",ans);
	clear();
}
int main(){
	io();
	int T;
	read(T);
	FOR(_,1,T){
		solve(_);
	}
	return 0;
}

