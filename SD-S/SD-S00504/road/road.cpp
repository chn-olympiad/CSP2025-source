#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot;
int d[1000010],c[20],zh[1000010],a[1001000],ver[1000010],edge[1000100],Next[1001000],head[1001000];
bool v[1000010];
priority_queue<pair<int,int> > p;
long long ans;
void add(int x,int y,int z) {
	ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k==0) {
		for(int i=1; i<=m; i++) {
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
			add(y,x,z);
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&c[i]);
			for(int j=1;j<=n;j++){
				scanf("%d",&a[j]);
				add(i+n,j,c[i]+a[j]);
				add(j,i+n,c[i]+a[j]);
			}
		} 
		memset(d,0x3f3f3f,sizeof(d));
		d[1]=0;
		p.push(make_pair(0,1));
		while(p.size()) {
			int x=p.top().second;
			p.pop();
			if(v[x]) continue;
			v[x]=1;
			for(int i=head[x]; i; i=Next[i]) {
				int y=ver[i],z=edge[i];
				if(d[y]>d[x]+z) {
					d[y]=d[x]+z;
					zh[y]=z;
					p.push(make_pair(-d[y],y));
				}
			}
		}
		for(int i=1;i<=n;i++) ans+=zh[i];
		cout<<ans;
	}else cout<<0;
	return 0;
}

