#include<bits/stdc++.h>
using namespace std;
struct st{
	int u,v;
	long long w;
	int id;
}e[2000001];
bool cmp(st a,st b){
	return a.w<b.w;
}
int f[1201][10011];
int find(int x,int s){
	if(f[s][x]==x) return x;
	return f[s][x]=find(f[s][x],s);
}
long long ans[1201],ANS;
int n,m,k,N;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w,0};
	}
	N=1<<k;
	for(int i=1;i<=k;i++){
		int w;
		cin>>w;
		for(int j=1;j<N;j++){
			if(j&(1<<(i-1))){
				ans[j]+=w;
			}
		}
		for(int j=1;j<=n;j++){
			cin>>w;
			e[++m]={i,j,w,i};
		}
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n+k;i++){
		for(int j=0;j<N;j++){
			f[j][i]=i;
		}
	}
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v,w=e[i].w,id=e[i].id;
		//cout<<x<<" "<<y<<" "<<w<<" "<<id<<endl;
		if(id){
			for(int j=1;j<N;j++){
				if(!(j&(1<<(id-1)))) continue;
				int fx=find(x+n,j),fy=find(y,j);
				if(fx==fy) continue;
				f[j][fx]=f[j][fy],ans[j]+=w;
				//if(j==1) cout<<x+n<<" "<<y<<" "<<w<<endl;
			}
			continue;
		}
		int fx=find(x,0),fy=find(y,0);
		if(fx==fy) continue;
		f[0][fx]=f[0][fy],ans[0]+=w;
		for(int j=1;j<N;j++){
			fx=find(x,j),fy=find(y,j);
			if(fx==fy) continue;
			f[j][fx]=f[j][fy],ans[j]+=w;
			//	if(j==1) cout<<x<<" "<<y<<" "<<w<<endl;
		}
	}
	ANS=ans[0];
	for(int j=1;j<N;j++) ANS=min(ANS,ans[j]);
	cout<<ANS;
	return 0;
}
