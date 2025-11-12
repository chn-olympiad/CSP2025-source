#include<bits/stdc++.h>
using namespace std;
int n,T,m,sum=0,ans=-1,lm;
int const N=1e5+5;
int a[N][5],vis[5];
void dp(int x,int y){
	sum+=a[x][y];vis[y]++;
	if(vis[y]>lm) {
		//vis[y]--,sum-=a[x][y];
		//cout<<1<<endl;
		return ;
	}
	if(x==n){
		ans=max(ans,sum);
		//cout<<sum<<endl;
		//sum-=a[x][y],vis[y]--;
		return ;
	}
	for(int i=1;i<=m;i++){
		//cout<<x+1<<' '<<i<<endl;
		dp(x+1,i);
		sum-=a[x+1][i],vis[i]--;
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);		
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		m=3;
		cin>>n;
		sum=0,ans=-1,lm=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		dp(0,0);
		cout<<ans<<endl;
	}
	
}
