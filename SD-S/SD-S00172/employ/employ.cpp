#include<bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pb push_back
#define fi first
#define se second 
const int N=1e5;
using namespace std;
int n,m,c[N],ans=0,a[N],trnum=0;
bool flag=1;
bool vis[N];
char s[N];
void dfs(int dep){
	if(dep==n+1){
		int tmp=0,passtmp=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0' or c[a[i]]<=tmp){
				tmp++;
			}
			else{
				passtmp++;
			}
		}
		if(passtmp>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[dep]=i;
			dfs(dep+1);
			vis[i]=0;
			a[dep]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			flag=false;
		}
		else{
			trnum++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if((n==m and flag) or trnum<m){
		cout<<0<<'\n';
		return 0;
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
