#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5,M=2e4+5;
int n,m,k,u,v,w,x,y,a[M][15],f[N],ans,s;
struct node{
	int u,v,w;
};
vector<node> e;
inline int read(){
	int t=1,tot=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return tot*t;
}
inline int cmp(node a,node b){
	return a.w<b.w;
}
inline int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		u=read(); v=read(); w=read();
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		a[i][0]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
		for(int j=1;j<=n;j++){
			for(int u=1;u<=n;u++)
				if(u!=j)
					e.push_back({j,u,a[i][j]+a[i][u]+a[i][0]});
		}
	}
	sort(e.begin(),e.end(),cmp);
	s=1;
	for(int i=0;i<e.size();i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			f[fx]=fy;
			s++;
			ans+=e[i].w;
			if(s==n) break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
