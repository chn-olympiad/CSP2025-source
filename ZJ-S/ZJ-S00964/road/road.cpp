#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10020,maxm=1100010;
int fath[maxn],vis[20],cap[20],sta[maxn];
pair<int,pair<int,int> >edge[maxm];
inline int read(){
	int num=0; char ch=getchar();
	while(ch<'0' or ch>'9') ch=getchar();
	while(ch>='0' and ch<='9'){
		num=(num<<3)+(num<<1)+(ch^48);
		ch=getchar();
	}
	return num;
}
inline int find(int u){
	int top=1;
	sta[1]=u;
	while(fath[u]!=u) sta[++top]=u=fath[u];
	while(top) fath[sta[top--]]=u;
	return u;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		edge[i]=make_pair(w,make_pair(u,v));
	}
	sort(edge+1,edge+1+m);
	for(int i=1;i<=n;i++) fath[i]=i;
	int tot=0;
	for(int i=1;i<=m;i++){
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		int w=edge[i].first;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fath[fv]=fu;
			edge[++tot]=edge[i];
			if(tot==n-1) break;
		}
	}
	for(int i=1;i<=k;i++){
		cap[i]=read();
		for(int j=1;j<=n;j++){
			edge[++tot]=make_pair(read(),make_pair(j,n+i));
		}
	}
	sort(edge+1,edge+1+tot);
	ll ans=1e18;
	for(int sta=0;sta<(1<<k);sta++){
		ll sum=0;
		int num=0;
		for(int i=0;i<k;i++){
			if(((sta>>i)&1)){
				vis[i+1]=1,++num;
				sum+=cap[i+1];
			}
			else vis[i+1]=0;
		}
		for(int i=1;i<=n+k;i++) fath[i]=i;
		int xyq=n+num-1;
		for(int i=1;i<=tot;i++){
			int u=edge[i].second.first;
			int v=edge[i].second.second;
			int w=edge[i].first;
			if(v>n and !vis[v-n]) continue;
			int fu=find(u),fv=find(v);
			if(fu!=fv){
				--xyq;
				fath[fv]=fu;
				sum+=w;
				if(!xyq) break;
			}
		}
		if(!xyq) ans=min(ans,sum);
	}
	cout<<ans<<"\n";
	return 0;
}