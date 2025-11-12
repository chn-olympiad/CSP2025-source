#include<bits/stdc++.h>
using namespace std;

int mod=998244353;
int n;
int a[5010];
int vis[5010];
int deep;
int ans=0;
int dfs(int k,int max1,int sum,int pos){
	if(k>=deep){
		if(sum>2*max1){
			ans++;
		}
		return 0;
	}
	for(int i=pos;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			int tmp1=sum+a[i];
			dfs(k+1,a[i],tmp1,i+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		deep=i;
		dfs(0,-1,0,1);
		ans=ans%mod;
	}
	cout<<ans<<endl;
	return 0;
}
