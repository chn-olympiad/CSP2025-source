#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb emplace_back
#define mk make_pair
#define ll long long
#define fi first
#define se second
#ifdef int
#define inf ((1e18)+10)
#else 
#define inf ((1e9)+10)
#endif
//#define ls (now<<1)
//#define rs (now<<1|1)
//#define mid ((l+r)>>1)
using namespace std;
bool Mst;
const int Max=2e5+10;
const int mod=998244353;
const double eps=1e-9;


inline int read(){
	int res=0,v=1;
	char c=getchar();
	while(c<'0'||c>'9'){v=(c=='-'?-1:1);c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res*v;
}

int a[Max][4];
int siz[4];
void work(){
	priority_queue<pii,vector<pii>,greater<pii> >p[4];
	int n=read();
	siz[1]=siz[2]=siz[3]=0;
	for(int i=1;i<=n;++i){
		int v=0;
		for(int j=1;j<=3;++j){
			a[i][j]=read();
			if(a[i][j]>a[i][v])v=j;
		}
		int R=0;
		for(int j=1;j<=3;++j){
			if(j==v)continue;
			if(a[i][j]>a[i][R])R=j;
		}
		p[v].push(mk(a[i][v]-a[i][R],i));
		++siz[v];
		if(siz[v]>n/2){
			pii z=p[v].top();p[v].pop();
			--siz[v];
			int val=z.se,R=0;
			for(int j=1;j<=3;++j){
				if(j==v)continue;
				if(a[val][j]>a[val][R])R=j;
			}
			p[R].push(mk(a[val][R],val));
			++siz[R];
		}
	}
	int ans=0;
	for(int i=1;i<=3;++i){
		while(!p[i].empty()){ans+=a[p[i].top().se][i];p[i].pop();}
	}
	cout << ans << "\n";
}


bool Med;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)work();
//	cerr << "Time: "<< clock()/1000.0 << "s\n";
//	cerr << "Me: "<< abs(&Mst-&Med)/1048576.0 << "MB\n";
	return 0;
}
/*
考虑反悔贪心。

*/