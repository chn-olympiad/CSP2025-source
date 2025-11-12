#include <cstdio>
#include <algorithm>

const int mod=998244353;
const int maxn=5005;
int a[maxn];
int n;

int dfs(int len,int s,int maxa){
	if(len==n) return s>2*maxa;
	
	int ans=0;
	ans=(ans+dfs(len+1,s,maxa))%mod;
	ans=(ans+dfs(len+1,s+a[len+1],std::max(maxa,a[len+1])))%mod; 
	return ans%mod;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	printf("%d\n",dfs(0,0,0)%mod);
	return 0;
}
