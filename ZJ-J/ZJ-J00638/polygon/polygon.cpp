#include <bits/stdc++.h>
using namespace std;
int n,a[5020],ans;
int dp[5020][5020][2];//ijk:前ｉ根木棍选ｊ根，第ｉ根选或不选 
void dfs(int index,bool f,int maxn,int add,int len){//当前木棍下标，是否选，最大值，长度和，木棍数 
	if(len<3 && index+1<=n){
		dfs(index+1,1,max(maxn,a[index+1]),add+a[index+1],len+1);
		dfs(index+1,0,maxn,add,len);
	}else if(index+1<=n){
		if(add>2*maxn && f) ans=(ans+1)%998244353;
		dfs(index+1,1,max(maxn,a[index+1]),add+a[index+1],len+1);
		dfs(index+1,0,maxn,add,len);
	}else if(index==n){
		if(add>2*maxn && f) ans=(ans+1)%998244353;
	}
	return;
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1,1,a[1],a[1],1);
	dfs(1,0,0,0,0);
	printf("%d",ans);
	
	return 0;
}
