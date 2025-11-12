#include<bits/stdc++.h>
using namespace std;
int n,m,k,p[20005],g[15],a,u,d,v,cnt;
long long ans;
template<typename T> void read(T &x){
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
}
struct pl{
	int u,d,v;
}c[2000005];
int fd(int x){
	if(x!=p[x])return p[x]=fd(p[x]);
	return x;
}
void cmb(int x,int y){
	p[p[y]]=p[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++){
		read(c[i].u),read(c[i].d),read(c[i].v);
	}
	for(int i=1;i<=n+k;i++)p[i]=i;
	for(int i=1;i<=k;i++){
		read(g[i]);
		for(int j=1;j<=n;j++){
			read(a);
			if(!a){
				cmb(j,n+i);
			}else{
				m++; 
				c[m].u=j,c[m].d=n+i,c[m].v=a; 
			}
		}
	}
	sort(c+1,c+1+m,[](pl x,pl y){
		return x.v<y.v;
	});
	for(int i=1;i<=m;i++){
		u=c[i].u,d=c[i].d,v=c[i].v;
		if(fd(u)!=fd(d)){
			cmb(u,d);
			ans+=v;
			cnt++;
			if(cnt==n-1)break; 
		}
	}
	printf("%lld",ans);
	return 0;
}