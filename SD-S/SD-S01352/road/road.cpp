#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,m,k,u,v,w;
vector<pair<int,int> >g[10015];
int c[15];
int vis[10015],dis[10015];
int flg1=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x3f3f3f3f,sizeof dis);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]>0) flg1=1;
		int f=0;
		for(int j=1;j<=n;j++){
			cin>>w;
			if(w==0) f=1;
			g[n+i].push_back({j,w});
			g[j].push_back({n+i,w});
		}
		if(f==0) flg1=1;
	}
	if(k==0||flg1==0){
		long long ans=0;
		dis[1]=0;
		for(int i=1;i<=n+k;i++){
			int minn=0x3f3f3f3f,p=0;
			for(int i=1;i<=n+k;i++){
				if(vis[i]) continue;
				if(dis[i]<minn){
					minn=dis[i];
					p=i;
				}
			}
			vis[p]=1;
			ans=ans+minn;
			for(auto wx:g[p]){
				if(vis[wx.first]) continue;
				dis[wx.first]=min(dis[wx.first],wx.second);
			}
		}
		cout<<ans<<" ";
	}else{
		long long ans1=-1;
		for(int nowb=0;nowb<(1<<k);nowb++){
			long long ans=0;
			memset(dis,0x3f3f3f3f,sizeof dis);
			for(int i=1;i<=n+k;i++){
				vis[i]=0;
			}
			for(int i=1;i<=k;i++){
				int now=(nowb>>(i-1))&1;
				vis[n+i]=now;
				if(now==0){
					ans=ans+c[i];
				}
			}
			dis[1]=0;
			for(int i=1;i<=n+k;i++){
				int minn=0x3f3f3f3f,p=0,f=0;
				for(int i=1;i<=n+k;i++){
					if(vis[i]) continue;
					f=1;
					if(dis[i]<minn){
						minn=dis[i];
						p=i;
					}
				}
				if(f==0) break;
				vis[p]=1;
				ans=ans+minn;
				for(auto wx:g[p]){
					if(vis[wx.first]) continue;
					dis[wx.first]=min(dis[wx.first],wx.second);
				}
			}
			if(ans1==-1) ans1=ans;
			else ans1=min(ans,ans1);
		}
		cout<<ans1;
	}
	return 0;
}
