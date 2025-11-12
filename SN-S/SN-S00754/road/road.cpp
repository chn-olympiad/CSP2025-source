//SN-S00754  陈钰婉  西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct edge{
	int u,v,w;
}e[2*maxn],q[5*maxn];
int c[maxn],ans=1e18;
struct node{
	int to,val;
};
vector<node> a[15];

inline bool cmp(edge a,edge b){
	return a.w<b.w;
}
int f[maxn];
inline int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
inline void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) f[fx]=fy;
}

inline int kruscal(edge e[],int n,int m){
	int ans=0,cnt=0; 
	sort(e+1,e+1+m,cmp);
	iota(f+1,f+1+n,1);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v)) continue;
		merge(u,v);
		ans+=e[i].w,cnt++;
		if(cnt==n-1) break;
	} 
	if(cnt!=n-1) return -1;
	else return ans;
}

int b[maxn];

#define mk make_pair
void dfs(int x){
	if(x==k+1){
		map<pair<int,int>,int> mp;
		int cnt=0;
		for(int i=1;i<=m;i++){
			q[++cnt]=e[i];
			mp[mk(e[i].u,e[i].v)]=e[i].w;
		}
		int sum=0;
		for(int i=1;i<=k;i++){
			if(b[i]==1){//第i个乡镇被修复 
				for(auto x:a[i]){
					for(auto y:a[i]){
						if(x.to==y.to) continue;
						int t=mp[mk(x.to,y.to)];
						if(t==0){
							q[++cnt]=(edge){x.to,y.to,x.val+y.val};
							mp[mk(x.to,y.to)]=x.val+y.val;
						}
						else{
							if(x.val+y.val<t){
								q[++cnt]=(edge){x.to,y.to,x.val+y.val};
								mp[mk(x.to,y.to)]=x.val+y.val;
							}
						}
					}
				}
				sum+=c[i];
			}
		}
		sort(q+1,q+1+cnt,cmp);
		ans=min(ans,kruscal(q,n,cnt)+sum);
		return;
	}
	b[x]=0;
	dfs(x+1);
	b[x]=1;
	dfs(x+1);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	ans=min(ans,kruscal(e,n,m));
	if(k==0){
		cout<<ans<<endl;
		return 0;
	}
	
	int fl=0;
	for(int i=1;i<=k;i++){//建造第k个乡镇 
		cin>>c[i];
		if(c[i]!=0) fl=1;
		for(int j=1,x;j<=n;j++){
			cin>>x;
			a[i].push_back((node){j,x});
		}
	}
	
	if(fl==0){
		int cnt=0;
		map<pair<int,int>,int> mp;
		for(int i=1;i<=m;i++){
			q[++cnt]=e[i];
			if(e[i].u>e[i].v) swap(e[i].u,e[i].v);
			mp[mk(e[i].u,e[i].v)]=e[i].w;
		}
		
		for(int i=1;i<=k;i++){
			for(auto x:a[i]){
				for(auto y:a[i]){
					if(x.to==y.to) continue;
					int t=mp[mk(x.to,y.to)];
					if(t==0){
						q[++cnt]=(edge){x.to,y.to,x.val+y.val};
						mp[mk(x.to,y.to)]=x.val+y.val;
					}
					else{
						if(x.val+y.val<t){
							q[++cnt]=(edge){x.to,y.to,x.val+y.val};
							mp[mk(x.to,y.to)]=x.val+y.val;
						}
					}
				}
			}
		}
		sort(q+1,q+1+cnt,cmp);
		ans=min(ans,kruscal(q,n,cnt));
		cout<<ans<<endl;
		return 0; 
	}
	
	dfs(1);
	cout<<ans<<endl;
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
