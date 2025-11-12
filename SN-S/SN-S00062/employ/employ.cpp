#include<bits/stdc++.h>
using namespace std;
const int MAXN=500;
int n,m;
int s[MAXN+5];
int c[MAXN+5];
char ch;
int ans=0;
int vis[MAXN+5];
void dfs(int now,int luqv,int bad){
//	cout<<now<<' '<<luqv<<' '<<bad<<endl;
	if(now>n){
		if(luqv>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(s[now]==0){
				dfs(now+1,luqv,bad+1);
			}else{
				if(bad>=c[i]){
					dfs(now+1,luqv,bad+1);
				}else{
					dfs(now+1,luqv+1,bad);
				}
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

