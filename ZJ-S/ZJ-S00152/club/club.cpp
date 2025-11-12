#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=2e9+10;
int n;
int t;
int a[N][4];
int cnt[4];
int ans;
struct memb{
	int id;
	int nxtw,p;
	bool operator <(const memb& other)const{
		return p>other.p;
	}
};

struct member{
	int a[4];
	int id;
	int w[4];
	int p1,p2;
	void pt(int i){
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		if(a[1]>=a[2]&&a[2]>=a[3])w[1]=1,w[2]=2,w[3]=3;
		else if(a[1]>=a[3]&&a[3]>=a[2])w[1]=1,w[2]=3,w[3]=2;
		else if(a[2]>=a[1]&&a[1]>=a[3])w[1]=2,w[2]=1,w[3]=3;
		else if(a[2]>=a[3]&&a[3]>=a[1])w[1]=2,w[2]=3,w[3]=1;
		else if(a[3]>=a[2]&&a[2]>=a[1])w[1]=3,w[2]=2,w[3]=1;
		else w[1]=3,w[2]=1,w[3]=2;
		p1=a[w[1]]-a[w[2]];
		p2=a[w[2]]-a[w[3]];
		id=i;
	}
	memb cm(int now){
		if(now==w[1]){
			return {id,w[2],p1};
		}
		else return {id,w[3],p2};
	} 
}m[N];
priority_queue<memb>q[4];

void putin(int x,int cl){
	q[cl].push(m[x].cm(cl));
	int sz=q[cl].size();
	if(sz>n/2){
		memb mem=q[cl].top();
		q[cl].pop();
		int id=mem.id,nxtw=mem.nxtw,p=mem.p;
		ans-=p;
		if(nxtw==m[id].w[2]){
			q[nxtw].push({id,m[id].w[3],m[id].p2});
		}
		else if(nxtw==m[id].w[3]){
			q[nxtw].push({id,0,INF});
		}
	}
}

void solve(){
	while(q[1].size())q[1].pop();
	while(q[2].size())q[2].pop();
	while(q[3].size())q[3].pop();
	
	scanf("%d",&n);
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		m[i].pt(i);
	}
	ans=0;
	for(int i=1;i<=n;i++){
		ans+=m[i].a[m[i].w[1]];
		putin(i,m[i].w[1]);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}