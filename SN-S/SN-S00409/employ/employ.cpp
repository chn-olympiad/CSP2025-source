#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[114514];
string s;
bool vis[114514];
int p[114514];
int ans=0;
void dfs(int x,int t){
	if(n-t<m)return;
	if(x==n){
//		int t=0;
//		for(int i=0;i<n;i++){
//			if(t>=a[p[i]] || s[i]=='0'){
//				t++;
//			}
//		}
		if(n-t>=m){
//			for(int i=0;i<n;i++){
//				cout<<p[i]<<" ";
//			}cout<<t<<endl;
			ans++;
			ans%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
//		p[x]=i;
		if(a[i]<=t || s[x]=='0'){
			dfs(x+1,t+1);
		}else{
			dfs(x+1,t);
		}
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}dfs(0,0);
	cout<<ans;
//	cout<<t;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

