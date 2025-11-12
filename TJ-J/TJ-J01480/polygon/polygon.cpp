#include <cstdio>
namespace h_3{
	const int maxn=5000+4;
	int n;
	int a[maxn];
	int dfs(int now,int num,int maxa){
		int ans=0;
		if(now>n){
			if(num>maxa*2) return 1;
			return 0;
		}
		ans+=dfs(now+1,num,maxa);
		if(a[now]>maxa) ans+=dfs(now+1,num+a[now],a[now]);
		else ans+=dfs(now+1,num+a[now],maxa);
		return ans;
	}
	void solve(){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",dfs(1,0,0));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	h_3::solve();
}
