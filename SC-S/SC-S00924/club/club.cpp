#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,N,A[10000][5],Y,vis[1000005],tot[3],ans,vis_num[10005][3],cnt,flg;
bool check(int x){
	if(tot[x]>Y) return false;
	return true;
}
void dfs(int x,int sum){
	if(x==N){
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=3;j++){
			if(vis_num[i][j]==0&&check(j)&&cnt<=N){
				vis_num[i][j]=1;
				tot[j]++;
				cnt++;
				dfs(x+1,sum+A[i][j]);
				vis_num[i][j]=0;
				tot[j]--;
				cnt--;
			}
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(A,0,sizeof(A));
		memset(vis_num,0,sizeof(vis_num));
		memset(vis,0,sizeof(vis));
		memset(tot,0,sizeof(tot));
		cin>>N;
		Y=N/2;ans=0;
		for(int i=1;i<=N;i++) cin>>A[i][1]>>A[i][2]>>A[i][3];
		dfs(0,0);
		cout<<ans<<'\n';
	}
	return 0;
}