#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cassert>
int T,n;
const int maxn=1e5+5;
struct item{
	int a,b,c;
}v[maxn];
namespace Force{
	const int fmaxn=205;
	bool hasmem[fmaxn][fmaxn][fmaxn];int mem[fmaxn][fmaxn][fmaxn];
	int dfs(int a,int b,int c){
		int x=a+b+c+1;
		if(x>n) return 0;
		if(hasmem[a][b][c]) return mem[a][b][c];
		int max_=-0x3f3f3f3f;
		if(a+1<=n/2) max_=std::max(max_,dfs(a+1,b,c)+v[x].a);
		if(b+1<=n/2) max_=std::max(max_,dfs(a,b+1,c)+v[x].b);
		if(c+1<=n/2) max_=std::max(max_,dfs(a,b,c+1)+v[x].c);
		hasmem[a][b][c]=true,mem[a][b][c]=max_;
		return max_;
	}
	void solve(){
		for(int i=0;i<fmaxn;i++)
			for(int j=0;j<fmaxn;j++)
				for(int k=0;k<fmaxn;k++)
					hasmem[i][j][k]=false,mem[i][j][k]=0;
		printf("%d\n",dfs(0,0,0));
	}
}
bool cmp(item a,item b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&v[i].a,&v[i].b,&v[i].c);
		bool flag=true;
		for(int i=1;i<=n;i++) if(!(v[i].b==v[i].c&&v[i].c==0)) flag=false;
		if(flag){
			std::sort(v+1,v+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++) sum+=v[i].a;
			printf("%d\n",sum);
		}else Force::solve();
	}
	return 0;
}
