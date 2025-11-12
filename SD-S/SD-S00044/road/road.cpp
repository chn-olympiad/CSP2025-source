#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+100;
int n,m,k,tot,ans,cnt;
int fa[N],len[N],c[N],sum;
struct node{
	int u,v,w;
}a[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	if(k==0){
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			int x=find(a[i].u),y=find(a[i].v),w=a[i].w;
			if(x!=y){
				fa[x]=y;
				ans+=w;
				cnt++;
				if(cnt==n-1) break;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				tot++;
				cin>>a[m+tot].w;
				a[m+tot].u=n+tot;
				a[m+tot].v=j;
			}
		}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(a+1,a+m+tot+1,cmp);
		for(int i=1;i<=m+tot;i++){
			int x=find(a[i].u),y=find(a[i].v),w=a[i].w;
			if(x!=y){
				fa[x]=y;
				ans+=w;
				cnt++;
				if(cnt==n+k-1) break;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

