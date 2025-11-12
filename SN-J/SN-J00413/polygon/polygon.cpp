#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
long long n,a[5005];
namespace Subtask1{//40pts
	int sum=0,maxx=0,ans=0;
	bool vis[5005];
	inline void dfs(int now){
		if(now==n+1){
			sum=0;
			maxx=0;
			for(int i=1;i<=n;i++){
				if(vis[i]){
					sum+=a[i];
					maxx=max(maxx,a[i]);
				}
			}
			if(sum>2*maxx){
				ans++;
			}
			return;
		}
		vis[now]=1;
		dfs(now+1);
		vis[now]=0;
		dfs(now+1);
		return;
	}
	signed main(){
		dfs(1);
		cout<<ans<<endl;
		return 0;
	}
};
namespace Subtask2{//24pts
	int ans=0,C[5005][5005];
	inline bool check(){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		if(sum==n){
			return 1;
		}
		else{
			return 0;
		}
	}
	signed main(){
		C[0][0]=1;
		for(int i=1;i<=n;i++){
			C[i][0]=1;
			C[i][1]=i;
			C[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				C[i][j]=C[i-1][j-1]+C[i-1][j];
			}
		}
		for(int i=3;i<=n;i++){
			ans+=C[n][i];
			ans%=mod;
		}
		cout<<ans<<endl;
		return 0;
	}
};
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		Subtask1::main();
		return 0;
	}
	if(Subtask2::check()){
		Subtask2::main();
		return 0;
	}
	return 0;
}
/*
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
