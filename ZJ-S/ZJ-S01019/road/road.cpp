#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const int N=1e6+5,M=1e4+5,K=15;
int T=1;
int n,m,k;
int lg[M];
i64 ans=1e18,sum;
struct node{
	int u,v,w;
	bool operator<(const node &b)const{
		return w<b.w;
	}
}a[N];
struct Node{
	int w,v;
	bool operator<(const Node &a)const{
		return w<a.w;
	}
}b[K][M];
struct Q{
	int i,j,w;
	bool operator<(const Q &a)const{
		return w>a.w;
	}	
};
priority_queue<Q> q;
int f[M+K];
int find(int x){ return x==f[x]?x:f[x]=find(f[x]); }
void solve(){
	for(int i=1;i<=M-5;i++) lg[i]=lg[i>>1]+1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+1+m);
	for(int i=1;i<=k;i++){
		cin>>b[i][0].w;
		for(int j=1;j<=n;j++) cin>>b[i][j].w,b[i][j].v=j;
		sort(b[i]+1,b[i]+1+n);
	}
	for(int l=0,i,t1,t2,ss,fl;l<(1<<k);l++){
		sum=0;
		fl=0;
		ss=0;
		i=1;
		iota(f+1,f+1+n+k,1);
		for(int t=l,p=l&-l,id;t;t-=p,p=t&-t){
			id=lg[p];
			q.push({id,1,b[id][1].w});
			sum+=b[id][0].w;
		}
		while(ss<n-1){
			if(i<=m&&(q.empty()||a[i].w<q.top().w)){
				t1=find(a[i].u),t2=find(a[i].v);
				i++;
				if(t1==t2) continue;
				f[t2]=t1;
				sum+=a[i-1].w;
				ss++;
			}
			else if(!q.empty()){
				Q now=q.top(); q.pop();
				t1=find(n+now.i),t2=find(b[now.i][now.j].v);
				if(t1==t2) continue;
				f[t2]=t1;
				if(now.j>1) ss++;
				sum+=b[now.i][now.j].w;
				if(now.j<n) q.push({now.i,now.j+1,b[now.i][now.j+1].w});
			}
			else {
				fl=1;
				break;
			}
		}
		while(!q.empty()) q.pop();
		if(fl) continue;
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(T--) solve();
	return 0;
} 