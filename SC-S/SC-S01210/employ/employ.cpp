#include<bits/stdc++.h>//Fail
using namespace std;
const long long mod=998244353;
long long ans;
map<long long,long long>dp;
int n,m,a[505],c[505];
long long dfs(int x,int bef,int s){
	if(x>n){
		if(bef<=n-m) return 1;
		return 0;
	}
	if(n-x+n-bef<m) return 0;
	if(dp[(x<<25)+(bef<<18)+s])
		return dp[(x<<25)+(bef<<18)+s];
	long long ret=0;
	for(int i=1;i<=n;i++){
		if(s&(1<<(i-1))) continue;
		if(bef>=c[i]||a[x]==0) ret+=dfs(x+1,bef+1,s|(1<<(i-1)));
		else ret+=dfs(x+1,bef,s|(1<<(i-1)));
	}
	dp[(x<<25)+(bef<<18)+s]=ret;
	return ret;
}
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s+1); 
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0) c[0]++;
	}
	if(m>n-c[0]){
		printf("0\n"); 
		return 0;
	}
	if(c[0]==0&&a[n]==n){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		printf("%lld\n",ans);
		return 0;
	}
	if(n<=20){
		printf("%lld\n",dfs(1,0,0)%mod);
		return 0;
	}
	printf("0\n");
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/