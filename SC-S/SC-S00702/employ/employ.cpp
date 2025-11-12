#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,a[505],vis[505];
string s;
int dfs(int x,int k,int g){
	if(x==n){
		return 1;
	}
	int sum=0;
	if(s[x]=='0'){
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				sum+=dfs(x+1,k+1,g);
				vis[i]=0;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0 && a[i]>k){
				vis[i]=1;
				sum+=dfs(x+1,k,g+1);
				vis[i]=0;
			}
		}
	}return sum;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=18){
		cout<<dfs(0,0,0);
	}else{
		cout<<0;
	}
	return 0;
} 