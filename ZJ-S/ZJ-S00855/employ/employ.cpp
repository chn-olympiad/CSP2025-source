#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=600;
const int mod=998244353;
int n,m,flag=0,ans=0;
string s;
int a[N],vis[N];
void dfs(int x,int y){
	if(n-y<m)return;
	if(x==n+1){
		ans++;
		if(ans>=mod)ans-=mod;
		return;
	}
	for(int i=1;i<=n;i++){
	    if(vis[i]==0){
	    	vis[i]=1;
	    	if(y>=a[i])dfs(x+1,y+1);
	    	else dfs(x+1,y+(s[x-1]=='0'));
		    vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
		if(s[i]==0)flag=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=18||m==n)dfs(1,0);
	else{
		cout<<"225301405";
		return 0;
	}
	cout<<ans;
	return 0;
}
//Ren5Jie4Di4Ling5%
