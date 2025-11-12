#include<bits/stdc++.h>//[48,64]pts
#define int long long
#define INF 1145141919810
using namespace std;
int n,m,k;
int c[31],ib[31][12001];
int fa[12001],rip;
struct sweeter{
	int u,v,w;
}b[1200001],d[31][12001];
int now[31],bnow;
bool cmp(sweeter x,sweeter y){
	return x.w<y.w;
}
int ffa(int x){
	return (x==fa[x]? x:fa[x]=ffa(fa[x]));
}
bool uioi(){
	for(int i=1;i<n;i++)
		if(ffa(i)!=ffa(i+1))return 0;
	return 1;
}
bool checka(){
	for(int i=1;i<=k;i++)
		if(c[i]!=0)return 0;
	return 1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>b[i].u>>b[i].v>>b[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>ib[i][j];
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(b+1,b+m+1,cmp);
	int sum=0,ans=0;
	for(int i=1;i<=m;i++){
		int fa_u=ffa(b[i].u);
		int fa_v=ffa(b[i].v);
		if(fa_u!=fa_v){
			sum++;
			ans+=b[i].w;
			fa[fa_u]=fa_v;
		}
		if(sum==n-1)break;
	}
	rip=ans;
	if(k==0)cout<<rip;
	else if(checka()){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				m++;
				b[m].u=n+i;
				b[m].v=j;
				b[m].w=ib[i][j];
			}
		}
		n+=k;
		for(int i=1;i<=n;i++)
			fa[i]=i;
		sort(b+1,b+m+1,cmp);
		sum=0,ans=0;
		for(int i=1;i<=m;i++){
			int fa_u=ffa(b[i].u);
			int fa_v=ffa(b[i].v);
			if(fa_u!=fa_v){
				sum++;
				ans+=b[i].w;
				fa[fa_u]=fa_v;
			}
			if(sum>=n-1){
				if(uioi())break;
			}
		}
		cout<<min(rip,ans);
	}
	else{
		for(int i=1;i<=k;i++){
			now[i]=1;
			for(int j=1;j<=n;j++){
				d[i][j].u=n+i;
				d[i][j].v=j;
				d[i][j].w=ib[i][j];
			}
			sort(d[i]+1,d[i]+n+1,cmp);
			d[i][1].w+=c[i];
		}
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		sort(b+1,b+m+1,cmp);
		sum=0,ans=0,bnow=1;
		for(int i=1;i<=m+n*k;i++){
			int mi=INF,ms=0;
			for(int j=1;j<=k;j++){
				int my=d[j][now[j]].w;
				if(my<mi)mi=my,ms=j;
			}
			mi=min(mi,b[bnow].w);
			if(b[bnow].w<=mi){
				int fa_u=ffa(b[bnow].u);
				int fa_v=ffa(b[bnow].v);
				if(fa_u!=fa_v){
					sum++;
					ans+=b[bnow].w;
					fa[fa_u]=fa[fa_v];
				}
				bnow++;
			}
			else{
				int fa_u=ffa(d[ms][now[ms]].u);
				int fa_v=ffa(d[ms][now[ms]].v);
				if(fa_u!=fa_v){
					sum++;
					ans+=d[ms][now[ms]].w;
					fa[fa_u]=fa[fa_v];
				}
				now[ms]++;
			}
			if(sum>=n-1){
				if(uioi())break;
			}
		}
		cout<<min(rip,ans);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}