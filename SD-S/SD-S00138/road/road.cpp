#include<bits/stdc++.h>
#define f(i,a,b) for(auto i=a;i<=b;i++)
using namespace std;
const int maxm=1e6+10,maxn=1e5+10;
struct fan{
	int u,v,w;
}e[maxm*2];
int fa[maxn],c[maxn],a[11][maxn],cnt,dis[1010][1010],qwq;
bool cmp(fan a,fan b){
	return a.w<b.w;
}int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	f(i,1,m){
		int x,y,z;cin>>x>>y>>z;
		e[++cnt]={x,y,z};
		e[++cnt]={y,x,z};
	}
	f(i,1,k){
		cin>>c[i];if(!c[i]) qwq++;
		f(j,1,n) cin>>a[i][j];
	}if(!k){long long ans=0,ch=0;
		sort(e+1,e+1+cnt,cmp);
		f(i,1,n) fa[i]=i;
		f(i,1,cnt){
			int x=find(e[i].u),y=find(e[i].v);
			if(x!=y){
				fa[x]=y;ch++;
				ans+=1ll*e[i].w;
			}if(ch==n-1) break;
		}cout<<ans<<'\n';
	}else if(n<=1000&&qwq==k){
		memset(dis,0x3f,sizeof dis);
		f(i,1,n) dis[i][i]=0;
		f(i,1,cnt){
			dis[e[i].u][e[i].v]=min(dis[e[i].u][e[i].v],e[i].w);
			dis[e[i].v][e[i].u]=min(dis[e[i].v][e[i].u],e[i].w);
		}f(cc,1,k) f(i,1,n) f(j,1,n) if(i!=j) dis[i][j]=min(dis[i][j],a[cc][i]+a[cc][j]);
		cnt=0;f(i,1,n) f(j,1,n) if(i!=j) if(i!=j) e[++cnt]={i,j,dis[i][j]};
		sort(e+1,e+1+cnt,cmp);
		f(i,1,n) fa[i]=i;int ch=0;long long ans=0;
		f(i,1,cnt){
			int x=find(e[i].u),y=find(e[i].v);
			if(x!=y){
				fa[x]=y;ch++;
				ans+=1ll*e[i].w;
			}if(ch==n-1) break;
		}cout<<ans<<'\n';
	}else{long long ans=100000000000000000,qq=cnt;
		f(i,0,(1<<k)-1){long long sum=0;vector<int> xx;cnt=qq;
			f(j,0,k-1) if(i&(1<<j)) sum+=c[j+1],xx.push_back(j+1);
			memset(dis,0x3f,sizeof dis);
			f(i,1,n) dis[i][i]=0;
			f(i,1,cnt){
				dis[e[i].u][e[i].v]=min(dis[e[i].u][e[i].v],e[i].w);
				dis[e[i].v][e[i].u]=min(dis[e[i].v][e[i].u],e[i].w);
			}for(auto it:xx) f(i,1,n) f(j,1,n) if(i!=j) dis[i][j]=min(dis[i][j],a[it][i]+a[it][j]);
			cnt=0;f(i,1,n) f(j,1,n) if(i!=j) if(i!=j) e[++cnt]={i,j,dis[i][j]};
			sort(e+1,e+1+cnt,cmp);
			f(i,1,n) fa[i]=i;int ch=0;
			f(i,1,cnt){
				int x=find(e[i].u),y=find(e[i].v);
				if(x!=y){
					fa[x]=y;ch++;
					sum+=1ll*e[i].w;
				}if(ch==n-1) break;
			}
			ans=min(ans,sum);
		}cout<<ans<<endl;
	}
	return 0;
}
