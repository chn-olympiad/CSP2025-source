#include<iostream>
#include<algorithm>
using namespace std;
const int N=20010,M=1000010;
int n,m,k,val[N],a[11][N],p[N],siz[N];
struct point{
	int u,v,w;
	inline bool operator<(const point &W)const{
		return w<W.w;
	}
}edge[M],edge2[M];
inline int find(int x){
	if(p[x]!=x)
		p[x]=find(p[x]);
	return p[x];
}
inline int read(){
	char c=getchar();
	int num=0,op=1;
	while(c<'0'||c>'9'){
		if(c=='-')
			op=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
		num=num*10+c-'0',c=getchar();
	return num*op;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		edge[i]=(point){read(),read(),read()};
	for(int i=1;i<=k;i++){
		val[i]=read();
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	}
	sort(edge+1,edge+m+1);
	long long ans=1e18;
	for(int tmp=0;tmp<1<<k;tmp++){
		long long sum=0,cnt=0;
		for(int i=1;i<=n+k;i++)
			p[i]=i,siz[i]=(i<=n);
		for(int i=1;i<=k;i++){
			if(tmp>>(i-1)&1){
				for(int j=1;j<=n;j++)
					edge2[++cnt]={n+i,j,a[i][j]};
				sum+=val[i];
			}
		}
		sort(edge2+1,edge2+cnt+1);
		int i=1,j=1;
		while(true){
			if(j<=cnt&&edge2[j].w<edge[i].w){
				int pa=find(edge2[j].u),pb=find(edge2[j].v);
				if(pa!=pb){
					p[pa]=pb,siz[pb]+=siz[pa],sum+=edge2[j].w;
					if(siz[pb]==n)
						break;
				}
				j++;
			}
			else{
				int pa=find(edge[i].u),pb=find(edge[i].v);
				if(pa!=pb){
					p[pa]=pb,siz[pb]+=siz[pa],sum+=edge[i].w;
					if(siz[pb]==n)
						break;
				}
				i++;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
}
//Ren5Jie4Di4Ling5%
