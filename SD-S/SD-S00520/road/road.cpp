#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cstring>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<queue>
#define ll long long
#define ull usdigned long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int K=15;
ll read(){
	ll x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*w;
}
void write(ll x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
ll n,m,k,u,v,w;
ll c[K],a[K][N];
struct node{
	ll from,son,nex,val;
	ll typ;
}edge[5000005],edge2[5000005];
ll head[N],cnt;
ll head2[N],cnt2;
void add(ll a,ll b,ll c){
	cnt++;
	edge[cnt].from=a;
	edge[cnt].son=b;
	edge[cnt].nex=head[a];
	edge[cnt].val=c;
	edge[cnt].typ=cnt;
	head[a]=cnt;
}
void add2(ll a,ll b,ll c){
//	cout<<a<<" "<<b<<" "<<c<<" yep!\n";
	cnt2++;
	edge2[cnt2].from=a;
	edge2[cnt2].son=b;
	edge2[cnt2].nex=head2[a];
	edge2[cnt2].val=c;
	edge2[cnt2].typ=cnt2;
	head2[a]=cnt2;
}
struct NODE{
	ll dis,id,typ;
	bool operator < (const NODE &kk)const{
		return kk.dis<dis;
	}
};
ll d[N],vis[N],ans,g[5000005];
struct Node{
	ll f1,f2;
}p[K];
void prim(){
	memset(d,0x3f,sizeof(d));
	priority_queue<NODE> pq;
	d[1]=0;
	pq.push((NODE){0,1,0});
	ll ned=0;
	while(!pq.empty()&&ned<=n-1){
		NODE now=pq.top();
		pq.pop();
//		cout<<now.id<<" "<<now.dis<<"\n";
		if(vis[now.id]==0){
			vis[now.id]=1;
			if(now.id>=1&&now.id<=n) ned++;
			ans+=now.dis;
			g[now.typ]++;
			for (ll i=head[now.id];i!=0;i=edge[i].nex){
				ll r=edge[i].son;
				if(d[r]>edge[i].val){
					d[r]=edge[i].val;
					pq.push((NODE){d[r],r,edge[i].typ});
				}
			}
		}
	}
}
void prim2(){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	priority_queue<NODE> pq;
	d[1]=0;
	pq.push((NODE){0,1,0});
	ll ned=0;
	while(!pq.empty()&&ned<=n-1){
		NODE now=pq.top();
		pq.pop();
//		cout<<now.id<<" "<<now.dis<<"\n";
		if(vis[now.id]==0){
			vis[now.id]=1;
			if(now.id>=1&&now.id<=n) ned++;
			ans+=now.dis;
			for (ll i=head2[now.id];i!=0;i=edge2[i].nex){
				ll r=edge2[i].son;
				if(d[r]>edge2[i].val){
					d[r]=edge2[i].val;
					pq.push((NODE){d[r],r,edge2[i].typ});
				}
			}
		}
	}
}
void cheak(){
	for (int i=1;i<=cnt2;i++){
		cout<<edge2[i].from<<" "<<edge2[i].son<<" "<<edge2[i].val<<"\n";
	}
}
int main(){
	file("road");
	n=read();m=read();k=read();
	for (ll i=1;i<=m;i++){
		u=read();v=read();w=read();
		add(u,v,w);
		add(v,u,w);
		add2(u,v,w);
		add2(v,u,w);
	} 
	for (ll i=1;i<=k;i++){
		c[i]=read();
		for (ll j=1;j<=n;j++){
			a[i][j]=read();
			add(i+n,j,a[i][j]);
			add(j,i+n,a[i][j]);
		}
		add(i+n,i+n+k,c[i]);
		p[i].f1=cnt;
		add(i+n+k,i+n,c[i]);
		p[i].f2=cnt;
	}
//	cheak();
	prim();
	for (ll i=1;i<=k;i++){
		if(g[p[i].f1]!=0||g[p[i].f2]!=0){
//			cout<<i<<"\n";
			for (ll j=1;j<=n;j++){
				add2(i+n,j,a[i][j]);
				add2(j,i+n,a[i][j]);
			}
			add2(i+n,i+n+k,c[i]);
			add2(i+n+k,i+n,c[i]);
		}
	}
//	cout<<cnt2<<"\n"; 
//	cheak();
	ans=0;
	prim2();
	cout<<ans<<"\n";
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
