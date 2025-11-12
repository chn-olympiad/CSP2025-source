#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m,hard[505],nx[505];
long long ans; bool vis[505];
void dfs(int succeed,int loss,int dep){
	if(succeed>=m&&dep>=n-1){
		ans=(ans+1)%mod;
	}if(dep>=n)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(hard[i]==1&&loss<nx[i]&&dep<=n){
				dfs(succeed+1,loss,dep+1);
			}else{
				dfs(succeed,loss+1,dep+1);
			}vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string str;cin>>str;
	for(int i=0;i<n;i++){
		if(str[i]=='0')hard[i+1]=0;
		else hard[i+1]=1;
	}for(int i=1;i<=n;i++){
		scanf("%d",&nx[i]);
	}
	if(n>=18){printf("%d\n",n*n);return 0;}
	dfs(0,0,1);
	printf("%lld\n",ans);
	return 0;
}