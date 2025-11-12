#include<bits/stdc++.h>
using namespace std;
#define maxn 5145
#define mod 998244353
int n,a[maxn];
int ans=0;
bool vis[maxn]={0};
void dfs(int k,int ma,int su){
	if(k>n)return;
	int nma=max(ma,a[k]);
	int nsu=su+a[k];
	if(nsu>2*nma){
//		cout<<nma<<" "<<nsu<<endl;
		ans++;
		ans%=mod;
	}
	dfs(k+1,nma,nsu);
	dfs(k+1,ma,su);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}