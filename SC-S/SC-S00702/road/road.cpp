#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,k,c[15][10005],l=0,f[10050];
struct node{
	int fr,to,v;
};
vector<node> a;
bool cmp(node a,node b){
	return a.v<b.v;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a.push_back({x,y,z});
	}for(int i=1;i<=k;i++){
		cin>>c[i][0];
		l=max(l,c[i][0]);
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			l=max(l,c[i][j]);
		}
	}if(l==0){
		cout<<0;
		return 0;
	}else{
		int ans2=1e18;
		for(int i=0;i<(1<<k);i++){
			int d=0,id=0,ans=0;
			for(int j=1;j<=n+k;j++)f[j]=j;
			for(int j=1;j<=k;j++){
				if(1&(i>>j)){
					d++;
					ans+=c[j][0];
					for(int l=1;l<=n;l++){
						a.push_back({n+j,l,c[j][l]});
					}
				}
			}
			sort(a.begin(),a.end(),cmp);
			for(int j=0;j<a.size();j++){
				if(find(a[j].fr)!=find(a[j].to)){
					merge(a[j].fr,a[j].to);
					ans+=a[j].v;
					id++;
				}if(id==n+d-1)break;
			}ans2=min(ans2,ans);
		}cout<<ans2;
	}
	return 0;
} 
//48