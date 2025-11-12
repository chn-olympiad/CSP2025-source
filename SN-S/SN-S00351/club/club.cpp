#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,cnt;
int vis[5],a[N][5];
void dfs(int u,int ans)
{
	if(u>n){
		cnt=max(cnt,ans);
		//cout<<cnt<<endl;
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]<n/2){
			vis[i]++;
			ans+=a[u][i];
			dfs(u+1,ans);
			ans-=a[u][i];
			vis[i]--;
		}
		
	}
} 
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cnt=0;
		for(int i=1;i<=3;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		dfs(1,0);
		cout<<cnt<<endl;
		
	}

}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0


