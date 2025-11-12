#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10100,M=2300000;
int n,m,k,cnt[15],c[15],mn[15],to[15],st[N],e[15][N],a,b,d,h[N],ed[M],ne[M],w[M],idx,sum=1;
long long ans;
struct node{
	int a,b,w;
	bool operator<(const node&o)const{
		return w>o.w;
	}
};
priority_queue<node>q;
void add(int a,int b,int c){
	ed[idx]=b;
	ne[idx]=h[a];
	w[idx]=c;
	h[a]=idx++;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;memset(h,-1,sizeof(h));memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=m;i++){scanf("%d%d%d",&a,&b,&d),add(a,b,d),add(b,a,d);}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)scanf("%d",&e[i][j]);
		q.push({1,n+i,e[i][1]+c[i]});
	}for(int i=h[1];~i;i=ne[i])q.push({1,ed[i],w[i]});
	st[1]=1;
	while(sum<n){
		auto t=q.top();b=t.b;d=t.w;q.pop();
		if(st[b])continue;
		st[b]=1;if(b<=n)sum++;
		if(b>n){b-=n;
			cnt[b]++;
			mn[b]=d;ans+=d;
			for(int i=1;i<=n;i++)if(!st[i])q.push({b+n,i,e[b][i]+d});
		}else if(t.a>b){a=t.a-n;
			if(cnt[a]==1){cnt[a]++;ans+=d-mn[a];
				for(int i=1;i<=n;i++)if(!st[i]&&i!=b)q.push({a+n,i,e[a][i]});
				for(int i=h[b];~i;i=ne[i])q.push({b,ed[i],w[i]});
			}else ans+=d;
			for(int i=h[b];~i;i=ne[i])q.push({b,ed[i],w[i]});
		}else{ans+=d;
			for(int i=h[b];~i;i=ne[i])q.push({b,ed[i],w[i]});
			for(int i=1;i<=k;i++)if(!st[i+n]){q.push({b,i+n,e[i][b]+c[i]});};
		}
	}for(int i=1;i<=k;i++)if(cnt[i]==1)ans-=mn[i];cout<<ans;
}
//2 1 1
//1 2 10
//2 2 9