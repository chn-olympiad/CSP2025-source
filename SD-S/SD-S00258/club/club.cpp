#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr int N=1e5+100,M=1e6+100;

constexpr int MOD=998244353;

int n;

struct node{
	int v[4];
};node c[N];

vector<int> vec[4];

int cnt[4];

ll ans=0;

pair<int,int> minn[N];

bool vis[N][4];

inline bool cmp1(node x,node y){
	if(x.v[1]>y.v[1]){
		return 1;
	}
	if(x.v[1]==y.v[1]){
		int max1=max(x.v[2],x.v[3]),max2=max(y.v[2],y.v[3]);
		return max1>max2;
	}
	return 0;
}

inline void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		minn[i]=make_pair(INT_MAX,0);
	}
	for(int i=1;i<=n;i++){
		int maxn=-1,pos=0;
		for(int j=1;j<=3;j++){
			cin>>c[i].v[j];
			if(c[i].v[j]>maxn){
				pos=j;
				maxn=c[i].v[j];
			}
		}
		for(int j=1;j<=3;j++){
			if(c[i].v[j]!=maxn){
				if((maxn-c[i].v[j])<minn[i].first){
					minn[i].first=(maxn-c[i].v[j]);
					minn[i].second=j;
				}
			}
		}
		vec[pos].push_back(i);
		cnt[pos]++;
	}
	int maxc=max(cnt[1],max(cnt[2],cnt[3]));
	if(maxc<=(n/2)){
		for(int i=1;i<=3;i++){
			for(auto id:vec[i]){
				ans+=c[id].v[i];
			}
		}
		cout<<ans<<'\n';
		return ;
	}
	if(maxc==cnt[1]){
//		cout<<"kk\n";
		sort(vec[1].begin(),vec[1].end(),[&](int x,int y){
			return minn[x].first<minn[y].first;
		});
//		for(auto id:vec[1]){
//			cout<<id<<' ';
//		}
//		cout<<'\n';
		for(auto id:vec[1]){
			cnt[1]--;
			cnt[minn[id].second]++;
			vec[minn[id].second].push_back(id);
//			cout<<minn[id].second<<'\n';
			vis[id][1]=1;
			if(cnt[1]<=(n/2)){
				for(int i=1;i<=3;i++){
					for(auto idx:vec[i]){
						if(!vis[idx][i]){
							
							ans+=c[idx].v[i];
						}
					}
				}
				cout<<ans<<'\n';
				return ;
			}
		}
	}
	if(maxc==cnt[2]){
		sort(vec[2].begin(),vec[2].end(),[&](int x,int y){
			return minn[x].first<minn[y].first;
		});
		for(auto id:vec[2]){
			cnt[2]--;
			cnt[minn[id].second]++;
			vec[minn[id].second].push_back(id);
			vis[id][2]=1;
			if(cnt[2]<=(n/2)){
				for(int i=1;i<=3;i++){
					for(auto idx:vec[i]){
						if(!vis[idx][i]){
							
							ans+=c[idx].v[i];
						}
					}
				}
				cout<<ans<<'\n';
				return ;
			}
		}
	}
	if(maxc==cnt[3]){
		sort(vec[3].begin(),vec[3].end(),[&](int x,int y){
			return minn[x].first<minn[y].first;
		});
		for(auto id:vec[3]){
			cnt[3]--;
			cnt[minn[id].second]++;
			vec[minn[id].second].push_back(id);
			vis[id][3]=1;
			if(cnt[3]<=(n/2)){
				for(int i=1;i<=3;i++){
					for(auto idx:vec[i]){
						if(!vis[idx][i]){
							
							ans+=c[idx].v[i];
						}
					}
				}
				cout<<ans<<'\n';
				return ;
			}
		}
	}
}

inline void clr(){
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			c[i].v[j]=0;
		}
	}
	vec[1].clear();
	vec[2].clear();
	vec[3].clear();
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL),cout.tie(NULL);
	int T=1;
	cin>>T;
	while(T--){
		clr();
		solve();
	}
	return 0;
}

