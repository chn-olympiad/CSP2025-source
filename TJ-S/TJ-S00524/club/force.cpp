#include<cstdio>
#include<algorithm>
template <typename T> bool tense(T &a,const T &b){return b<a?a=b,true:false;}
template <typename T> bool relax(T &a,const T &b){return b>a?a=b,true:false;}

const int MAXN = 1e5+10;
int a[MAXN][5];
int n;

namespace Force{
	const int N = 210,INF = 2e9+10;
	bool mem[N][N][N];
	int f[N][N][N];
	
	int dfs(int i,int j,int k){
		int now = i+j+k;
		if(now>n) return 0;
		if(mem[i][j][k]) return f[i][j][k];
		int res = -INF;
		if(i+1<=n/2) relax(res,dfs(i+1,j,k)+a[now][1]);
		if(j+1<=n/2) relax(res,dfs(i,j+1,k)+a[now][2]);
		if(k+1<=n/2) relax(res,dfs(i,j,k+1)+a[now][3]);
		mem[i][j][k] = true;
		return f[i][j][k] = res;
	}
	void solve(){
		for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int k=0;k<=n;k++) mem[i][j][k] = false;
		printf("%d\n",dfs(0,0,0));
	}
}
namespace SpecialB{
	int d[MAXN];
	
	void solve(){
		for(int i=1;i<=n;i++) d[i] = a[i][2] - a[i][1];
		std::sort(d+1,d+n+1);
		int res = 0;
		for(int i=1;i<=n;i++) res+=a[i][1];
		for(int i=n;i>n/2;i--) res+=d[i];
		printf("%d\n",res);
	}
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) scanf("%d",&a[i][j]);
	if(n<=200){
		Force::solve();
		return;
	}
//	bool flagb = true;
//	for(int i=1;i<=n;i++) flagb&=(a[i][3]==0);
//	if(flagb){
//		SpecialB::solve();
//		return;
//	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("force.out","w",stdout);
//	Force::solve();
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}


