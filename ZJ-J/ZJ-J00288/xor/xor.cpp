#include<iostream>
#include<climits>
#include<cstdio>
using namespace std;
int n,k,a[500005];
long long ans=0;
bool vis[500005];
void dfs(int begin,int end,int xxor){
	if(xxor==k){ans++;return;}
	for(int i=end+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(begin,i,xxor^a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}dfs(1,1,0);
	printf("%lld\n",ans);
	return 0;
}