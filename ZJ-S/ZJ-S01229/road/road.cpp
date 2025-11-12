#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,m1,k,i,j,fx,fy,x,y,ans,fl1,fl2,mi,b[20][10010],f[10100],c[30],d[10100],e[30];
struct no{int x,y,z;}a[2000010],a1[2000010];
bool cmp(no t,no w){return t.z<w.z;}
int find(int x){
	if (x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int qiu(){
	int i,j,fx,fy,x,y,s=0,m1;
	m1=m;
	for (i=1;i<=m1;i++) a1[i].x=a[i].x,a1[i].y=a[i].y,a1[i].z=a[i].z;
	for (i=1;i<=n+k;i++) f[i]=i;
	for (i=1;i<=n;i++) d[i]=1;
	for (i=n+1;i<=n+k;i++)
		if (e[i-n]==1){
			for (j=1;j<=n;j++){
				a1[++m1].x=i,a1[m1].y=j,a1[m1].z=b[i-n][j];
			}
			s+=c[i-n];
		}
	sort(a1+1,a1+1+m1,cmp);
	for (i=1;i<=m1;i++){
		x=a1[i].x;y=a1[i].y;
		if (x>=n&&y<=n) swap(x,y);
		fx=find(x);fy=find(y);
		if (fx!=fy){
			s+=a1[i].z;
			f[fy]=fx;d[fx]+=d[fy];
		}
		if (d[fx]==n) break;
	}
	return s;
}
void dfs(int t){
	if (t>k){
		mi=min(mi,qiu());
		return ;
	}
	e[t]=1;dfs(t+1);
	e[t]=0;dfs(t+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	for (i=1;i<=k;i++){
		cin>>c[i];
		for (j=1;j<=n;j++) cin>>b[i][j];
	}
	if (k==0) fl1=1;
	fl2=1;
	for (i=1;i<=k;i++)
		if (c[i]!=0) fl2=0;
	if (fl1||fl2){
		for (i=1;i<=n+k;i++) f[i]=i;
		for (i=1;i<=n;i++) d[i]=1;
		for (i=n+1;i<=n+k;i++)
			for (j=1;j<=n;j++)
				a[++m].x=i,a[m].y=j,a[m].z=b[i-n][j];
		sort(a+1,a+1+m,cmp);
		for (i=1;i<=m;i++){
			x=a[i].x;y=a[i].y;
			if (x>=n&&y<=n) swap(x,y);
			fx=find(x);fy=find(y);
			if (fx!=fy){
				ans+=a[i].z;
				f[fy]=fx;d[fx]+=d[fy];
			}
			if (d[fx]==n) break;
		}
		cout<<ans;
	}
	else{
		mi=1e18;
		dfs(1);
		cout<<mi;
	}
	return 0;
}
