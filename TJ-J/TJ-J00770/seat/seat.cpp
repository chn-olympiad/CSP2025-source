#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

template <typename T>
bool tense(T &a,const T &b){
	if(a>b){
		a=b;
		return true;
	}return false;
}
template <typename T>
bool relax(T &a,const T &b){
	if(a<b){
		a=b;
		return true;
	}return false;
}

namespace Force{
	int n,m;
	const int maxn=30;
	int c[maxn][maxn],a[maxn*maxn];
	bool is_v(int x,int y){return 1<=x&&x<=n&&1<=y&&y<=m;}
	void dfs(int x,int y,int i,bool f){
		if(!is_v(x,y)||i>n*m) return;
		c[x][y]=i;
		if(f){
			int tx=x+1;
			if(is_v(tx,y)) dfs(tx,y,i+1,f);
			else dfs(x,y+1,i+1,!f);
		}else{
			int tx=x-1;
			if(is_v(tx,y)) dfs(tx,y,i+1,f);
			else dfs(x,y+1,i+1,!f);
		}
	}

	bool cmp(int x,int y){return x>y;}
	void solve(){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
		int t=a[1];
		std::sort(a+1,a+n*m+1,cmp);
		dfs(1,1,1,true);
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=m;j++) printf("%d ",c[i][j]);
		// 	puts("");
		// }
		int ansx=-1,ansy=-1;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[c[i][j]]==t){
			ansx=i,ansy=j;
		}
		assert(ansx!=-1&&ansy!=-1);
		printf("%d %d\n",ansy,ansx);
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	Force::solve();

	return 0;
}