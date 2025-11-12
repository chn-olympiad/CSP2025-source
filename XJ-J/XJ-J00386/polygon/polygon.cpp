#include <bits/stdc++.h>
using namespace std;
int n,a[5005],vis[5005],k=0;
void dfs(int zg,int sl,int gs,int jd){
	if(gs>=3&&sl>zg*2){
		k++;
		k%=998244353;
	}
	for(int i=jd+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(a[i],sl+a[i],gs+1,i);
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
	sort(a+1,a+1+n);
	dfs(a[0],0,0,0);
	cout<<k;
	return 0;
}
