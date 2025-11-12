#include<bits/stdc++.h>
#define int long long

const int N=1145140;
const int inf=0x66ccff66ccff;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){s=(s<<3)+(s<<1)+(c-'0');c=getchar();}
	return s*f;
}
struct node{
	int to,val;
};
struct edge{
	int fr,to,val,id;
};
int fa[N],rank[N];
int find(int x){
	return (x==fa[x]?x:fa[x]=find(fa[x]));
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(rank[x]>rank[y])std::swap(x,y);
	rank[y]+=rank[x];fa[x]=y;
}
int n,m,k,c[N],a[12][N],vis[20];
std::vector<edge> edgeset[N]; 
std::pair<int,int> kul(int num){
	int ans=0,maxx=-inf;
	for(int i=1;i<=n;++i)fa[i]=i,rank[i]=1;
	std::sort(edgeset[num].begin(),edgeset[num].end(),[](edge x,edge y){
		return (x.val)<(y.val);	
	});
	int cnt=0;
	for(auto &i:edgeset[num]){
//		if(cnt==n-1)break;
		if(find(i.fr)==find(i.to))continue;
		maxx=std::max(maxx,i.val);
//		printf("(%lld,%lld,%lld)\n",i.fr,i.to,i.val);
		vis[i.id]=1;
		edgeset[num+1].push_back({i.fr,i.to,i.val,i.id}); 
		ans+=i.val;
		merge(i.fr,i.to);
		cnt++;
	}
	return std::make_pair(ans,maxx);
//	printf("%lld",ans);
}
void solve(){
	auto tmp=kul(0);
	int ans=tmp.first,lstmax=tmp.second;
	for(int i=1;i<=k;++i){
		memset(vis,0,sizeof vis);
		for(int j=1;j<=n;++j){
			for(int l=j+1;l<=n;++l){
				if(a[i][j]+a[i][l]>lstmax)continue;
				edgeset[i].push_back({j,l,a[i][j]+a[i][l],i});
			}
		}
		auto res=kul(i);
		int prec=0;
		for(int j=1;j<=k;++j)prec+=(c[j]*vis[j]);
		if(res.first+prec<ans)ans=res.first+prec,lstmax=res.second;
		else edgeset[i+1]=edgeset[i-1];
//		printf("(%lld)\n",ans);
//		printf("%lld\n",res+c[i]);
	}
	printf("%lld",ans);
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		edgeset[0].push_back({u,v,w,0});
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j){
			a[i][j]=read();
		}
	}
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//³¹µ×ËÆÁË 
