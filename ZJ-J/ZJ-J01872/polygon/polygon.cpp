#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n;
int a[N],vis[N];
long long ans;
void dfs(int k){
	if(k==n+1){
		int maxn=0,sum=0,cnt=0;
		for(int i=1;i<=n;++i){
			sum+=vis[i]*a[i];
			cnt+=vis[i];
			maxn=max(maxn,vis[i]*a[i]);
		}if(cnt>=3&&sum>2*maxn){
			ans++;
		}
	}else{
		vis[k]=1;
		dfs(k+1);
		vis[k]=0;
		dfs(k+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}dfs(1);
	cout<<ans%998244353;
	return 0;
}
