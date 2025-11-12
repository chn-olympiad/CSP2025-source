#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e3+10,mod=998244353;
char op[N];
int c[N];
bool vis[N];
int num[N];
int ans=0; 
int n,m;
void check(){
	int sum=0,lim=0;
	for(int i=1;i<=n;i++){
		if(op[i]=='1'&&lim<c[num[i]]){
			sum++;
		}else{
			lim++;
		}
	}
//	cout<<sum<<endl;
	if(sum>=m){
		ans=(ans+1)%mod;
	}
	return;
}
void dfs(int t){
	if(t==n+1){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			num[t]=i;
			dfs(t+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	scanf("%s",op+1);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
