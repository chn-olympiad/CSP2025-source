#include<bits/stdc++.h>
#define fir first
#define sec second
#define int long long
#define pii pair<int,int>
#define fep(i,s,e) for(int i=s;i<e;i++)
#define pef(i,s,e) for(int i=s;i>e;i--)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
namespace FastIO{
	template<typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);x*=f;
	}
	template<typename T,typename ...Args>
	inline void read(T &x,Args &...args){
		read(x);read(args...);
	}
	template<typename T>void print(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)print(x/10);
		putchar((x%10)^48);
	}
}
using namespace std;
using namespace FastIO;
const int N=2e5+47,M=5e6+5;
int n,q,l[M],r[M],L,R;
string f[N],t[N],F,T;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n,q);
	rep(i,1,n){
		cin>>f[i]>>t[i];
	}
	while(q--){
		int ans=0;
		cin>>F>>T;
		if(F.size()!=T.size()){
			puts("0");
			continue;
		}
		L=F.size()-1;R=0;
		fep(i,0,F.size()){
			if(F[i]!=T[i]){
				L=min(L,i);
				R=max(R,i);
			}
		}
		int len=R-L+1;
		rep(i,1,n){
			if(f[i].size()<len)continue;
			int st=max((int)(R-f[i].size()-1),0ll);
			rep(ll,st,L){
				int rr=ll+f[i].size()-1,flag=1;
				rep(j,ll,rr){
					if(f[i][j-ll]!=F[j]||t[i][j-ll]!=T[j]){
						flag=0;
						break;
					}
				}
				if(flag==1){
					ans++;
					break;
				}
			}
		}
		print(ans);puts("");
	}
	return 0;
}