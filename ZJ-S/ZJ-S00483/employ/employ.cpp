#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fre(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int c[20],a[20],con[20],m,n,ans;
bool vis[20];
string s;
void dfs(int now,int sum,int x){
	if(now==n+1){
		if(sum>=m){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0){
			vis[i]=1;
			if(a[now]==0)dfs(now+1,sum,x+1);
			else if(c[i]<=x)dfs(now+1,sum,x+1);
			else dfs(now+1,sum+1,x);
			vis[i]=0;
		}
}
int main(){
	fre();
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		if(s[i-1]=='0')a[i]=0;
		else a[i]=1;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
