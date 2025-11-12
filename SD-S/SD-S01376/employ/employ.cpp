#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int maxn=500,mod=998244353;
int n,m,s[maxn],a[maxn],ans,sum,pl[maxn];
bool vis[maxn];
void check(){
	int c=0;
	for(int i=1;i<=n;i++){
//		cout<<pl[i]<<" ";
		if(!s[i])c++;
		else{
			if(c>=a[pl[i]])c++;
		}
	}
//	cout<<"\n";
	if(n-c>=m)ans++;
	ans%=mod;
}
void dfs(int x){
	if(x==n){
		check();
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			pl[x+1]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		sum+=s[i];
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(sum==n){
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		printf("%d",ans);
	}else{
		dfs(0);
		printf("%d",ans%mod);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
