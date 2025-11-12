#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ull unsigned long long 
struct node{
	string a,b,c;
	node(){
		a="",b="",c="";
	}
};
const ull base=13331;
inline node get(string a,string b){
	int wz1;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			wz1=i;
			break;
		}
	}
	int wz2;
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]!=b[i]) {
		wz2=i;break;}
	}
	node res;
	for(int i=wz1;i<=wz2;i++) res.a+=a[i];//,res.a+=b[i];
	for(int i=wz1;i<=wz2;i++) res.a+=b[i];
	for(int i=0;i<wz1;i++) res.b+=a[i];
	for(int i=wz2+1;i<a.size();i++) res.c+=a[i];
	reverse(res.b.begin(),res.b.end());
	return res;
}
int n,q;
int cnt;
const int nn=2e5+5;
node x[nn],o[nn];
int res[nn];
inline ull hsh(string s){
	ull nw=0;
	for(int i=0;i<s.size();i++){
		nw=nw*base;
		nw=nw+(s[i]-'a'+1);
	}
	return nw;
}
unordered_map<ull,int> d;
vector<int> upd[nn],qry[nn];
#define pb push_back
#define pii pair<int,int>
const int mm=4e6+5;
int mx;
struct BIT{
	int c[mm];
	inline int lb(int x){
		return x&(-x);
	}
	inline void add(int x,int z){
		for(int i=x;i<=mx;i+=lb(i)) c[i]+=z;
	}
	inline int query(int x){
		int res=0;
		for(int i=x;i>=1;i-=lb(i)) res+=c[i];
		return res;
	}
	inline void cl(){
		for(int i=1;i<=mx;i++) c[i]=0; 
	}
}tr;
#define fi first
#define se second
struct trie{
	unordered_map<int,int> son[mm];
	int dfsl[mm],dfsr[mm],tm=1,js;
	vector<pii> mdf[mm];
	vector<pii> qry[mm];
	inline void ins(string s){
		int u=1;
		for(char c:s){
			int to=c-'a'+1;
			if(!son[u][to]) son[u][to]=++tm;
			u=son[u][to];
		}
	}
	inline void cl(){
		for(int i=1;i<=tm;i++) son[i].clear(),mdf[i].clear(),qry[i].clear();
		tm=1,js=0;
	}
	inline int getid(string s){
		int u=1;
		for(char c:s){
			int to=c-'a'+1;
			u=son[u][to];
		}
		return u;
	}
	inline void dfs(int x){
		dfsl[x]=++js;
		for(int i=1;i<=26;i++){
			if(son[x][i]) dfs(son[x][i]);
		}
		dfsr[x]=js;
	}
	inline void dfsc(int x){
		for(pii mzh:mdf[x]) tr.add(mzh.fi,1),tr.add(mzh.se+1,-1);
		for(pii mzh:qry[x]){
			res[mzh.se]=tr.query(mzh.fi);
		}
		for(int i=1;i<=26;i++){
			if(son[x][i]) dfsc(son[x][i]);
		}
		for(pii mzh:mdf[x]) tr.add(mzh.fi,-1),tr.add(mzh.se+1,1);
	}
}ds[2];
inline void solve(int id){
	ds[0].cl(),ds[1].cl();
	for(int i:upd[id]) ds[0].ins(x[i].b),ds[1].ins(x[i].c);//,cout<<x[i].a<<" ";
//	cout<<endl;
	for(int i:qry[id]) ds[0].ins(o[i].b),ds[1].ins(o[i].c);//,cout<<o[i].a<<' ';
//	cout<<endl<<endl<<endl;
	ds[1].dfs(1);
	for(int i:upd[id]){
		int id1=ds[0].getid(x[i].b),id2=ds[1].getid(x[i].c);
		ds[0].mdf[id1].pb(mp(ds[1].dfsl[id2],ds[1].dfsr[id2]));
	}
	mx=ds[1].js;
	tr.cl();
	for(int i:qry[id]){
		int id1=ds[0].getid(o[i].b),id2=ds[1].getid(o[i].c);
		ds[0].qry[id1].pb(mp(ds[1].dfsl[id2],i));
	}
	ds[0].dfsc(1);
}
#define endl '\n'
int tmm;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		assert(a.size()),assert(b.size());
		if(a==b) continue;
		cnt++;
		x[cnt]=get(a,b);
		ull val=hsh(x[cnt].a);
		if(!d[val]) d[val]=(++tmm);
		int sd=d[val];
		upd[sd].pb(cnt);
//		cout<<val<<" "<<x[cnt].a<<endl;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		o[i]=get(a,b);
		ull val=hsh(o[i].a);
		if(!d[val]) continue;
		int sd=d[val];
		qry[sd].pb(i);
//		cout<<o[i].a<<" ))) "<<o[i].b<<" "<<o[i].c<<" "<<val<<endl;
	}
	for(int i=1;i<=tmm;i++) solve(i);
	for(int i=1;i<=q;i++) cout<<res[i]<<endl;
	return 0;
}

