#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m,com,a[505];
string s;
ll ans=0;
bool vis[505];
void dfs(int num,int x,int taotai){
	if(num>n){
		if(n-taotai>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(taotai>=a[i]){
				dfs(num+1,i,taotai+1);
				vis[i]=0;
			}else{
				dfs(num+1,i,taotai);
				vis[i]=0;
			}	
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	
	for(int i=1;i<=n;i++){
		
		cin >> a[i];
		
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,i,0);
		vis[i]=0;
	}
	cout << ans;
	return 0;
}
