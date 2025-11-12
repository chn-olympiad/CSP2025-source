#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int ans=0,sum=0;
int n;
int a[100010],vis[1000010];
void dfs(int x,int s,int m,int p){
	if(x==0){
		
		if(s>m*2){
//			cout<<s<<" "<<m<<endl;
			sum++;
		}
		return ;
	}
	for(int j=p;j<=n;j++){
		if(vis[j]==0){
			vis[j]=1;
			dfs(x-1,s+a[j],max(m,a[j]),j);
			vis[j]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	for(int j=3;j<=n;j++){
		sum=0;
		for(int k=1;k<=n;k++){
			vis[k]=0;
		}
		dfs(j,0,0,1);
		ans+=sum;
	}
	cout<<ans;
	return 0;
}
