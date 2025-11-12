#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+10;
const int M=20;
int n,m,k,D[M][N],len,c[N],fa[N*2],si[N*2];
LL ans=0;
bool o=true;
struct Node {
	int x,y,z;
} a[N*2],d[N*2],t[N*2];
int read() {
	int t=0;
	int f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		t=(t<<3)+(t<<1)+(c^'0');
		c=getchar();
	}
	return t*f;
}
int Find(int x) {
	return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Merge(int x,int y) {
	int fx=Find(x);
	int fy=Find(y);
	if(si[fx]>si[fy]) {
		si[fx]+=si[fy];
		fa[fy]=fx;
	} else {
		si[fy]+=si[fx];
		fa[fx]=fy;
	}
}
bool cmp(Node x,Node y) {
	return x.z<y.z;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1; i<=m; i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
	for(int i=1; i<=k; i++) {
		c[i]=read();
		if(c[i]!=0) o=false;
		for(int j=1; j<=n; j++) D[i][j]=read();
	}
	for(int i=1; i<=n; i++) fa[i]=i,si[i]=1;
	sort(a+1,a+1+m,cmp);
	for(int i=1; i<=m; i++) {
		if(Find(a[i].x)!=Find(a[i].y)) {
			Merge(a[i].x,a[i].y);
			ans+=a[i].z;
			d[++len]=a[i];
		}
	}
	int ma=(1<<k)-1;
	if(o==true) {
		for(int i=ma; i<=ma; i++) {
			LL num=0;
			for(int j=1; j<=n+k; j++) fa[j]=j,si[j]=1;
			int Len=len;
			for(int j=1; j<=len; j++) t[j]=d[j];
			int cnt=n;
			for(int j=1; j<=k; j++) {
				if((i>>(j-1))&1) {
					num+=c[j];
					cnt++;
					for(int l=1; l<=n; l++) t[++Len]= {n+j,l,D[j][l]};
				}
			}
			sort(t+1,t+1+Len,cmp);
			int o=0;
			for(int j=1; j<=Len; j++) {
				int fx=Find(t[j].x);
				int fy=Find(t[j].y);
				if(fx!=fy) {
					Merge(fx,fy);
					num+=t[j].z;
					o++;
					if(o==cnt-1) break;
				}
			}
			ans=min(ans,num);
		}
		cout<<ans;
	} else {
		for(int i=0; i<=ma; i++) {
			LL num=0;
			for(int j=1; j<=n+k; j++) fa[j]=j,si[j]=1;
			int Len=len;
			for(int j=1; j<=len; j++) t[j]=d[j];
			int cnt=n;
			for(int j=1; j<=k; j++) {
				if((i>>(j-1))&1) {
					num+=c[j];
					cnt++;
					for(int l=1; l<=n; l++) t[++Len]= {n+j,l,D[j][l]};
				}
			}
			sort(t+1,t+1+Len,cmp);
			int o=0;
			for(int j=1; j<=Len; j++) {
				int fx=Find(t[j].x);
				int fy=Find(t[j].y);
				if(fx!=fy) {
					Merge(fx,fy);
					num+=t[j].z;
					o++;
					if(o==cnt-1) break;
				}
			}
			ans=min(ans,num);
		}
		cout<<ans;
	}
	return 0;
}

