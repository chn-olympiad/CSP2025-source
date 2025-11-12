#include<bits/stdc++.h>
using namespace std;
string s;
int n,q,ans;
int a[1001],p[1001],vis[1001],c[1001];
void dfs(int now,int ns,int flag){
	if(ns+n-now<q) return;
	if(now==n){
		ans++;
		ans=ans%998244353;
		return;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			c[now+1]=i;
			if(p[i]<=a[now]+flag){
				if(s[now]=='0'){
					dfs(now+1,ns,flag);
				}
				else{
					dfs(now+1,ns,flag+1);
				}
			}
			else if(s[now]=='0'){
				dfs(now+1,ns,flag);
			} 
			else{
				dfs(now+1,ns+1,flag);
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(s[i-1]=='0') a[i]++;
		a[i]+=a[i-1];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
} 
