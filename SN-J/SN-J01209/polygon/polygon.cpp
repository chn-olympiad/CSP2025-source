#include <bits/stdc++.h>
using namespace std;
long long a[5010],n,ans,arr[550],vis[550];
const long long mod=998244353;
void dfs(int i,int maxn,int last){
	if (i==maxn+1){
		long long mx=-0x3f3f3f3f,sum=0;
		for (int i=1;i<=maxn;i++){
			cout<<arr[i]<<' ';
			mx=max(arr[i],mx);
			sum+=arr[i];
		}
		cout<<endl;
		if (sum>mx*2) ans++;
		ans%=mod;
		return ;
	}
	for (int j=last;j<=n;j++){
		if (vis[j]) continue;
		arr[i]=a[j];
		vis[j]=1;
		dfs(i+1,maxn,j);
		vis[j]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		dfs(1,i,1);
	}
	cout<<ans%mod;
	return 0;
}

