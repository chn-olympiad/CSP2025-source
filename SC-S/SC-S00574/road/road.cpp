#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[10005];
long long ans;
struct caoi{
	long long u,v,w;
	long long id;
}a[2000005];
long long c[15][10005];
bool cmp(caoi ll,caoi rr){
	return ll.w<rr.w;
}
long long find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool vis[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int xb=m,flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		if(c[i][0]!=0)flag=1;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]!=0)flag=1;
		}	
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	if(k!=0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long hh=0x3f3f3f3f3f3f3f3f,ii;
				for(int l=1;l<=k;l++){
					if(hh>c[l][i]+c[l][j]+c[l][0]){
						hh=c[l][i]+c[l][j]+c[l][0];
						ii=l;
					}
				}
				a[++xb].u=i;a[xb].v=j;a[xb].w=hh;a[xb].id=ii;
			}
		}
	}
	sort(a+1,a+1+xb,cmp);
	int bs=0;
	for(int i=1;i<=xb;i++){
		int x=find(a[i].u);
		int y=find(a[i].v);
		if(x!=y){
			++bs;
			f[x]=y;
			ans+=a[i].w;
			if(a[i].id!=0){
				if(!vis[a[i].id]){
					vis[a[i].id]=1;
				}else{
					ans-=c[a[i].id][0];
				}
			}
		}
		if(bs==n-1)break;
	}
	cout<<ans;
	return 0;
}