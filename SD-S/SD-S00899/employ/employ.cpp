#include<bits/stdc++.h>
using namespace std;

const int MAXN=510;

int n,m,d[MAXN],a[MAXN],vis[MAXN],ans;

char s[MAXN];

void dfs(int x,int sum){
	if(x==n){
		ans+=((n-sum)>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(d[x]==0){
				dfs(x+1,sum+1);
			}else{
				dfs(x+1,sum+(sum>=a[i]));
			}
			vis[i]=0;
		}
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++){
		d[i]=s[i]-'0';
	}
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	vis[1]=1;
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
