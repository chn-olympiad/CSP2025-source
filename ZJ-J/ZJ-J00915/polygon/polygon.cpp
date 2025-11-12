#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool vis[5005];
int n;
int maxn=0;
int ans=0;
int cnt=0;
int q;
void dfs(int s,int f){
	if(s==f+1){
		maxn=0;
		cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				maxn=max(a[i],maxn);
				cnt+=a[i];
			}
		}
		if(cnt>2*maxn){
			ans++;
		}	
		return;
	}
	for(int i=q;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			q=i;
			dfs(s+1,f);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=3;
	for(int i=3;i<=n;i++){
		f++;
		dfs(1,f);
		q=1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
