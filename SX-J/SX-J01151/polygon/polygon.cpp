#include <bits/stdc++.h>
using namespace std;
int n,inp[5005];//int min_num=INT_MAX;
long long ans=0;
bool used[5005];

void dfs(int wait,int xb){
	if(wait<0){
		ans++;
		ans=ans%998244353;
	}
	for(int i=xb;i>=1;i--){
		if(!used[i]){
			used[i]=true;
			dfs(wait-inp[i],i);
			used[i]=false;
		}
	}
	return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    memset(used,true,sizeof(used));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&inp[i]);
    }
    sort(inp+1,inp+1+n);
    for(int i=n;i>=3;i--){
    	dfs(inp[i],i);
    }
    printf("%lld",ans);
	return 0;
}
