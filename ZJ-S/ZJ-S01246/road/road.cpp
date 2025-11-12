#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,l;
}mp[1000001];
int n,m,k,c[15],a[15][10001],fa[10001],b[15][10001],ans;
bool cmp(node p,node q){
	return p.l<q.l;
}
int search(int x){
	if(fa[x]==x)return x;
	fa[x]=search(fa[x]);
	return fa[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>mp[i].u>>mp[i].v>>mp[i].l;
	}
	sort(mp+1,mp+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	if(k==0){
		for(int i=1;i<=m;i++){
			int rootx=search(mp[i].u),rooty=search(mp[i].v);
			if(rootx!=rooty){
				cnt++;
				fa[rootx]=rooty;
				ans+=mp[i].l;
			}
			if(cnt==n-1)break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=m;i++){
		int rootx=search(mp[i].u),rooty=search(mp[i].v);
		if(rootx!=rooty){
			cnt++;
			fa[rootx]=rooty;
			int mini=mp[i].l;
			for(int j=1;j<=k;j++){
				if(b[j][mp[i].u]==1)mini=min(mini,a[j][mp[i].v]);
				else if(mini>a[j][mp[i].u]+a[j][mp[i].v]){
					mini=a[j][mp[i].u]+a[j][mp[i].v];
					b[j][mp[i].u]=1;b[j][mp[i].v]=1;
				}
			}
			ans+=mini;
		}
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
}