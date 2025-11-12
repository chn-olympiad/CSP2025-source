#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],sum[N],cnt;
int vis[N];
int ans;
int find(int s,int x){
	for(int i=s;i<=n;i++){
		if(vis[i]){
			return -1;
		}
		if(sum[i]==x){
			return i;
		}
	}
	return -1;
}


void dfs(int x,int cnt){
	ans=max(ans,cnt);
	int f=find(x,sum[x-1]^k);
	if(f==-1){
		return;
	}else{
		for(int i=x;i<=f;i++){
			if(!vis[i]){
				vis[i]=1;	
			}
		}
		dfs(f+1,cnt+1);
		for(int i=x;i<=f;i++){
			if(vis[i]==1){
				vis[i]=0;	
			}
		}
	}
}
int mx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		if(a[i]==k){
			vis[i]=2;
			cnt++;
		}
		sum[i]=sum[i-1]^a[i];
	}
	if(k==0&&mx<=1){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,0);
	}
	cout<<ans+cnt;
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
