#include <cstdio>
namespace h_2{
	const int maxn=100000+4;
	int n;
	int a[maxn][7];
	int dfs(int now,int c1,int c2,int c3){
		int ans=0;
		if(now>n) return 0;
		int m=dfs(now+1,c1,c2,c3);
		ans=m>ans?m:ans;
		if(c1>0) m=dfs(now+1,c1-1,c2,c3)+a[now][1];
		ans=m>ans?m:ans;
		if(c2>0) m=dfs(now+1,c1,c2-1,c3)+a[now][2];
		ans=m>ans?m:ans;
		if(c3>0) m=dfs(now+1,c1,c2,c3-1)+a[now][3];
		ans=m>ans?m:ans;
		return ans;
	}
	void solve(){
		int T;
		scanf("%d",&T);
		while(T--){
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			printf("%d\n",dfs(1,n/2,n/2,n/2));
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	h_2::solve();
	return 0;
} 
