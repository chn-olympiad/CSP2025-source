#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,c[12],fa[100005],r[12],now[12],tot,ans,mx,t;
void read(ll &x){
	x=0;
	char y=getchar();
	while(y<'0'||y>'9'){
		y=getchar();
	}
	while(y>='0'&&y<='9'){
		x=x*10+y-'0';
		y=getchar();
	}
}
ll find(ll x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
struct md{
	ll x,y,z;
};
md b[1000006],a[12][10004],d[1000006];
int cmp(md x,md y){
	if(x.z<y.z){
		return 1;
	}
	return 0;
}
void q(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=t+1;i++){
		r[i]=1;
	}
	for(int i=1;i<=n+t-1;i++){
		md mi;
		mi.z=(ll)1e18;
		for(int j=1;j<=t;j++){
			while(r[j]!=n+1&&find(a[now[j]][r[j]].x)==find(a[now[j]][r[j]].y)){
				r[j]++;
			}
			if(r[j]==n+1){
				continue;
			}
			if(a[now[j]][r[j]].z<mi.z){
				mi=a[now[j]][r[j]];
			}
		}
		while(r[t+1]!=tot+1&&find(d[r[t+1]].x)==find(d[r[t+1]].y)){
			r[t+1]++;
		}
		if(r[t+1]!=tot+1&&d[r[t+1]].z<mi.z){
			mi=d[r[t+1]];
		}
		fa[fa[mi.x]]=fa[mi.y];
		mx+=mi.z;
	}
	ans=min(ans,mx);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=(ll)1e18;
	//cin>>n>>m>>k;
	read(n);
	read(m);
	read(k);
	for(int i=1;i<=m;i++){
		//cin>>b[i].x>>b[i].y>>b[i].z;
		read(b[i].x);
		read(b[i].y);
		read(b[i].z);
	}
	sort(b+1,b+m+1,cmp);
	
	
	for(int i=1;i<=k;i++){
		//cin>>c[i];
		read(c[i]);
		for(int j=1;j<=n;j++){
			//cin>>a[i][j].z;
			read(a[i][j].z);
			a[i][j].x=i+n;
			a[i][j].y=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	
	
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(find(b[i].x)==find(b[i].y)){
			continue;
		}
		fa[fa[b[i].x]]=fa[b[i].y];
		d[++tot]=b[i];
	}
	
	
	for(int i=0;i<(1<<k);i++){
		t=0;
		mx=0;
		for(int j=1;j<=k;j++){
			if(((i>>(j-1))&1)==1){
				now[++t]=j;
				mx+=c[j];
			}
		}
		q();
	}
	cout<<ans<<endl;
}
