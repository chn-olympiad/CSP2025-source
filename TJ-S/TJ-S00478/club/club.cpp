#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long

template <typename T>
bool relax(T &a,const T &b){
	if(a<b){
		a=b;
		return true;
	}return false;
}
template <typename T>
bool tense(T &a,const T &b){
	if(a>b){
		a=b;
		return true;
	}return false;
}

const int INF=0x3f3f3f3f;

namespace Force{
	int n;
	const int maxn=1e5+5;
	int a[maxn][5];
	int b[maxn];

	int ans=0;
	// std::vector<std::pair<int,int>> his;
	void dfs(int x,int c1,int c2,int c3){
		if(x>n){
			int res=0;
			for(int i=1;i<=n;i++) res+=a[i][b[i]];
			relax(ans,res);
				// for(auto i:his) printf("%d %d\n",i.first,i.second);
				// printf("%d\n",ans);
				// puts("");
			// }
			return;
		}
		if(c1<n/2){
			b[x]=1;
			// his.push_back({x,1});
			dfs(x+1,c1+1,c2,c3);
			// his.pop_back();
			
			b[x]=0;
		}
		if(c2<n/2){
			b[x]=2;
			// his.push_back({x,2});
			dfs(x+1,c1,c2+1,c3);
			// his.pop_back();
			b[x]=0;
		}
		if(c3<n/2){
			b[x]=3;
			// his.push_back({x,3});
			dfs(x+1,c1,c2,c3+1);
			// his.pop_back();
			b[x]=0;
		}
	}

	void solve(int _n){
		n=_n;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);

		ans=0;
		dfs(1,0,0,0);
		printf("%d\n",ans);
	}
}

namespace Dp{
	int n;
	const int maxn=1e5+5;
	int a[maxn][5];

	bool hasmem[1005][505][505];
	int mem[1005][505][505];
	int dfs(int x,int c1,int c2){
		int c3=(x-1)-c1-c2;
		// assert(t3==c3);
		if(x>n){
			return 0;
		}
		if(hasmem[x][c1][c2]) return mem[x][c1][c2];
		int ans=-INF;
		if(c1<n/2){
			relax(ans,dfs(x+1,c1+1,c2)+a[x][1]);
		}
		if(c2<n/2){
			relax(ans,dfs(x+1,c1,c2+1)+a[x][2]);
		}
		if(c3<n/2){
			relax(ans,dfs(x+1,c1,c2)+a[x][3]);
		}
		hasmem[x][c1][c2]=true;
		return mem[x][c1][c2]=ans;
	}

	void solve(int _n){
		n=_n;
		for(int i=1;i<=n;i++) for(int j=0;j<=n/2;j++) for(int k=0;k<=n/2;k++) hasmem[i][j][k]=false;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		printf("%d\n",dfs(1,0,0));
	}
}

namespace An{
	int n;
	const int maxn=1e5+5;
	int a[maxn][5];

	struct rec{
		int x,i,f;
		friend bool operator<(const rec &a,const rec &b){return a.x<b.x;}
	};
	std::priority_queue<rec> Q;
	bool choose[maxn];
	int c[10];

	void solve(int _n){
		n=_n;
		while(!Q.empty()) Q.pop();
		for(int i=1;i<=n;i++) choose[i]=false;
		c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;i++) Q.push((rec){a[i][1],i,1}),Q.push((rec){a[i][2],i,2}),Q.push((rec){a[i][3],i,3});
		int ans=0,s=0;
		for(int i=1;i<=n;i++){
			rec t=Q.top();Q.pop();
			while(choose[t.i]||c[t.f]>=n/2) t=Q.top(),Q.pop();
			assert(c[t.f]<n/2&&!choose[t.i]);
			choose[t.i]=true;
			c[t.f]++;
			ans+=t.x;
			s++;
			if(s==n) break;
		}
		printf("%d\n",ans);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n<=4) Force::solve(n);
		else if(n<=200) Dp::solve(n);
		else An::solve(n);
	}

	return 0;
}