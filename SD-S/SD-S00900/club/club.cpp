#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int T,n,a[N][5],len,c[5],now[N];
bool f[N],ok[N];
LL ans;
struct node {
	int id;
	int la;
	int now;
	int v;
};
bool operator <(node x,node y) {
	return x.v>y.v;
}
priority_queue<node> q[5];
struct Node {
	int id;
	int op;
	int v;
} d[N*3];
bool cmp(Node x,Node y) {
	if(x.v!=y.v) return x.v>y.v;
	else if(x.id!=y.id) return x.id<y.id;
	else return x.op<y.op;
}
int read(){
	int f=1;
	int t=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		t=(t<<3)+(t<<1)+(c^'0');
		c=getchar();
	}
	return t*f;
}
void solve() {
	n=read();
	len=0;
	ans=0;
	c[1]=c[2]=c[3]=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=3; j++) a[i][j]=read(),d[++len]= {i,j,a[i][j]};
	}
//	if(a[1][1]==6090){
//		return ;
//	}
	sort(d+1,d+1+len,cmp);
	for(int i=1; i<=len; i++) {
		if(f[d[i].id]) continue;
		if(c[d[i].op]<n/2) {
			f[d[i].id]=true;
			ans+=d[i].v;
			c[d[i].op]++;
			now[d[i].id]=d[i].op;
			for(int j=1; j<=3; j++) {
				if(j!=d[i].op) q[d[i].op].push({d[i].id,d[i].op,j,a[d[i].id][d[i].op]-a[d[i].id][j]});
			}
		} else {
			while(!q[d[i].op].empty()&&q[d[i].op].top().la!=now[q[d[i].op].top().id]) q[d[i].op].pop();
			if(q[d[i].op].empty())  continue;
			node t=q[d[i].op].top();
			int ma=0;
			for(int j=1;j<=3;j++){
				if(j!=d[i].op) ma=max(ma,a[d[i].id][j]);
			}
			if(t.v>=d[i].v-ma) {
				continue;
			} else {
				f[d[i].id]=true;
				c[t.la]--;
				now[t.id]=t.now;
				now[d[i].id]=d[i].op;
				c[t.now]++;
				c[d[i].op]++;
				ans-=a[t.id][t.la];
				ans+=a[t.id][t.now];
				ans+=d[i].v;
				for(int j=1; j<=3; j++) {
					if(j!=d[i].op) q[d[i].op].push({d[i].id,d[i].op,j,a[d[i].id][d[i].op]-a[d[i].id][j]});
				}
				for(int j=1; j<=3; j++) {
					if(j!=t.now) q[t.now].push({t.id,t.now,j,a[t.id][t.now]-a[t.id][j]});
				}
			}
		}
	}
	printf("%lld\n",ans);
	for(int i=1; i<=3; i++) while(!q[i].empty()) q[i].pop();
	for(int i=1; i<=n; i++) ok[i]=false,f[i]=false,a[i][1]=a[i][2]=a[i][3]=0,c[1]=c[2]=c[3]=0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--) solve();
	return 0;
}

