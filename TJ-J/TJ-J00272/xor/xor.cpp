#include <cstdio>
#include <algorithm>

const int maxn=500005;
int a[maxn],s[maxn];
int n,k;

namespace force{

int dfs(int len,int l,int r,int s){
	if(len==n){
		return s==k;
	}
	int ans=dfs(len+1,l,r,s);
	if(r==len) ans=std::max(ans,dfs(len+1,l,r+1,s^a[len+1]));
	else ans=std::max(ans,(s==k)+dfs(len+1,len+1,len+1,a[len+1]));
	return ans;
}

int n_2(){
	if(n==1) return !a[1];
	
	if(a[1]==0&&a[2]==0) return 2;
	return 1;
}

}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	if(n<=2) printf("%d\n",force::n_2());
	else printf("%d\n",force::dfs(1,1,1,0));
	return 0;
}
