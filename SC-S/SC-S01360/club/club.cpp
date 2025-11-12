#include<bits/stdc++.h>
using namespace std;
//55pts On3
const int N=205,inf=-1e9;
int n,m;
int T;
int a[N][4];
long long res;
int vis[N],cnt[4];
void dfs(int x,long long sum){
	if(x==n+1){
		res=max(res,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(vis[i])continue;
			else{
				vis[i]=1;
				if(cnt[j]<n/2){
					cnt[j]++;
					dfs(x+1,sum+a[i][j]);
					cnt[j]--;
				}
				vis[i]=0;
			}
		}
	}
}
void work(){
	cin>>n;
	res=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)cin>>a[i][j];
	dfs(1,0);
	printf("%lld\n",res);
}
int main(){
	
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
