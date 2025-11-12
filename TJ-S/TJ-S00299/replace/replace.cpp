#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define RLL register LL
#define PLL pair<LL,LL>
#define id_a(x) ((x-1)<<1)
#define id_b(x) (((x-1)<<1)|1)
const LL N=2e5+10,M=2e6+10;
vector<LL> ne[N<<1];
string a[N],b[N];
LL n,q;

inline LL sz(const string s){
	return (LL)s.size();
}

inline void work(string s,LL id){
	for(RLL i=0;i<sz(s);++i){
		ne[id].push_back(1);
	}
	ne[id][0]=-1;
	for(RLL i=1;i<sz(s);++i){
		ne[id][i]=ne[id][i-1];
		while(ne[id][i]!=-1 && s[ne[id][i]]!=s[i]){
			ne[id][i]=ne[id][ne[id][i]];
		}
		++ne[id][i];
	}
	return;
}

inline LL query(string s,string t,LL id){
	LL ans=0;
	queue<LL> q;
	for(RLL i=0,j=0;i<sz(s);++i){
		if(j==sz(a[id])-1){
			q.push((LL)i);
			j=ne[id_a(id)][j];
		}
		while(j!=-1 && s[i]!=a[id][j]){
			j=ne[id_a(id)][j];
		}
		++j;
	}
	for(RLL i=0,j=0;q.size() && i<sz(t);++i){
		if(q.front()<i){
			q.pop();
		}
		if(j==sz(b[id])-1){
			if(q.front()==i){
				++ans;
				q.pop();
			}
			j=ne[id_b(id)][j];
		}
		while(j!=-1 && t[i]!=b[id][j]){
			j=ne[id_b(id)][j];
		}
		++j;
	}
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(RLL i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		work(a[i],id_a(i));
		work(b[i],id_b(i));
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		LL l,r;
		for(RLL i=0;i<sz(s);++i){
			if(s[i]!=t[i]){
				l=i;
				break;
			}
		}
		for(RLL i=sz(s);i--;){
			if(s[i]!=t[i]){
				r=i;
				break;
			}
		}
		LL ans=0;
		for(RLL i=1;i<=n;++i){
			if(sz(a[i])>=r-l+1){
				ans+=query(s.substr(max(0ll,r+1-sz(a[i])),min(r-l+sz(a[i]),sz(s)-(r+1-sz(a[i])+1))),t.substr(max(0ll,r+1-sz(a[i])),min(r-l+sz(a[i]),sz(s)-(r+1-sz(a[i])+1))),i);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
