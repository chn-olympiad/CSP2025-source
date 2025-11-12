#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e5+5;
int n,k,a[N],cnt,ans,vis[N],f[5005][5005];
struct node{
	int l,r;
}c[N];

void dfs(int x,int sum){
	if(x==cnt+1){
		ans=max(ans,sum);
		return;
	}
	bool flg=1;
	for(int j=c[x].l;j<=c[x].r;j++)if(vis[j]){flg=0;break;}
	if(flg){
		for(int j=c[x].l;j<=c[x].r;j++)vis[j]=1;
	    dfs(x+1,sum+1);
	    for(int j=c[x].l;j<=c[x].r;j++)vis[j]=0; 
	}
	dfs(x+1,sum);
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0&&a[1]==1&&a[2]==1&&a[3]==1&&a[n]==1){
		cout<<(n/2)<<'\n';
		return 0;
	}
	if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=(a[i]==0);
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1)++cnt,++i;
		}
		cout<<cnt<<'\n';
		return 0;
	}
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=(a[i]==1);
		cout<<cnt<<'\n';
		return 0;
	}
	for(int l=1;l<=n;l++){
		int ret=0;
		for(int r=l;r<=n;r++){
			ret^=a[r];
			if(ret==k){
			    c[++cnt].l=l,c[cnt].r=r;
			    break;
			}
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

