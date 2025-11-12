#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[1000005];
int fa[10005];
int c[15],w[15][10005];
vector<node> v;
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);//cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&w[i][j]);//cin>>w[i][j];
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+m+1,cmp);
	long long cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1)break;
		else{
			int fa1=find(a[i].u),fa2=find(a[i].v);
			if(fa1==fa2)continue;
			else{
				ans+=a[i].w;
				fa[fa1]=fa2;
				v.push_back(a[i]);
			}
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	//cout<<ans<<"\n";
	for(int i=1;i<(1<<k);i++){
		for(int j=1;j<=n;j++)fa[j]=j;
		long long tp=0,cnt=0,ctt=n;
		vector<node> vv;
		for(int j=0;j<v.size();j++)vv.push_back(v[j]);
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				tp+=c[j];
				ctt++;
				fa[ctt]=ctt;
				for(int p=1;p<=n;p++)vv.push_back({ctt,p,w[j][p]});
			}
		}
		sort(vv.begin(),vv.end(),cmp);
		//cout<<bitset<4>(i)<<":"<<tp<<"\n";
		for(int j=0;j<vv.size();j++){
			if(cnt==ctt-1)break;
			else{
				int fa1=find(vv[j].u),fa2=find(vv[j].v);
				if(fa1==fa2)continue;
				else{
					//cout<<vv[j].u<<" "<<vv[j].v<<" "<<vv[j].w<<"\n";
					tp+=vv[j].w;
					fa[fa1]=fa2;
					cnt++;
				}
			}
		}
		//cout<<"\n"; 
		ans=min(ans,tp);
	}
	printf("%lld",ans);
	return 0;
}
