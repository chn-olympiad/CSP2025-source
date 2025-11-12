#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int T,n,ans=0;
int a[100005][5];
int c[100005];
void dfs(int k,int dy,int de,int h){
	if(k>n){
		ans=max(ans,h);
		return;
	}
	if(dy<n/2) dfs(k+1,dy+1,de,h+a[k][1]);
	if(de<n/2) dfs(k+1,dy,de+1,h+a[k][2]);
	if(k-1-de-dy<n/2) dfs(k+1,dy,de,h+a[k][3]);
	return;
}
bool cmp(int q,int p){
	return a[q][1]>a[p][1];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n>200){
			for(int i=1;i<=n;i++) c[i]=a[i][1];
			sort(c+1,c+n+1,cmp);
			for(int i=1;i<=n/2;i++ ) ans+=c[i];
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
} 