#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10,mod=998244353;
int ss,n,m,c[N];
char s[N];
ll sum;
bool vis[N];
void dfs(int cnt,int w,int o){
	if(cnt==n){
		if(w>=m) sum=(sum+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(o<c[i]&&s[cnt+1]=='1') w++;
			if(s[cnt+1]=='0') o++;
			vis[i]=1;
			dfs(cnt+1,w,o);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='1') ss++;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(ss==n){
		sum=1;
		for(int i=n;i<=n-m+1;i++) sum=(sum*i)%mod;
		for(int i=1;i<=m;i++) sum=sum/i;
		cout<<sum;
		return 0;
	}
	else{
		dfs(0,0,0);
		cout<<sum;
	}
	return 0;
}
