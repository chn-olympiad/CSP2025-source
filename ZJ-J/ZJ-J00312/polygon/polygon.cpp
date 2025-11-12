#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long cnt;
bool v[5005];
void dfs(int ma,long long x,int o,int k){
	if(x>ma*2&&o>=3){
		cnt++;
	}
	if(o==n+1){
		return;
	}
	for(int i=k+1;i<=n;i++){
		if(v[i]==1){
			continue;
		}
		v[i]=1;
		dfs(max(ma,a[i]),x+a[i],o+1,i);
		v[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,(long long)0,0,0);
	cout<<cnt%mod;
	return 0;
}
