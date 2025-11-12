#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int M=3e3+5;
const int mod=1e9+7;
const int eps=1e-6;
struct node{
	int u,v,w;
}e[N];
int fa[N],a[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool cmp(node A,node B){
	return A.w<B.w;
}
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int n,m,k;
int ans,cnt,pos;
int mp[M][M];
void solve(){
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	if(n>3e3){
		for(int i=1;i<=m;i++){
			e[i].u=read();
			e[i].v=read();
			e[i].w=read();
		}
		pos=m;
		for(int i=1;i<=k;i++){
			int c=read();
			for(int j=1;j<=n;j++)a[j]=read();
			for(int j=1;j<=n;j++){
				for(int oi=j+1;oi<=n;oi++){
					pos++;
					if(pos>1e6)	break;
					e[pos].u=j;
					e[pos].v=oi;
					e[pos].w=a[j]+a[oi]+c;
	//				cout<<j<<' '<<oi<<' '<<a[j]<<' '<<a[oi]<<' '<<c<<'\n';
				}
				if(pos>1e6)break;
			}
			if(pos>1e6)break;
		}
	}
	else{
		memset(mp,0x3f,sizeof mp);
		for(int i=1;i<=n;i++)mp[i][i]=0;
		for(int i=1,u,v,w;i<=m;i++){
			cin>>u>>v>>w;
			if(u>v)swap(u,v);
			mp[u][v]=min(mp[u][v],w);
		}
		for(int i=1;i<=k;i++){
			int c=read();
			for(int j=1;j<=n;j++)a[j]=read();
			for(int j=1;j<=n;j++)
				for(int oi=j+1;oi<=n;oi++)
					mp[j][oi]=min(mp[j][oi],a[j]+a[oi]+c);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(mp[i][j]!=0x3f3f3f3f3f3f3f3f){
					e[++pos].u=i;
					e[pos].v=j;
					e[pos].w=mp[i][j];
				}
			}
		}
	}
	
//	cout<<"1\n";
	sort(e+1,e+1+pos,cmp);
	for(int i=1;i<=pos;i++){
//		cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<'\n';
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		cnt++;
		ans+=e[i].w;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}

