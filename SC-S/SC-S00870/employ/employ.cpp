#include<bits/stdc++.h>
using namespace std;
string t;
const int N=1e5+5;
int a[N],vis[N],n,lis[N],tot,m,ans;
bool check(){
	int ss=0,res=0;
	for(int i=1;i<=n;i++){
		if(t[i-1]=='0')
			++ss;
		else{
			if(ss>=a[lis[i]]) ++ss;
			else res++;
		}
	}
	return res>=m;
}
void dfs(int u,int cnt){
	if(cnt==n){
		if(check()==1) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;lis[++tot]=i;
			dfs(i,cnt+1);
			vis[i]=0;lis[tot--]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>t;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0);
	cout<<ans;
	return 0;
}