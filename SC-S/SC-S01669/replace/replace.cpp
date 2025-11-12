#include<bits/stdc++.h>
#define ll long long
#define PLL pair<long long,long long>
#define PII pair<int,int>
using namespace std;
const ll P=1003,N=2e5+5,Le=5e6+5;
int n,q,l,r,tot,now,ans;
ll numa,numb,numc,numd,flc[N],clf[N],mul[Le];
string s,t;
map<PLL,int> mp;
inline int get(PLL k) {
	if(!mp.count(k)) return mp[k]=++tot;
	return mp[k];
}
vector<pair<PII,ll> > vec[N];
inline ll aska(int L,int R) {
	return flc[R]-flc[L-1]*mul[R-L+1];
}
inline ll askb(int L,int R) {
	return clf[R]-clf[L-1]*mul[R-L+1];
}
int A,B;
pair<PII,ll> tmp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	mul[0]=1;
	for(int i=1; i<Le; i++) mul[i]=mul[i-1]*P;
	for(int o=1; o<=n; o++) {
		l=200000000,r=0;
		cin>>s>>t;
		numa=numb=numc=numd=0;
		for(int i=0; i<s.size(); i++) {
			numa=numa*P+(ll)(s[i]-'a'+1);
			if(s[i]!=t[i]) {
				l=min(l,i);
				r=max(r,i);
			}
		}
		for(int i=l; i<=r; i++) {
			numc=numc*P+(ll)(s[i]-'a'+1);
			numd=numd*P+(ll)(t[i]-'a'+1);
		}
		now=get({numc,numd});
		vec[now].push_back({{l,s.size()-r-1},numa});
//		printf("%lld %lld %lld %lld %lld %lld\n",l,r,numa,numb,numc,numd);
	}
	while(q--) {
		ans=0;
		l=200000000,r=0;
		cin>>s>>t;
		if(s.size()!=t.size()) {
			cout<<"0\n";
			continue;
		}
		s="f"+s;
		t="f"+t;
		for(int i=1; i<s.size(); i++) {
			flc[i]=flc[i-1]*P+s[i]-'a'+1;
			clf[i]=clf[i-1]*P+t[i]-'a'+1;
			if(s[i]!=t[i]) {
				l=min(l,i);
				r=max(r,i);
			}
		}
		now=get({aska(l,r),askb(l,r)});
		for(int i=0; i<vec[now].size(); i++) {
			tmp=vec[now][i];
//			cout<<tmp.first.first<<" "<<tmp.first.second<<"\n";
			if(tmp.first.first>l-1 or tmp.first.second>s.size()-r-1) continue;
			if(aska(l-tmp.first.first,r+tmp.first.second)==tmp.second) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
