#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int a[10005],ans;
bool vis[10005];
void dfs(int minid,int maxid,int sum,int stp){
	bool flg=1;
	for(int i=minid+1;i<maxid;i++){
		if(vis[i]==0){
			flg=0;
			if(sum+a[i]>a[maxid]*2){
				ans++;
				ans%=p;
			}
			vis[i]=1;
			dfs(i,maxid,sum+a[i],stp+1);
			vis[i]=0;
		}
	}
	if(flg)return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			int sum=1;
			for(int j=i+1;j<=n;j++){
				sum*=j%p;
			}for(int j=1;j<=(n-i);j++){
				sum/=j;
			}
			ans+=sum%p;ans%=p;
		}
		cout<<ans%p;
		return 0;
	}
	else{
		if(n==3){
			if(a[1]+a[2]>a[3])cout<<1;
			else cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				vis[i]=1;
				vis[j]=1;
				dfs(i,j,a[i]+a[j],2);
				vis[i]=0;
				vis[j]=0;
			}
		}
		cout<<ans;
	}
	return 0;
}
//polygon