#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
const int N=500005;
int n,k;
int a[N];
namespace Force{
	const int NN=1005;
	int me[NN][256][2];
	bool hm[NN][256][2];
	int dfs(int x,int num,bool f){
		if(x>n) return (num==k&&f)?1:0;
		if(hm[x][num][f])return me[x][num][f];
		int ans=-0x3f3f3f3f;
		if(f){
			ans=std::max(ans,dfs(x+1,num^a[x],true));
			if(num==k) ans=std::max(ans,dfs(x,0,false)+1);
		}else{
			ans=std::max(ans,dfs(x+1,0,false));
			ans=std::max(ans,dfs(x+1,a[x],true));
		}
		hm[x][num][f]=true;
		return me[x][num][f]=ans;
		
	}
	void solve(){
		printf("%d\n",dfs(1,0,false));
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("force3.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	Force::solve();
	return 0;
}
