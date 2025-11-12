//SN-J00678 ¶ÎÑÅçÍ ¸¨ÂÖÖĞÑ§  
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5001],ans=0;
void dfs(int step,int cnt,int maxn,int g){
	if(step==n+1){
		if(g>=3&&cnt>2*maxn){
			ans++;
			ans%=mod;
		}
		return ;
	}
	dfs(++step,cnt+a[step],max(maxn,a[step]),g+1);
	dfs(step,cnt,maxn,g);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

