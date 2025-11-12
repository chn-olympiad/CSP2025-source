#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll in(){
	ll x=1,k=0;
	char s=getchar();
	while(s<'0'||s>'9'){
		if(s=='-')x=-x;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		k=k*10+s-'0';
		s=getchar();
	}
	return k*x;
}
ll n,m,k;
struct ww{
	ll v,w,qyg;
	friend bool operator <(const ww &X,const ww &Y){
		return X.w>Y.w;
	}
};
priority_queue<ww>p;
struct www{
	ll v,w,sy,bh;
	
};
struct r{
	ll u,v,w;
}a[10001000];
vector<www>q[10010];
ll vis[10010];
ll dis[10010],ans,lll[10010],jl[2001000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in(),m=in(),k=in();
	for(int i=1;i<=m;i++){
		ll u,v,w;
		u=in(),v=in(),w=in();
		q[u].push_back({v,w,0,i});
		q[v].push_back({u,w,0,i});
		a[i]={u,v,w};
	}
	for(int i=1;i<=n;i++){
		vis[i]=0,dis[i]=LLONG_MAX;
	}
	if(k==0){
		dis[1]=0;
		p.push({1,0,0});
		while(!p.empty()){
			ww c=p.top();
			ll x=c.v,y=c.w;
			p.pop();
			
			if(!vis[x]){
				vis[x]=1;
				dis[x]=y;
				if(jl[c.qyg]==0)ans+=a[c.qyg].w,jl[c.qyg]=1;
				for(int i=0;i<q[x].size();i++){
					p.push({q[x][i].v,q[x][i].w+y,q[x][i].bh});
				}
			}
			
		}
		cout<<ans<<"\n";
	}
	else{
		ll bh=m+1;
		for(int i=1;i<=k;i++){
			int u;
			cin>>u;
			for(int j=1;j<=n;j++){
				lll[j]=in();
			}
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					q[j].push_back({k,lll[j]+lll[k],0,bh});
					q[k].push_back({j,lll[j]+lll[k],0,bh});
					a[bh]={j,k,lll[j]+lll[k]};
					bh++;
//					cout<<i<<" "<<j<<" "<<k<<" "<<bh<<"\n";
				}
			}
		}
		ans=0;
		p.push({1,0,0});
		while(!p.empty()){
			ww c=p.top();
			ll x=c.v,y=c.w;
			p.pop();
			if(!vis[x]){
//				cout<<x<<" "<<y<<" "<<c.qyg<<" \n";
				vis[x]=1;
				dis[x]=y;
				ans+=a[c.qyg].w;
				for(int i=0;i<q[x].size();i++){
					if(q[x][i].w+y<dis[q[x][i].v])p.push({q[x][i].v,q[x][i].w+y,q[x][i].bh});
				}
			}
//			cout<<x<<" "<<y<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
3 3 1
1 2 1000
2 3 1000
1 3 1
1 1 1000


*/
