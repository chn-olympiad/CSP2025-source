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
namespace Better{
	int b[N];
	int me[N];
	bool hm[N];
	int dfs(int x){
		if(x>n) return 0;
		if(hm[x])return me[x];
		int ans=-0x3f3f3f3f;
		ans=std::max(ans,dfs(x+1));
		for(int i=x;i<=n;i++){
			if((b[i]^b[x-1])==k) ans=std::max(ans,dfs(i+1)+1);
		}
		hm[x]=true;
		return me[x]=ans;
		
	}
	void solve(){
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]^a[i];
		}
		printf("%d\n",dfs(1));
	}
}
namespace Better1{
	const int M=(1<<20)+5;
	int b[N];
	int dp[N];
	int get(int x){
		if(x>n) return 0;
		return dp[x];
	}
	int t[M];
	void solve(){
		for(int i=1;i<=n;i++){
			b[i]=b[i-1]^a[i];
		}
		for(int i=0;i<=(1<<20);i++){
			t[i]=-0x3f3f3f3f;
		}
		for(int x=n;x>=1;x--){
			int ans=-0x3f3f3f3f;
			t[b[x]]=std::max(t[b[x]],get(x+1)+1);
			ans=std::max(ans,get(x+1));
			ans=std::max(ans,t[(k^b[x-1])]);
			/*
			for(int i=x;i<=n;i++){
				if((b[i])==(k^b[x-1])) ans=std::max(ans,get(i+1)+1);
			}
			*/
			dp[x]=ans;
		}
		
		printf("%d\n",get(1));
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//Force::solve();
	Better1::solve();
	return 0;
}
