#include<bits/stdc++.h>
using namespace std;
const int N=500,mod=998244353;
bool vis[N];
char s[N];
int a[N];
int n,m;
int f(int x){
	int ans=1;
	for(int i=1;i<=x;i++){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
int dfs(int x,int y,int z){
	if(y>=m){
		return f(n-x);
	}
	if(x>n)return 0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		if(z>=a[i])continue;
		vis[i]=1;
		if(s[x]=='1')ans+=dfs(x+1,y+1,z);
		else ans+=dfs(x+1,y,z+1); 
		vis[i]=0;
	}
	return ans;
}
bool pf1=1;
int pf2=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(s[i]=='0'){
			pf1=0;
			pf2++;
		}
	}
	if(pf2+m>n){
		printf("0");
	}else if(pf1){
		printf("%d",f(n));
	}else{
		printf("%d",dfs(1,0,0));
	}
	return 0;
}

