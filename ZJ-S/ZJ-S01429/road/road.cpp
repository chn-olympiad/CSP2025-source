#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,c[10],d[10][N],f[110],cnt,ans;
struct node{
	int t,e,w;
}line[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>line[i].t>>line[i].e>>line[i].w;
	}for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	if(k==0){
		sort(line+1,line+m+1,cmp);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++){
			if(cnt==n-1) break;
			int p=find(line[i].t),q=find(line[i].e);
			if(p==q) continue;
			f[p]=q;
			cnt++;
			ans+=line[i].w;
		}
		cout<<ans;
	}
	return 0;
}
