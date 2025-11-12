#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ve vector
#define pb push_back
#define pii pair<int,int> 
#define p_q priority_queue
#define mk make_pair
#define fi first
#define se second
namespace cute_fzj_kuai_ruarua{
	struct edge{
		int x,y;
		ll w;
		bool f;
	}e[1000005],ee[2000005];
	bool cmp(edge x,edge y){
		return x.w<y.w;
	}
	int n,f[20005],k,a[15][10005],c[15],m;
	int find(int x){
		return f[x]==x?x:f[x]=find(f[x]);
	}
	void main(){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>e[i].x>>e[i].y>>e[i].w;
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++) cin>>a[i][j];
		}
		for(int i=1;i<=n;i++) f[i]=i;
		sort(e+1,e+1+m,cmp);
		ll ans=0;
		for(int i=1;i<=m;i++){
			int xx=find(e[i].x),yy=find(e[i].y);
			if(xx!=yy){
				e[i].f=1;
				f[xx]=yy;
				ans+=e[i].w;
			}
		}
		int cnt=0;
		for(int i=1;i<=m;i++){
			if(e[i].f){
				cnt++;
				ee[cnt]=e[i];
			}
		}
		m=cnt;
		for(int i=1;i<=cnt;i++){
			e[i]=ee[i];
		}
		for(int i=1;i<(1<<k);i++){
			int cnt=0;
			for(int j=1;j<=m;j++){
				cnt++;
				ee[cnt]=e[j];
			}
			ll now_=0,cntpoint=n;
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					cntpoint++;
					now_+=c[j];
					for(int _=1;_<=n;_++){
						cnt++;
						ee[cnt].x=j+n;
						ee[cnt].y=_;
						ee[cnt].w=a[j][_];
					}
				}
			}
			sort(ee+1,ee+1+cnt,cmp);
			for(int j=1;j<=n+k;j++) f[j]=j;
			for(int j=1;j<=cnt;j++){
				int xx=find(ee[j].x),yy=find(ee[j].y);
				if(xx!=yy){
					now_+=ee[j].w;
					cntpoint--;
					if(now_>=ans||cntpoint==1) break;
					f[xx]=yy;
				}
			}
			ans=min(ans,now_);
		}
		cout<<ans;
	}
}
using namespace cute_fzj_kuai_ruarua;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cute_fzj_kuai_ruarua::main();
	return 0;
}
