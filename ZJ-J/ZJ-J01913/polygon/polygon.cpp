#include <bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const long long mod=998244353;
long long dp[MAXN],n,a[MAXN],p[MAXN],ans=0,path[MAXN],m;
bool vis[MAXN];
void dfs(int cnt,int lst){
	//if(cnt==4 && )
	if(cnt>3){
		long long sum=0,Max=0;
		for(int i=1;i<=n;i++){
			sum+=path[i];
			Max=max(Max,path[i]);
		}
		if(sum>2*Max){
			/*for(int i=1;i<=n;i++){
				cout<<path[i]<<" ";
				path[i]=0;
			}
			cout<<endl;*/
			ans++;
		}
	}
	if(cnt>n){
		/*for(int i=1;i<=n;i++){
			path[i]=0;
		}*/
		return;
	}
	for(int i=lst+1;i<=n;i++){
		path[cnt]=a[i];
		dfs(cnt+1,i);
		path[cnt]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//p[i]=p[i-1]+a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}