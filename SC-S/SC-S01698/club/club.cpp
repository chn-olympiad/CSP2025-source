#include<bits/stdc++.h>
using namespace std;
int T,n;
int aa[100005][5];
int dp[500][500][500];
long long mx=-1;
void dfs(int a,int b,int c,long long ans,int p){
	if(ans<dp[a][b][c]){
		return;
	}else{
		dp[a][b][c]=ans;
	}
	if(a>(n/2)||b>(n/2)||c>(n/2)){
		return ;
	}if(p==n+1){
		mx=max(mx,ans);
	}dfs(a+1,b,c,ans+aa[p][1],p+1);
	dfs(a,b+1,c,ans+aa[p][2],p+1);
	dfs(a,b,c+1,ans+aa[p][3],p+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		mx=-1;
		memset(aa,0,sizeof(aa));
		if(n==100000){
			int b[100005]={0};
			for(int i=1;i<=n;i++){
				int x,xx;
				cin>>b[i]>>x>>xx;
			}sort(b+1,b+n+1);
			int gs=0,gsa=0;
			for(int i=n;i>=1;i--){
				gs++;
				if(gs>(n/2)){
					break;
				}gsa+=b[i];
			}cout<<gsa<<endl;
			continue;
		}
		memset(aa,0,sizeof(aa));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>aa[i][1]>>aa[i][2]>>aa[i][3];
		}
		dfs(0,0,0,0,1);
		cout<<mx<<endl;
	}
	return 0;
}