#include<bits/stdc++.h>
using namespace std;
const int N=5e6+100;
int n,m;bool f[N],vis[N];int a[N],c,k,b[N],ans;
void dfs(int cnt){
	if(cnt>n){
		c=0,k=0;
		for(int i=1;i<=n;i++){
			if(c>=a[b[i]]) c++;
			else if(f[i]==0) c++;
			else k++;
		} 
		if(k>=m){
			ans++;return ;
		}
	}
		
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		b[cnt]=i;vis[i]=1;
		dfs(cnt+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;cin>>c;f[i]=c-'0';
	}
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	if(n<=18) dfs(1);
	else if(m==n) cout<<0;
	cout<<ans;
}