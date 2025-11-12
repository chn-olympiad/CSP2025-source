#include<bits/stdc++.h>
using namespace std;
const int inf=998244353;
long long n,a[5005],vis[5005],f,sum;
void dfs(int x,long long d,long long ans,int w){
	if(ans>2*d&&w>=3){
		sum++;
		sum%=inf;
	}
	for(int i=x+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(i,max(d,a[i]),ans+a[i],w+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++)dfs(i,a[i],a[i],i);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
