#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int N=2e5+10,M=5e6+10;
#define pb emplace_back
int n,q,len;
ll ans;
string s1[N],s2[N];
const ull pp=13331;
mt19937_64 rnd(19790101);
ull p[M],pri[30],ha1[M],ha2[M];
vector<int>v;
map<pair<ull,ull>,int>mp[3000];
#define mk(a,b) {a,b}
inline ull gethash(string s){
	ull val=0;
	for(char c:s)
	  val=val*pp+pri[c-'a'+1];
	return val;
}
inline ull getval1(int l,int r){
	if(l>r)return 0;
	return ha1[r]-ha1[l-1]*p[r-l+1];
}
inline ull getval2(int l,int r){
	if(l>r)return 0;
	return ha2[r]-ha2[l-1]*p[r-l+1];
}
inline void solve(int x){
	for(int i=1;i+v[x]-1<=len;++i){
	  if(s1[0][i-1]!=s2[0][i-1])break;
	  if(getval1(i+v[x],len)!=getval2(i+v[x],len))continue;
	  pair<ull,ull> p=mk(getval1(i,i+v[x]-1),getval2(i,i+v[x]-1));
	  if(mp[x].find(p)!=mp[x].end())
		ans+=mp[x][p];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<M;++i)p[i]=p[i-1]*pp;
	for(int i=0;i<29;++i)pri[i]=rnd();
	for(int i=1;i<=n;++i){
	  cin>>s1[i]>>s2[i];
	  v.pb(s1[i].size());
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;++i){
	  ull hash1=gethash(s1[i]),hash2=gethash(s2[i]);
	  int pos=lower_bound(v.begin(),v.end(),s1[i].size())-v.begin();
	  ++mp[pos][mk(hash1,hash2)];
	}
	int qwq=v.size();
	while(q--){
	  cin>>s1[0]>>s2[0];
	  len=s1[0].size();
	  s1[0]=' '+s1[0],s2[0]=' '+s2[0];
	  for(int i=1;i<=len;++i)ha1[i]=ha1[i-1]*pp+pri[s1[0][i]-'a'+1];
	  for(int i=1;i<=len;++i)ha2[i]=ha2[i-1]*pp+pri[s2[0][i]-'a'+1];
	  ans=0;
	  for(int j=0;j<qwq;++j){
	  	if(v[j]>len)break;
	  	solve(j);
	  }
	  cout<<ans<<"\n";
	}
//	cerr<<"Time: "<<clock()/1.0/CLOCKS_PER_SEC*1000.0<<" ms\n";
	return 0;
}