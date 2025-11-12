#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
const int N=1e4,M=1e6;
struct edge{
	int l,r,val;
	bool operator<(const edge &X) const{
		return val<X.val;
	}
};
int n,m,k;
int fa[N];
bool flag=1;
vector<edge> v;
vector<edge> tq;
int c[N],a[N][N];
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	int u,qwq,w;
	for(int i=1;i<=m;i++){
		cin>>u>>qwq>>w;
		v.push_back(edge{u,qwq,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];if(c[i])flag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];if(a[i][j])flag=0;
		}
	}
	if(flag&&k){
		cout<<0<<"\n";
		return 0;
	}
		sort(v.begin(),v.end());
		int ans=0,cnt=0;
		for(int i=0;i<m;i++){
			int t1=find(v[i].l),t2=find(v[i].r);
			if(t1!=t2){
				fa[t1]=t2;
				cnt++;
				ans+=v[i].val;
			}
			if(cnt==n-1){
				break;
			}
		}
	if(k==0){	
		cout<<ans<<"\n";
		return 0;
	}
	else{
		for(int q=1;q<=(1<<k)-1;q++){
			int qaq=q,as=0,j=1;
			tq=v;
			while(qaq>0){
				if(qaq&1){
					as+=c[j];
				}
				for(int i=1;i<=n;i++){
					for(int rt=1;rt<=n;rt++){
						tq.pb({i,rt,a[j][i]+a[j][rt]});
					} 
				}
				j++;
				qaq>>=1;
			}
			sort(tq.begin(),tq.end());
		cnt=0;
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=0;i<tq.size();i++){
			int t1=find(tq[i].l),t2=find(tq[i].r);
			if(t1!=t2){
				fa[t1]=t2;
				cnt++;
				as+=tq[i].val;
			}
			if(cnt==n-1){
				break;
			}
		}
			ans=min(as,ans);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
