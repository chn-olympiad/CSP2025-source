#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=100005;

ll T,n,a[maxn][5],ansf;

struct rk{
	ll pos,val;
};

struct node{
	ll ans;
	rk a[4];
	ll c;
	bool operator <(const node &x)const{
		return c>x.c;
	}
}b[maxn];

priority_queue <node >q[4];

bool cmp(rk x,rk y){
	return x.val>=y.val;
}

void Init(){
	while(!q[2].empty()) q[2].pop();
	while(!q[1].empty()) q[1].pop();
	while(!q[3].empty()) q[3].pop();
	ansf=0;
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++){
		b[i].a[1].pos=1,b[i].a[2].pos=2,b[i].a[3].pos=3;
		b[i].a[1].val=a[i][1],b[i].a[2].val=a[i][2],b[i].a[3].val=a[i][3];
		sort(b[i].a+1,b[i].a+4,cmp);
	}
	for(int i=1;i<=n;i++){
		b[i].c=b[i].a[1].val-b[i].a[2].val;
		b[i].ans=b[i].a[1].val;
		q[b[i].a[1].pos].push(b[i]);
	}
}

void solve(){
	Init();
	while(1){
		if(q[1].size()>(n/2)){
			node x=q[1].top(); q[1].pop();
			x.a[1].val=-1;
			sort(x.a+1,x.a+4,cmp);
			x.ans=x.a[1].val;x.c=x.a[1].val-x.a[2].val;
			q[x.a[1].pos].push(x);
		}
		else if(q[2].size()>(n/2)){
			node x=q[2].top(); q[2].pop();
			x.a[1].val=-1;
			sort(x.a+1,x.a+4,cmp);
			x.ans=x.a[1].val;x.c=x.a[1].val-x.a[2].val;
			q[x.a[1].pos].push(x);
		}
		else if(q[3].size()>(n/2)){
			node x=q[3].top(); q[3].pop();
			x.a[1].val=-1;
			sort(x.a+1,x.a+4,cmp);
			x.ans=x.a[1].val;x.c=x.a[1].val-x.a[2].val;
			q[x.a[1].pos].push(x);
		}
		else break;
	}
	for(int i=1;i<=3;i++)
	while(!q[i].empty()){
		ansf+=q[i].top().ans;
		q[i].pop();
	}
	cout<<ansf<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--) solve();
}
