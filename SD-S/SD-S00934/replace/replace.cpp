#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define mod1 1000000007
#define mod2 1000000009
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
const int N=2e5+5,M=5e6+5,b1=131,b2=1331;
bool ST;
ll p1[M],p2[M];
int n,q;
struct str{
	string s;int n;
	vector<ll>h1,h2;
	void init(){
		n=s.size();s=' '+s;
		h1.resize(n+1);h2.resize(n+1);
		for(int i=1;i<=n;i++)
			h1[i]=(h1[i-1]*b1+s[i])%mod1,h2[i]=(h2[i-1]*b2+s[i])%mod2;
	}
	pll query(int l,int r){
		return {(h1[r]-p1[r-l+1]*h1[l-1]%mod1+mod1)%mod1,(h2[r]-p2[r-l+1]*h2[l-1]%mod2+mod2)%mod2};
	}
}s1[N],s2[N];
pll x1[N],x2[N];
//inline bool equal(pll a1,pll a2,pll b1,pll b2){
//	return a1.first==a2.first&&a1.second==a2.second&&b1.first==a2.first&&a1.second==a2.second;
//} baka
//inline bool check(string s,int n){
//	int a=0,b=0;
//	for(int i=1;i<=n;i++)
//		if(s[i]=='a')a++;
//		else if(s[i]=='b')b++;
//	return b==1&&a+b==n;
//}
//struct BIT{
//	int t[M];
//	BIT(){memset(t,0,sizeof(t));}
//	inline void update(int i,int x){for(i++;i<M;i+=i&-i)t[i]+=x;}
//	inline void erase(int i){for(i++;t[i]&&i<M;i+=i&-i)t[i]=0;}
//	inline int query(int i){int ret=0;for(i++;i;i-=i&-i)ret+=t[i];return ret;}
//}bit;
//struct node{int l,r,op,id;};
//vector<node>v1[M],v2[M];int ans[N];
//void solve(vector<node>s){
//	sort(s.begin(),s.end(),[&](node x,node y){
//		return x.l==y.l?x.op<y.op:x.l>y.l;
//	});
//	int n=s.size();//cerr<<n<<endl;
////	for(int i=0;i<n;i++){
////		cout<<s[i].l<<' '<<s[i].r<<' '<<s[i].op<<' '<<s[i].id<<endl;
////	}
//	for(int i=0;i<n;i++)
//		if(s[i].op==1)bit.update(s[i].r,1);
//		else {
//			ans[s[i].id]+=bit.query(M-3)-bit.query(s[i].r-1); 
////			cerr<<"q"<<s[i].r<<' '<<bit.query(s[i].r)<<endl;
//		}
//	for(int i=0;i<n;i++)if(s[i].op==1)bit.erase(s[i].r);
//}
//void solve_B(){
//	for(int i=1;i<=n;i++){
//		int b1=-1,b2=-1,m=s1[i].n;
//		for(int j=1;j<=m;j++)
//			if(s1[i].s[j]=='b')b1=j;
//		for(int j=1;j<=m;j++)
//			if(s2[i].s[j]=='b')b2=j;
////		cerr<<b1<<' '<<b2<<endl;
////		if(b1==-1||b2==-1||b1-b2+1>M-1||b2-b1+1>M)cerr<<"!#!#!"<<endl;
//		if(b1>b2)v1[b1-b2+1].push_back({b1-1,m-b2,1,i});
//		else if(b1<b2)v2[b2-b1+1].push_back({b2-1,m-b1,1,i});
//	}
//	for(int i=1;i<=q;i++){
//		str t1,t2;int m;
//		cin>>t1.s>>t2.s;m=t1.s.size();
//		if(t1.s.size()!=t2.s.size()){
//			cout<<0<<'\n';
//			continue;
//		}
//		t1.init();t2.init();
//		int l=1,r=m;
//		while(t1.s[l]==t2.s[l])l++;
//		while(t1.s[r]==t2.s[r])r--;
//		if(t1.s[l]=='b')v2[r-l+1].push_back({l-1,m-r,2,i});
//		else v1[r-l+1].push_back({l-1,m-r,2,i});
//	}
//	for(int i=1;i<M;i++)if(v1[i].size())solve(v1[i]);
//	for(int i=1;i<M;i++)if(v2[i].size())solve(v2[i]);
//	for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
//}
//¼Ä£¡ 
bool ED;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cerr<<(&ED-&ST)/1024.0/1024<<endl;
	for(int i=p1[0]=p2[0]=1;i<N;i++)p1[i]=p1[i-1]*b1%mod1,p2[i]=p2[i-1]*b2%mod2;
	cin>>n>>q;//bool fl=1;
	for(int i=1;i<=n;i++){
		cin>>s1[i].s>>s2[i].s;
		s1[i].init(),s2[i].init();
		x1[i]=s1[i].query(1,s1[i].n),x2[i]=s2[i].query(1,s2[i].n);
//		if(fl)fl&=check(s1[i].s,s1[i].n);
//		if(fl)fl&=check(s2[i].s,s2[i].n);
	}
//	cerr<<fl<<endl;
//	if(fl)return solve_B(),0;
	while(q--){
		str t1,t2;int m;
		cin>>t1.s>>t2.s;m=t1.s.size();
		if(t1.s.size()!=t2.s.size()){
			cout<<0<<'\n';
			continue;
		}
		t1.init();t2.init();
		int l=1,r=m;
		while(t1.s[l]==t2.s[l])l++;
		while(t1.s[r]==t2.s[r])r--;
		int ans=0;
		for(int i=1;i<=n;i++){
			int ln=s1[i].n,R=min(m,l+ln-1),L=R-ln+1;
			for(;R>=r&&L>=1;L--,R--){
				pll f1=t1.query(L,R),f2=t2.query(L,R);
				if(x1[i]==f1&&x2[i]==f2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3 2
baa aba
aba aab
aba baa
abaa aaba
abaa baaa

*/

