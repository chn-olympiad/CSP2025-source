#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],a[510],use[510],jie[510],mod=998244353;
void init(){
	jie[0]=1;
	for(int i=1;i<=510;i++){
		jie[i]=jie[i-1]*i%mod;
	} 
}
int dfs(int x,int num){
	if(num==m){
		return jie[n-x+1]; 
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(use[i]) continue;
		if(x-num>=a[i]){
			use[i]=1;
			ans+=dfs(x+1,num);
			use[i]=0;
		}
		else if(c[i]==1){
			use[i]=1;
			ans+=dfs(x+1,num+1);
			use[i]=0;
		}
		else{
			use[i]=1;
			ans+=dfs(x+1,num);
			use[i]=0;
		}
	} 
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char s;
		cin>>s;
		c[i]=s-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	printf("%d",dfs(1,0));
	return 0;
}

