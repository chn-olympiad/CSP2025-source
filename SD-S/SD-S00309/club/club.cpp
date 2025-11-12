#include <bits/stdc++.h>
#define pir pair<int,int>
#define fi first
#define se second
using namespace std;
const int maxn=100010;
struct stu {
	int v1,v2,v3;
}t[maxn];
priority_queue<pir> q1,q2,q3;
int vis[maxn],sum[5];
int n,ans;
void solve1() {
	while(q1.size()&&sum[1]<n/2) {
		int id=q1.top().se; q1.pop();
		if(vis[id]==1) continue;
		ans+=t[id].v1;
		t[id].v1=0;
		vis[id]=1;
		sum[1]++;
	}
	while(q1.size()) {
		int id=q1.top().se; q1.pop();
		if(vis[id]==1) continue;
		t[id].v1=0;
		if(t[id].v2==0&&t[id].v3==0) vis[id]=1;
		if(t[id].v3>t[id].v2) {
			pir k;
			k.fi=t[id].v3-t[id].v2;
			k.se=id;
			q3.push(k);
		}
		else {
			pir k;
			k.fi=t[id].v2-t[id].v3;
			k.se=id;
			q2.push(k);
		}
	}
}
void solve2() {
	while(q2.size()&&sum[2]<n/2) {
		int id=q2.top().se; q2.pop();
		if(vis[id]==1) continue;
		ans+=t[id].v2;
		t[id].v2=0;
		vis[id]=1;
		sum[2]++;
	}
	while(q2.size()) {
		int id=q2.top().se; q2.pop();
		if(vis[id]==1) continue;
		t[id].v2=0;
		if(t[id].v1==0&&t[id].v3==0) vis[id]=1;
		if(t[id].v1>t[id].v3) {
			pir k;
			k.fi=t[id].v1-t[id].v3;
			k.se=id;
			q1.push(k);
		}
		else {
			pir k;
			k.fi=t[id].v3-t[id].v1;
			k.se=id;
			q3.push(k);
		}
	}
}
void solve3() {
	while(q3.size()&&sum[3]<n/2) {
		int id=q3.top().se; q3.pop();
		if(vis[id]==1) continue;
		ans+=t[id].v3;
		t[id].v3=0;
		vis[id]=1;
		sum[3]++;
	}
	while(q3.size()) {
		int id=q3.top().se; q3.pop();
		if(vis[id]==1) continue;
		t[id].v3=0;
		if(t[id].v1==0&&t[id].v2==0) vis[id]=1;
		if(t[id].v1>t[id].v2) {
			pir k;
			k.fi=t[id].v1-t[id].v2;
			k.se=id;
			q1.push(k);
		}
		else {
			pir k;
			k.fi=t[id].v2-t[id].v1;
			k.se=id;
			q2.push(k);
		}
	}
}
void init() {
	ans=0;
	for(int i=1;i<=n;i++)
		t[i].v1=t[i].v2=t[i].v3=vis[i]=0;
	while(q1.size()) q1.pop();
	while(q2.size()) q2.pop();
	while(q3.size()) q3.pop();
	sum[1]=sum[2]=sum[3]=0;
}
void solve() {
	init();
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>t[i].v1>>t[i].v2>>t[i].v3;
		int c=min(t[i].v1,min(t[i].v2,t[i].v3));
		t[i].v1-=c,t[i].v2-=c,t[i].v3-=c,ans+=c;
		if(t[i].v3==0) {
			if(t[i].v1>t[i].v2) {
				pir k;
				k.fi=t[i].v1-t[i].v2;
				k.se=i;
				q1.push(k);
			}
			else {
				pir k;
				k.fi=t[i].v2-t[i].v1;
				k.se=i;
				q2.push(k);
			}
		}
		if(t[i].v2==0) {
			if(t[i].v1>t[i].v3) {
				pir k;
				k.fi=t[i].v1-t[i].v3;
				k.se=i;
				q1.push(k);
			}
			else {
				pir k;
				k.fi=t[i].v3-t[i].v1;
				k.se=i;
				q3.push(k);
			}
		}
		if(t[i].v1==0) {
			if(t[i].v3>t[i].v2) {
				pir k;
				k.fi=t[i].v3-t[i].v2;
				k.se=i;
				q3.push(k);
			}
			else {
				pir k;
				k.fi=t[i].v2-t[i].v3;
				k.se=i;
				q2.push(k);
			}
		}
		if(t[i].v1==0&&t[i].v2==0&&t[i].v3==0) vis[i]=1;
	}
	if(q1.size()>=q2.size()&&q1.size()>=q3.size()) {
		solve1();
		if(q2.size()>=q3.size()) {
			solve2();
			solve3(); 
		}
		else{
			solve3();
			solve2();
		}
	}
	else if(q2.size()>=q1.size()&&q2.size()>=q3.size()) {
		solve2();
		if(q1.size()>=q3.size()) {
			solve1();
			solve3(); 
		}
		else{
			solve3();
			solve1();
		}
	}
	else if(q3.size()>=q1.size()&&q3.size()>=q2.size()) {
		solve3();
		if(q1.size()>=q2.size()) {
			solve1();
			solve2(); 
		}
		else{
			solve2();
			solve1();
		}
	}
	cout<<ans<<"\n";
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
