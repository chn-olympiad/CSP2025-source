#include <bits/stdc++.h>
using namespace std;
const int N=100005;
using ll=long long;
using pii=array<int,2>;
using piii=array<int,3>;
using piiii=array<int,4>;
int read() {
	int res=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return res*f;
}
int T;
int n,ans;
int cnt[3],col[N],t[N],bel[N<<4],tt;
struct node {
	int val[3];
} p[N];
bool check(int i,int j) {
	return p[i].val[j]>=p[i].val[(j+1)%3]&&p[i].val[j]>=p[i].val[(j+2)%3];
}
void solve() {
	ans=0;
	priority_queue<piii> q[3];
	for(int i=1; i<=tt; i++)bel[i]=0;
	for(int i=1; i<=n; i++)col[i]=t[i]=0;
	tt=0;
	memset(cnt,0,sizeof cnt);
	n=read();
	for(int i=1; i<=n; i++) {
		for(int j=0; j<3; j++) {
			p[i].val[j]=read();
		}
	}
//	sort(p+1,p+n+1,[](const node &a,const node &b) {
//		return a.val[0]<b.val[0];
//	});
	for(int i=1; i<=n; i++) {
//		cerr<<i<<' '<<cnt[2]<<'\n';
		vector<piiii> vec;
		vec.reserve(6);
		for(int j=0; j<3; j++) {
			if(cnt[j]<n/2) {
				vec.push_back({p[i].val[j],j,j,0});
			}else {
				while(!q[j].empty()&&q[j].top()[1]!=t[bel[q[j].top()[1]]])q[j].pop();
				if(q[j].size())vec.push_back({p[i].val[j]+q[j].top()[0],j,q[j].top()[2],q[j].top()[1]});
			}
//			int id1=(j+1)%3;
//			if(cnt[id1]<n/2) {
//				while(!q[id1].empty()&&q[id1].top()[1]!=t[bel[q[id1].top()[1]]])q[id1].pop();
//				if(q[id1].size())vec.push_back({p[i].val[j]+q[id1].top()[0],j,id1,q[id1].top()[1]});
//			}
//			int id2=(j+2)%3;
//			if(cnt[id2]<n/2) {
//				while(!q[id2].empty()&&q[id2].top()[1]!=t[bel[q[id2].top()[1]]])q[id2].pop();
//				if(q[id2].size())vec.push_back({p[i].val[j]+q[id2].top()[0],j,id2,q[id2].top()[1]});
//			}
		}
//		sort(vec.begin(),vec.end());
//		;
		auto now=*max_element(vec.begin(),vec.end());
		col[i]=now[1];
		ans+=now[0];
		cnt[now[2]]++;
		tt++;
		bel[tt]=i;
		t[i]=tt;
		q[now[1]].push({p[i].val[(now[1]+1)%3]-p[i].val[now[1]],tt,(now[1]+1)%3});
		q[now[1]].push({p[i].val[(now[1]+2)%3]-p[i].val[now[1]],tt,(now[1]+2)%3});
		if(now[1]!=now[2]) {
			tt++;
			int j=bel[now[3]];
			bel[tt]=j;
			t[j]=tt;
			q[now[2]].push({p[j].val[(now[2]+1)%3]-p[j].val[now[2]],tt,(now[2]+1)%3});
			q[now[2]].push({p[j].val[(now[2]+2)%3]-p[j].val[now[2]],tt,(now[2]+2)%3});
		}
	}
	assert(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2);
	cout<<ans<<'\n';
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)solve();
}
/*
1
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
*/