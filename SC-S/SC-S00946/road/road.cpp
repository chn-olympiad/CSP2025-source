#include<bits/stdc++.h>
using namespace std;
//#define int long long
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,k;
struct op{
	int u,v,w,net;
}e[4000100];
int h[20010],cnt;
int a[15][10010];
void add(int x,int y,int z){
	e[++cnt].v=y;
	e[cnt].u=x;
	e[cnt].w=z;
	e[cnt].net=h[x];
	h[x]=cnt;
}
int cn[1000100],len;
int mo[2000100];
bool cmp(int x,int y){
	return e[x].w<e[y].w;
}
int fa[1000100];
int fi(int o){
	if(fa[o]!=o) return fa[o]=fi(fa[o]);
	return o;
}
long long ans=0,he;
int cu[200100];
bool p=1,p2;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w);
		cn[++len]=cnt;
		fa[i]=i;
	}
	if(k==0){
		sort(cn+1,cn+len+1,cmp);
		for(int i=1;i<=len;i++){
			if(fi(e[cn[i]].v)!=fi(e[cn[i]].u)){
				fa[fa[e[cn[i]].v]]=fa[e[cn[i]].u];
				ans+=e[cn[i]].w;
				he++;
				if(he==n-1) break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			a[i][j]=read();
			if(j!=0&&a[i][j]==0) cu[i]=j;
		}
		if(a[i][0]!=0||cu[i]==0) p=0;
	}
	if(p){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(j==cu[i]) continue;
				add(cu[i],j,a[i][j]);
				cn[++len]=cnt;
			}
		}
		sort(cn+1,cn+len+1,cmp);
		for(int i=1;i<=len;i++){
			if(fi(e[cn[i]].v)!=fi(e[cn[i]].u)){
				fa[fa[e[cn[i]].v]]=fa[e[cn[i]].u];
				ans+=e[cn[i]].w;
				he++;
				if(he==n-1) break;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		sort(cn+1,cn+len+1,cmp);
		for(int i=1;i<=len;i++){
			if(fi(e[cn[i]].v)!=fi(e[cn[i]].u)){
				fa[fa[e[cn[i]].v]]=fa[e[cn[i]].u];
				cn[++he]=cn[i];
				ans+=e[cn[i]].w;
				if(he==n-1) break;
			}
		}
		for(int i=0;i<(1<<k);i++){
			for(int j=1;j<=n-1;j++) mo[j]=cn[j],fa[j]=j;
//			for(int j=1;j<=n-1;j++) cout<<mo[j]<<" ";
//			cout<<endl;
			fa[n]=n;
			long long mi=0,cn1=0;
			p2=1;
			int opo=n-1;
			cnt=m+1;
			for(int j=1;j<=k;j++){
				if(i&(1<<(j-1))){
					if(ans<a[j][0]){
						p2=0;
						break;
					}
					mi+=a[j][0];
					cn1++;
					for(int l=1;l<=n;l++){
						add(l,cn1+n,a[j][l]);
						mo[++opo]=cnt;
					}
				}
			}
			for(int j=n+1;j<=n+k;j++) fa[j]=j;
//			cout<<ans<<"?????"<<endl;
			if(p2==0) continue;
//			cout<<i<<"!!!"<<endl;
//			for(int j=1;j<=opo;j++) cout<<mo[j]<<" ";
//			cout<<endl;
			he=0;
			sort(mo+1,mo+opo+1,cmp);
			for(int j=1;j<=opo;j++){
				if(fi(e[mo[j]].v)!=fi(e[mo[j]].u)){
					fa[fa[e[mo[j]].v]]=fa[e[mo[j]].u];
					mi+=e[mo[j]].w;
					he++;
					if(he==n+cn1-1) break;
				}
			}
			ans=min(ans,mi);
		}
		cout<<ans;
	}
	
	return 0;
}