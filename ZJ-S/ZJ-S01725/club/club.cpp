#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,a[N][5],vis[4];
long long ans=0,sum=0;
bool flag=1;
void dfs(int u){
	if(u==n+1){
		sum=max(sum,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]+1>n/2) continue;
		ans+=a[u][i];
		vis[i]++;
		dfs(u+1);
		ans-=a[u][i];
		vis[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof(vis));
		ans=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if((j==2||j==3)&&a[i][j]!=0) flag=0; 
			}
		}
		if(flag==1){
			int c[N];
			for(int i=1;i<=n;i++) c[i]=a[i][1];
			sort(c+1,c+1+n);
			for(int i=n;i>n/2;i--) sum+=c[i];
		}
		else dfs(1);
		cout<<sum<<endl;
	}
	return 0;
}
