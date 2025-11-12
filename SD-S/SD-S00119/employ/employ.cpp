#include<bits/stdc++.h>
#define N 510 
using namespace std;
string s;
int a[N],id[N],n,m,ans;
bool vis[N];
void dfs (int x){
	if (x>n){
		int cnt=0;
		for (int i=1; i<=n; i++){
			if (s[i-1]=='0' || cnt>=a[id[i]]){
				cnt++;
			}
		}
		if (n-cnt>=m){
			ans++;
		}
		return ;
	}
	for (int i=1; i<=n; i++){
		if (!vis[i]){
			id[x]=i;
			vis[i]=1;
			dfs (x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	dfs (1);
	cout<<ans;
	return 0;
}
