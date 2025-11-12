#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u,v,w;
	int id;
	bool operator < (const edge &b)const{
		return w<b.w;
	}
}p[100005];
int n,m,c;
vector<pair<int,int> >r[10005];
pair<int,int> a[13][10005];
int b[13];
int rt[13],minn;
int res,resc[13],resp[1030];
vector<int>ans,ansc[13];
int fe[10005];
int fa[10005];
int les[13][10005];
int dwn[1030][10005];
int hlc[1030];
//bitset<10005>
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void solve0(){
	int fx,fy;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,j=1;i<=m,j<n;i++){
		fx=find(p[i].u);
		fy=find(p[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			res+=p[i].w;
			ans.push_back(i);
			j++;
		}
	}
}
void dfs(int k,int fa){
	for(auto i:r[k]){
		if(i.first==fa)continue;
		dfs(i.first,k);
		fe[i.first]=i.second;
	}
}
void solve(int k,int s){
	int fx,fy;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,j=1,t=1;i<=m and j<n and t<=n;i++){
//		for(int xzh=1;xzh<=n;xzh++){
//			cout << find(xzh) << " ";
//		}
//		cout << "\n";
		while(t<=n and a[k][t].first<p[i].w){
			fx=find(s);
			fy=find(a[k][t].second);
			if(fx!=fy){
				fa[fx]=fy;
//				resc[k]+=a[k].t.second;
				ansc[k].push_back(t);
				j++;
			}
			t++;
		}
		fx=find(p[i].u);
		fy=find(p[i].v);
		if(fx!=fy){
			fa[fx]=fy;
//			resc[k]+=p[i].w;
			j++;
		}
	}
}
signed main(){
//	freopen("csps/down/road/road1.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> c;
	for(int i=1;i<=m;i++){
		cin >> p[i].u >> p[i].v >> p[i].w;p[i].id=i;
	}
	sort(p+1,p+m+1);
	for(int i=1;i<=c;i++){
		cin >> b[i];
		minn=1e18;
		for(int j=1;j<=n;j++){
			cin >> a[i][j].first;
			a[i][j].second=j;
			if(a[i][j].first<minn){
				minn=a[i][j].first;
				rt[i]=j;
			}
		}
		sort(a[i]+1,a[i]+n+1);
		b[i]+=a[i][rt[i]].first;
	}
	solve0();
	if(c==0){
		cout << res;
		return 0;
	}
	for(int j=0;j<n-1;j++){
		r[p[ans[j]].u].push_back({p[ans[j]].v,j});
		r[p[ans[j]].v].push_back({p[ans[j]].u,j});
	}
//	for(int i=1;i<=n;i++){
//		cout << i << "  ";
//		for(auto j:r[i]){
//			cout << j.first << " " << j.second << "  ";
//		}
//		cout << "\n";
//	}
	for(int i=1;i<=c;i++){
		dfs(rt[i],-1);
		fe[rt[i]]=-1;
//		for(int i=1;i<=n;i++){
//			cout << fe[i] << " ";
//		}
//		cout << "\n";
		solve(i,rt[i]);
		for(auto j:ansc[i]){
//			cout << j << " ";
			les[i][fe[a[i][j].second]]=p[ans[fe[a[i][j].second]]].w-a[i][j].first;
			cout << i << " " << fe[a[i][j].second] << " ";
			cout << les[i][fe[a[i][j].second]] << "\n";
		}
//		cout << "\n";
	}
	for(int i=0;i<(1<<c);i++){
		for(int j=0;j<c;j++){
			if((i&(1<<j))==0)continue;
			hlc[i]+=b[j+1];
			for(int l=0;l<n-1;l++){
				dwn[i][l]=max(dwn[i][l],les[j+1][l]);
			}
		}
		cout << i << "  ";
		for(int l=0;l<n-1;l++){
			cout << dwn[i][l] << " ";
			hlc[i]-=dwn[i][l];
		}
		cout << "\n";
		res=min(res,res+hlc[i]);
	}
	cout << res;
	return 0;
}

