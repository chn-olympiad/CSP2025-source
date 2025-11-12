#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=3e6+10,M=12,T=1e4+10,INF=1e17;
struct edge{
	LL u,v,w;
}e[N],ne[N];
LL fa[N],n,m,k,ss=1,ans;
LL c[M],st[M];
LL s[M][T];
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(edge A,edge B){
	return A.w<B.w;
}
inline void ksl(){
	int mm=0;
	for(int i=1;i<=m;i++) ne[i]=e[i];
	sort(ne+1,ne+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=ne[i].u,v=ne[i].v,w=ne[i].w;
		int a=find(u),b=find(v);
		if(a!=b){
			fa[a]=b;
			ans+=w;mm++;
			if(mm==n-1) break;
		}
	}
	return;
}
int main(){
	freopen("road4.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+30;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int stk=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];ss*=2;
		for(int j=1;j<=n;j++){
			cin>>s[i][j];
		}
		if(c[i]!=0){
			stk=1;
		}
	}
	if(!stk){
		int nm=m,nt=n;
		for(int j=1;j<=k;j++){
			ans+=c[j];++n;
			for(int t=1;t<=nt;t++){
				e[++m]={n,t,s[j][t]};
			}
		}
		for(int j=1;j<=n+30;j++) fa[j]=j;
		ksl();
		cout<<ans;
	}
	else{
		LL res=INF;
		for(int i=0;i<ss;i++){
			ans=0;int opsl=0;
			for(int j=1;j<=k;j++){
				if(((i>>(j-1))&1)==1) {
					st[j]=1;opsl++;
				}
				else st[j]=0;
			}
			if(i>60&&opsl>3) continue;
			int nm=m,nt=n;
			for(int j=1;j<=k;j++){
				if(st[j]==1){
					ans+=c[j];++n;
					for(int t=1;t<=nt;t++){
						e[++m]={n,t,s[j][t]};
					}
				}
			}
			if(ans>res) continue;
			for(int j=1;j<=n+30;j++) fa[j]=j;
			ksl();
			res=min(res,ans);
			m=nm,n=nt;
		}
		cout<<res;
	}
	return 0;
}