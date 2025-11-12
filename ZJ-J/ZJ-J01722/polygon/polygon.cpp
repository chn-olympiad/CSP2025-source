#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[5010],ans;
const int N=998244353;
void dfs(int x,int y,int z){
	if(x==n){
		if(y>z*2)
			ans++,ans%=N;
		return ;
	}
	dfs(x+1,y+a[x+1],max(z,a[x+1]));
	dfs(x+1,y,z);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		dfs(0,0,0);
		cout<<ans%N;
		return 0;
}