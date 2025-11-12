#include<bits/stdc++.h>
using namespace std;
int fa[20005];
struct node{
	int u,v,w;
};
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
vector<node>graph,graph2,Graph;
int n,m,k,c[15],a[15][10005];long long RES,ans;
long long MST(int n,vector<node>&graph){
	for(int i=1;i<=n;i++)fa[i]=i;
	long long anss=0;int cnt=0;
	for(auto i:graph){
		int fu=find(i.u),fv=find(i.v);
		if(fu!=fv){
			fa[fu]=fv;
			cnt++;
			anss+=i.w;
		}
		if(anss+RES>ans||cnt==n-1)break;
	}
	return anss;
}
void Merge(vector<node> &a,vector<node> &b,vector<node> &ans){
	int cnt1=0,cnt2=0;
	ans.clear();
	while(cnt1<a.size()&&cnt2<b.size()){
		if(cmp(a[cnt1],b[cnt2]))
			ans.push_back(a[cnt1++]);
		else{
			ans.push_back(b[cnt2++]);
		}
	}
	while(cnt1<a.size())ans.push_back(a[cnt1++]);
	while(cnt2<b.size())ans.push_back(b[cnt2++]);
}
long long mst(int sta){
	RES=0;
	for(int i=0;i<k;i++)
		if(sta>>i&1){
			RES+=c[i+1];
			for(int j=1;j<=n;j++)graph2.push_back({n+i+1,j,a[i+1][j]});
		}
	sort(graph2.begin(),graph2.end(),cmp);
	Merge(graph,graph2,Graph);
	return RES+MST(n+k,Graph);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		graph.push_back({u,v,w});
	}
	sort(graph.begin(),graph.end(),cmp);
	bool flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		flag&=(c[i]==0);
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	ans=LLONG_MAX;
	if(flag){
		cout<<mst((1<<k)-1)<<'\n';
		return 0;
	}
//	spnans=MST(spn);
	for(int sta=0;sta<(1<<k);sta++){
		ans=min(ans,mst(sta));
	}
//	sort(graph.begin(),graph.end(),cmp);
//	for(int i=1;i<=n+k;i++)fa[i]=i;
//	long long ans=0;int cnt=0;
//	for(auto i:graph){
//		int fu=find(i.u),fv=find(i.v);
//		if(fu!=fv){
//			fa[fu]=fv;
//			cnt++;
//			ans+=i.w;
//		}
//		if(cnt==n-1)break;
//	}
	cout<<ans<<'\n';
	return 0;
}
//15:12 16pts
//17:18 64~72pts
