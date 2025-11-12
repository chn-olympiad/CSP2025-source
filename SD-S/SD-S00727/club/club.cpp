#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define FOR(i,l,r) for(int i=(l);i<=(r);++i)
#define ROF(i,r,l) for(int i=(r);i>=(l);--i)
#define eb emplace_back
#define fr first
#define se second
#define mkp make_pair
using namespace std;
bool __ST;
void Document() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int read() {
	int s=0,t=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') t=-1;ch=getchar();}
	while(isdigit(ch)) {s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return s*t;
}
const int N=1e5+10;
int n;
pair<int,int> tmp[5];
int cnt[5];
priority_queue<pair<int,int> >q[5];
void solve() { 
	FOR(o,1,3) while(q[o].size()) q[o].pop();
	FOR(i,1,3) cnt[i]=0;
	cin>>n;LL ans=0;
	FOR(i,1,n) {
		FOR(j,1,3) {
			int x=read();
			tmp[j]={x,j};
		}
		sort(tmp+1,tmp+4);
		reverse(tmp+1,tmp+4);
		++cnt[tmp[1].se];ans+=tmp[1].fr;
		q[tmp[1].se].push(mkp(tmp[2].fr-tmp[1].fr,i));
	}
	FOR(o,1,3) {
		while(cnt[o]>n/2) {
			auto p=q[o].top();q[o].pop();
			--cnt[o];ans+=p.fr;
		}
	}
	cout<<ans<<"\n";
}
bool __ED;
int main() { cerr<<(&__ED-&__ST)/1048576.<<"\n";
	Document();
	int _=read();
	while(_--) solve();
	return 0;
}
