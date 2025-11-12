#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline int read(){
	int s=0,k=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=(s<<3)+(s<<1)+(c^48);
		c=getchar();
	}
	return s*k;
}

bool aaaa;
const int mod=19491001,Bc=120921,N=2e5+5;
int n,Q;
string s[N][2];
int sum=0;

namespace subtask1{
	ll fac[2005];
	map<pair<ll,ll>,int>mp;
	string a,b;
	
	struct HAS{
		ll pre[N];
		
		void init(string &s){
			pre[0]=0;
			for(int i=0;i<s.size();i++)
				pre[i+1]=(pre[i]*Bc+s[i]-'a'+1)%mod;
		}
		
		ll query(int l,int r){
			l++;r++;
			ll val=pre[r]-pre[l-1]*fac[r-l+1]%mod;
			if(val<0) val+=mod;
			return val;
		}
	}A,B;
	
	ll calc(string &s){
		ll ans=0;
		for(int i=0;i<s.size();i++){
			ans=(ans*Bc+s[i]-'a'+1)%mod;
		}
		return ans;
	}
	
	void solve(){
		fac[0]=1;
		for(int i=1;i<=2000;i++) fac[i]=fac[i-1]*Bc%mod;
		for(int i=1;i<=n;i++)
			mp[make_pair(calc(s[i][0]),calc(s[i][1]))]++;
		while(Q--){
			cin>>a>>b;
			A.init(a);B.init(b);
			if(a.size()!=b.size()){
				cout<<'0'<<'\n';
				continue;
			}
			int l=0,r=a.size()-1;
			while(a[l]==b[l]) l++;
			while(a[r]==b[r]) r--;
			int ans=0;
			for(int j=a.size()-1;j>=r;j--)
				for(int i=0;i<=l;i++) ans+=mp[make_pair(A.query(i,j),B.query(i,j))];
			cout<<ans<<'\n';
		}
	}
}

namespace subtask2{
	tuple<int,int,int> calc(string &s,string &t){
		int x=0,y=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='b'){
				x=i;
				break;
			}
		for(int i=0;i<t.size();i++)
			if(t[i]=='b'){
				y=i;
				break;
			}
		return make_tuple(min(x,y)+1,s.size()-max(x,y),y-x);
	}
	
	unordered_map<int,vector<pair<int,int> > >vec;
	int ans[N];
	struct que{
		int x,y,id;
	}qu[N];
	string ta,tb;
	unordered_map<int,vector<int> >que;
	
	const int M=5e6+5;
	int c[M];
	
	void add(int x,int v){
		while(x<M){
			c[x]+=v;
			x+=x&-x;
		}
	}
	
	int query(int x){
		int ans=0;
		while(x>0){
			ans+=c[x];
			x-=x&-x;
		}
		return ans;
	}
	
	void solve(){
		for(int i=1;i<=n;i++){
			int x,y,z;
			tie(x,y,z)=calc(s[i][0],s[i][1]);
			vec[z].emplace_back(x,y);
		}
		for(int i=1;i<=Q;i++){
			cin>>ta>>tb;
			if(ta.size()!=tb.size()) continue;
			int x,y,z;
			tie(x,y,z)=calc(ta,tb);
			qu[i]={x,y,i};
			que[z].push_back(i);
		}
		for(auto o:que){
			vector<pair<int,int> >&VEC=vec[o.first];
			vector<int>&QUE=que[o.first];
			sort(VEC.begin(),VEC.end());
			sort(QUE.begin(),QUE.end(),[&](int x,int y){
				return qu[x].x<qu[y].x;
			});
			int i=0;
			for(int x:QUE){
				int l=qu[x].x,r=qu[x].y,id=qu[x].id;
				while(i<VEC.size()&&VEC[i].first<=l){
					add(VEC[i].second,1);
					i++;
				}
				ans[id]=query(r);
			}
			for(int j=0;j<i;j++) add(VEC[j].second,-1);
		}
		for(int i=1;i<=Q;i++) cout<<ans[i]<<'\n';
	}
}
bool bbbb;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=n;i++) sum=sum+s[i][0].size()+s[i][1].size();
	if(sum<=2000) subtask1::solve();
	else subtask2::solve();
	return 0;
}

