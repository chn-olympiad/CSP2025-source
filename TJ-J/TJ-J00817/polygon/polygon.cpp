#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
int box[5001],vis[5001],a[5001],n;
void dfs(int x,int sid,int k){
	if(x==k+1){
		int maxn=0,sum=0;
		for(int i=1;i<=k;i++){
			maxn=max(maxn,box[i]);
			sum+=box[i];
		}if(sum>maxn*2)cnt++; 
		return ;
	}for(int i=sid;i<=n;i++){
		if(!vis[i]){
			box[x]=a[i];
			vis[i]=1;
			dfs(x+1,i,k);
			vis[i]=0;
		}
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=3;i--){
		dfs(1,1,i);
	}
	cout<<cnt%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
