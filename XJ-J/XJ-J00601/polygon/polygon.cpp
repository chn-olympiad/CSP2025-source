#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[5005],c[5005];
bool vis[5005];
void dfs(int x){
	if(x>n){
		int all=0,mmax=-1,fn=0;
		for(int i=1;i<=n;i++){
			if(c[i]==1){
				all+=a[i];
				fn++;
				mmax=max(mmax,a[i]);
			}
		}
		if(all>2*mmax&&all!=0&&fn>=3)ans++;
		return;
	}
	for(int i=0;i<=1;i++){
		if(!vis[x]){
			vis[x]=1;
			c[x]=i;
			dfs(x+1);
			vis[x]=0;
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
dfs(1);
cout<<ans%998244353;
	return 0;
}

