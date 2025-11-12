#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e6+10;
const int M=1e4+10;
const int O=1e5;
struct node{
	int u,v,w,q;
}e[N];
int n,m,k,c[15],a[15][M];
int f[O];
bool b[15];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x];
}
int add(int x,int y){
	f[x]=y;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		e[i]={u,v,w,0};
	}
	bool F=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0)F=1;
		}
	}
	if(F==0){
		cout<<0<<endl;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++)f[i]=i;
		int ans=0,cnt=0;
		sort(e+1,e+1+n,cmp);
		for(int i=1;i<=n;i++){
			int u=e[i].u,v=e[i].v;
			if(find(u)!=find(v)){
				add(u,v);
				ans+=e[i].w;
				cnt++;
			}
			if(cnt==n-1)break;
		}
		cout<<ans<<endl;
	}else{
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				m++;
				e[m]={i+n,j,a[i][j]+c[i],c[i]};
			}
		}
		for(int i=1;i<=n+k;i++)f[i]=i;
		sort(e+1,e+1+m,cmp);
		int ans=0,cnt=0,nn=n;
		for(int i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v;
			if(e[i].q>0){
				if(find(u)!=find(v)){
					add(u,v);
					ans+=e[i].w;
					cnt++;
				
				}
				b[u]=1;
				for(int j=i+1;j<=m;j++){
					if(e[j].u==u){
						e[j].w-=c[u-n];
						e[j].q=0;
					}
				}
				sort(e+i,e+i+(m-i+1),cmp);
				nn++;
			}else{
				if(find(u)!=find(v)){
					add(u,v);
					ans+=e[i].w;
					cnt++;
			
				}
			}
			if(cnt==nn-1)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
