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
const int N=1e5+7;
struct node{
	int a,b,c,mx;
}G[N];
int T,n,ans;
vector<int>mxa,mxb,mxc;
bool cmpa(int i,int j){
	int di=min(G[i].a-G[i].b,G[i].a-G[i].c);
	int dj=min(G[j].a-G[j].b,G[j].a-G[j].c);
	return di<dj;
}
bool cmpb(int i,int j){
	int di=min(G[i].b-G[i].a,G[i].b-G[i].c);
	int dj=min(G[j].b-G[j].a,G[j].b-G[j].c);
	return di<dj;
}
bool cmpc(int i,int j){
	int di=min(G[i].c-G[i].a,G[i].c-G[i].b);
	int dj=min(G[j].c-G[j].a,G[j].c-G[j].b);
	return di<dj;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		ans=0;
		mxa.clear();
		mxb.clear();
		mxc.clear();
		read(n);
		rep(i,1,n){
			read(G[i].a,G[i].b,G[i].c);
			if(G[i].a>=G[i].b&&G[i].a>=G[i].c)mxa.emplace_back(i);
			else if(G[i].b>=G[i].a&&G[i].b>=G[i].c)mxb.emplace_back(i);
			else mxc.emplace_back(i);
		}
		int flaga=0,flagb=0,flagc=0;
		if(mxa.size()<=n/2)flaga=1;
		if(mxb.size()<=n/2)flagb=1;
		if(mxc.size()<=n/2)flagc=1;
		fep(i,0,mxa.size())ans+=G[mxa[i]].a;
		fep(i,0,mxb.size())ans+=G[mxb[i]].b;
		fep(i,0,mxc.size())ans+=G[mxc[i]].c;
		if(flaga==0){
			sort(mxa.begin(),mxa.end(),cmpa);
			rep(i,0,mxa.size()-(n/2)-1){
				ans-=min(G[mxa[i]].a-G[mxa[i]].b,G[mxa[i]].a-G[mxa[i]].c);
			}
		}
		if(flagb==0){
			sort(mxb.begin(),mxb.end(),cmpb);
			rep(i,0,mxb.size()-(n/2)-1){
				ans-=min(G[mxb[i]].b-G[mxb[i]].a,G[mxb[i]].b-G[mxb[i]].c);
			}
		}
		if(flagc==0){
			sort(mxc.begin(),mxc.end(),cmpc);
			rep(i,0,mxc.size()-(n/2)-1){
				ans-=min(G[mxc[i]].c-G[mxc[i]].a,G[mxc[i]].c-G[mxc[i]].b);
			}
		}
		print(ans);
		puts("");
	}
	return 0;
}