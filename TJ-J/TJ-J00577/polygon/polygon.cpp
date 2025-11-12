#include<bits/stdc++.h>
using namespace std;
int n;
const long long mod=998244353;
long long ans;
int a[5005];
void dfs(int id,int sum,int cnt){
	if(cnt+1>=3&&sum+a[id]>a[id]*2){
		ans=(ans+1)%mod;
	}
	if(id==n) return;
	dfs(id+1,sum+a[id],cnt+1);
	dfs(id+1,sum,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1){
		cout<<n*(n-1)*(n-2)/6;
	}
	else{
		sort(a+1,a+n+1);
		dfs(1,0,0);
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
}
