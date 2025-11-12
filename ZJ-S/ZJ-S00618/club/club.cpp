#include<bits/stdc++.h>
#define pi pair<int,int>
#define ay array<int,2>
//#define int long long
#define fi first
#define se second
const int N=1e5+7;
const int inf=2e9+114514;
using namespace std;
int n,v[N],cnt[4];
array<int,4> a[N*3];
pi b[N][4];
int cmp(array<int,4> x,array<int,4> y){
	return x[0]>y[0];
}
int cmp1(pi x,pi y){
	return x.fi>y.fi;
}
void solve(){
	cin>>n;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++){
		v[i]=0;
		cin>>b[i][0].fi>>b[i][1].fi>>b[i][2].fi;
		b[i][0].se=0,b[i][1].se=1,b[i][2].se=2;
		sort(b[i],b[i]+3,cmp1);
		a[(i-1)*3+1]={b[i][0].fi,b[i][0].se,i,b[i][0].fi-b[i][1].fi};
		a[(i-1)*3+2]={b[i][1].fi,b[i][1].se,i,b[i][1].fi-b[i][2].fi};
		a[(i-1)*3+3]={b[i][2].fi,b[i][2].se,i,inf};
		
	}
	int ans=0;
	sort(a+1,a+3*n+1,cmp);
	priority_queue<ay,vector<ay>,greater<ay>>q[3];
	for(int i=1;i<=3*n;i++){
		if(v[a[i][2]])continue;
		if(cnt[a[i][1]]==n/2){
			if(!q[a[i][1]].empty()){
				auto x=q[a[i][1]].top();
				if(x[0]<a[i][3]){
					q[a[i][1]].pop();
					int now;
					for(int j=0;j<3;j++)if(b[x[1]][j].se==a[i][1])now=j+1;
					if(now!=2)q[b[x[1]][now].se].push({b[x[1]][now].fi-b[x[1]][now+1].fi,x[1]});
					ans+=a[i][0]-x[0];
					v[a[i][2]]=1;
					if(a[i][3]!=inf)q[a[i][1]].push({a[i][3],a[i][2]});
				}
			}
			continue;
		}
		cnt[a[i][1]]++;v[a[i][2]]=1;
		ans+=a[i][0];
		if(a[i][3]!=inf)q[a[i][1]].push({a[i][3],a[i][2]});
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	cin>>T;
	while(T--)solve();
}