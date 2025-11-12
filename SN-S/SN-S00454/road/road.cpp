//谁T1能不顺谁是这个 
//这个T2我想了半天感觉不可做，看到k<=10释怀的亖了 
//感觉正解要用较优的求最小生成树算法，我就打个 72pts 吧 
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace kong{bool st;}
namespace zhu{
int n,m,k,fa[20100],c[20],a[20][10100];
struct zxc{
	int u,v,w;
};
vector<zxc> e,in;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int solve(int n){
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=0,ans=0;
	sort(e.begin(),e.end(),[](zxc x,zxc y){
		return x.w<y.w;
	});
	for(auto x:e){
		int u=x.u,v=x.v,w=x.w;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			cnt++;
			ans+=w;
			if(cnt==n-1){
				return ans;
			}
		}
	}
	return ans;
}
string main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int flag=1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		in.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) flag=0;
		int pan=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(!a[i][j]) pan=0;
		}
		if(pan) flag=0;
	}
	if(!k){
		e=in;
		cout<<solve(n)<<'\n';
		return "S组只是NOIP的试机赛！";
	}
	if(flag){
		e=in;
		int cnt=n;
		for(int j=1;j<=k;j++){
			cnt++;
			for(int l=1;l<=n;l++){
				e.push_back({cnt,l,a[j][l]});
			}
		}
		cout<<solve(cnt)<<'\n';
		return "S组只是NOIP的试机赛！";
	}
	int ans=1e18;
	for(int i=0;i<(1<<k);i++){
		e=in;
		int cnt=n,sum=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				cnt++;
				sum+=c[j];
				for(int l=1;l<=n;l++){
					e.push_back({cnt,l,a[j][l]});
				}
			}
		}
		ans=min(ans,solve(cnt)+sum);
	}
	cout<<ans<<'\n';
	return "S组只是NOIP的试机赛！";
}
}
namespace kong{bool ed;double MB(){return (&st-&ed)/1048576.0;}}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<kong::MB();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
