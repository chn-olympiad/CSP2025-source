#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244343;
int n,m;
int chose[105];
bool vis[101];
bool is[101];
int wait[101];
int ans,use;
int leave;
void dfs(int p){
	if(p==n){
		int use=0,leave=0;
		for(int i=1;i<=n;i++){
			if(leave>=wait[chose[i]]||is[i]==0){
				leave++;
			}else{
				use++; 
			}
		}
		if(use>=m){
//			cout<<1<<'\n';
			ans++;
			ans%=998244353;
		}else{
//			cout<<0<<'\n';
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			chose[p+1]=i;
			dfs(p+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c=getchar();
		c-='0';
		is[i]=c;
	}
	for(int i=1;i<=n;i++)cin>>wait[i];
	dfs(0);
	cout<<ans;
	return 0;
}

