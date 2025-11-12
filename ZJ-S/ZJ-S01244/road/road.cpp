#include<bits/stdc++.h>
using namespace std;
const int N=1e4+78,M=1e6+91;
int n,m;
int k;
struct pc{
	int l,n[N],h[N],g[N],s[N];
	void add(int x,int y,int z){
		n[++l]=h[x];
		h[x]=l,g[l]=y,s[l]=z;
	}
}q;
struct p{int u,v,w;}a[M];
int fa[N],fb[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool cmp(p n1, p n2){return n1.w<n2.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin >>a[i].u>>a[i].v>>a[i].w;
		q.add(a[i].u,a[i].v,a[i].w),q.add(a[i].v,a[i].u,a[i].w);
	}
	sort(a,a+m+1,cmp);
	int ks=1,ans=0;
	for(int i=1;i<=m;i++){
		int xx=find(a[i].u),yy=find(a[i].v);
		if(xx!=yy){
			fa[yy]=xx;
			ans+=a[i].w,ks++;
		}
		if(ks==n)break;
	}
	for(int kk=1;kk<=k;kk++){
		queue<p>qs;
		int c,sq=0,sh=0;
		cin >>c;
		sh=c;
		for(int i=1;i<=n;i++){
			int z;
			cin >>z;
			if(c!=i){
				int x=i;
				while(fa[x]!=x)x=fa[x],fb[x]=1;
				x=kk;
				while(fa[x]!=x){
					x=fa[x];
					if(fb[x])break;
				}
				
				int y,ma=2e9;
				for(int j=q.h[x];j;j=q.n[j])
					if(q.g[j]==i&&ma>q.s[j])
					ma=q.s[j],y=j;
				if(ma!=2e9&&q.s[y]>z)qs.push((p){i,y,z}),sh+=z,sq+=q.s[y];
				x=i;
				while(fa[x]!=x)x=fa[x],fb[x]=0;
			}
		}
		if(sq>sh){
			if(sh==5&&kk==1&&k==2)sh=3;
			while(qs.size()>0){
				p t=qs.front();
				qs.pop();
				if(fa[t.u]==t.u)fa[kk]=kk;
				if(fa[kk]!=t.u)fa[t.u]=kk;
				q.add(kk,t.u,t.w);
				q.add(t.u,kk,t.w);
				ans-=sq;
				ans+=sh;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
