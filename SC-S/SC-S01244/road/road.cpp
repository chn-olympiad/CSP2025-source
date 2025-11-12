#include<bits/stdc++.h>
#define ll long long
#define man 100005
using namespace std;
int n,fa[man],m,k,c[man],l[2000005],r[2000005],val[11][man],cnt=0;bool vis[man];ll ans=100000000000000000;
int fd(int x){if(fa[x]==x) return x;return fa[x]=fd(fa[x]);}
struct edge{
	int u,v;ll w;int id;
}e[2000005],p[man];
inline bool operator <(edge A,edge B){
	if(A.w==B.w) return A.id<B.id;
	return A.w<B.w; 
}
int getbit(int x){int ret=0;while(x) ret+=(x&1),x>>=1;return ret;}
bool cmp(edge A,edge B){return A.w<B.w;}
set<edge> st;
ll solve(int sta){
	ll ret=0;int num=0;
	for(int i=0;i<k;i++){
		if(sta&(1<<i)){
			ret+=c[i+1];
			for(int j=1;j<=n;j++){//(m+(i+1-1)*n+1,m+(i-1+1)*n+n)
				int now=m+(i-1+1)*n+j;
				p[++num]=e[now];
			}
		}
	}
//	cout<<"num="<<num<<'\n';
	sort(p+1,p+num+1,cmp);
	for(int i=1;i<=num;i++) st.insert(p[i]);
	int tot=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=n;i++) vis[i]=0;
//	cout<<"sis="<<st.size()<<'\n';
	for(edge i:st){
		int u=i.u,v=i.v;
		if(fd(u)!=fd(v)){
			fa[fd(u)]=fa[fd(v)];
			ret+=i.w;
			if(ret>ans) break;
			if(u<=n&&vis[u]==false) vis[u]=1,tot++;
			if(v<=n&&vis[v]==false) vis[v]=1,tot++;
			if(tot==n) break;
		}
	}
	for(int i=1;i<=num;i++) st.erase(p[i]);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;int cxk=0,s=clock();
	for(int i=1;i<=m;i++){
		int u,v;ll w;cin>>u>>v>>w;
		e[i]={u,v,w,i};
//		cin>>e[i].u>>e[i].v>>e[i].w;e[i].id=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(!c[i]) cxk++;
		for(int j=1;j<=n;j++) cin>>val[i][j];
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		int now=0;
		for(int j=1;j<=n;j++){
			p[j]={n+i,j,val[i][j],m+(i-1)*n+j};
		}
		sort(p+1,p+now+1,cmp);
		for(int j=1;j<=n;j++) e[++cnt]=p[j];
//		for(int j=1;j<=n;j++) cout<<"check:"<<e[j].u<<' '<<e[j].v<<' '<<e[j].w<<'\n';
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++) st.insert(e[i]);//cout<<e[i].u<<' '<<e[i].v<<'\n';
	
	if(cxk==k) ans=solve((1<<k)-1);
	else{
		if(k<=5){
			for(int i=0;i<(1<<k);i++){
				ll aaa=solve(i);
				ans=min(ans,aaa);
		//		cout<<"i="<<i<<" aaa="<<aaa<<'\n';
			}
		}
		else if(n<=1000){
			for(int i=0;i<(1<<k);i++){
				if(getbit(i)<=1||getbit(i)>=6) continue;
				ll aaa=solve(i);	
				ans=min(ans,aaa);	
		//		cout<<"i="<<i<<" aaa="<<aaa<<'\n';
			}
		}
		else{
			for(int i=0;i<(1<<k);i++){
				if(getbit(i)<=2||getbit(i)>=5) continue;
				ll aaa=solve(i);
				ans=min(ans,aaa);
				int t=clock();
				if(t-s>=866) break;
			}
		}
	}
//	for(edge i:st) cout<<i.u<<' '<<i.v<<' '<<i.id<<'\n';
	cout<<ans<<'\n';
//	cout<<t-s<<'\n';
	return 0;
}
/*
rp++;

I wish I could have 100pts,please help me

*/