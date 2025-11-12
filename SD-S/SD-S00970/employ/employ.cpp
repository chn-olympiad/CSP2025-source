#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[555]={};
int ar[555]={},br[555]={};
bool vis[555]={};
int ans=-1;
void dfs(int i,int cnt){
	if(cnt>=m){
		ans++;
		ans=ans%998244353;
		return;
	}
	if(i==n){
		return;
	}
	
	for(int j=1;j<=n;j++){
		if(br[j]>0&&s[j]=='1'&&vis[j]==0){
			vis[j]=1;
			dfs(i+1,cnt+1);
			vis[j]=0;
		}else{
			for(int k=1;k<=n;k++){
				br[k]--;
			}
			dfs(i+1,cnt);
			for(int k=1;k<=n;k++){
				br[k]++;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ar[i];
		br[i]=ar[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
