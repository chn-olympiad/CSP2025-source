#include<bits/stdc++.h>
using namespace std;
int n;
int a[5009];
const long long Mod=998244353ll;
long long res=0;
void dfs(int u,int step,long long total,int maxx){
	if(step>=3&&total>maxx*2) res=(res+1)%Mod;
	for(int i=u+1;i<=n;i++){
		dfs(i,step+1,total+a[i],max(maxx,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++)
		dfs(i,0,0,0);
	cout<<res%Mod;
	return 0;
}

