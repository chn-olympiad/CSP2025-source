#include<bits/stdc++.h>
using namespace std;

ifstream fin("replace.in");
ofstream fout("replace.out");
#define cin fin
#define cout fout

const int N=2e5+5,M=5e6+5;

int n,q,p1[N],p2[N];
string s[N][2];

int tr[M][26],fail[M],tot=1;
vector<int> E[M];

int ins(const string&s){
	int p=1;
	for(char c:s){
		int cc=c-'a';
		if(!tr[p][cc]) tr[p][cc]=++tot;
		p=tr[p][cc];
	}
	return p;
}

int dfn[M],pdf,siz[M];
void dfs(int u){
	dfn[u]=++pdf;
	siz[u]=1;
	for(int v:E[u]) dfs(v),siz[u]+=siz[v];
	E[u].clear();
	E[u].shrink_to_fit();
}

void build(){
	queue<int> q;
	for(int i=0;i<26;++i){
		if(tr[1][i]) q.push(tr[1][i]),fail[tr[1][i]]=1;
		else tr[1][i]=1;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;++i){
			if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
			else tr[u][i]=tr[fail[u]][i];
		}
		E[fail[u]].push_back(u);
	}
	dfs(1);
}

struct Obj{
	int a,b,c,id,op;
};
vector<Obj> obj;

struct Bit{
#define lbt(x) (x&(-x))
	int tr[N];
	vector<int> d;
	void Add(int x,int y){
		for(;x<=tot;x+=lbt(x)) tr[x]+=y;
	}
	void add(int x,int y){
		d.push_back(y/abs(y)*x);
		Add(x,y);
	}
	int qry(int x){
		int res=0;
		for(;x;x-=lbt(x)) res+=tr[x];
		return res;
	} 
	void undo(int x){ 
		while(d.size()>x){
			int p=d.back();
			Add(abs(p),-p/abs(p));
			d.pop_back();
		}
	}
} bit;

int ans[N];

void cdq(int l,int r){
//	cerr<<l<<" "<<r<<"\n";
	if(l==r) return;
	int mid=(l+r)>>1;
	cdq(l,mid),cdq(mid+1,r);
	int i=l,j=mid+1;
	int t=bit.d.size();
	for(;j<=r;++j){
		while(i<=mid&&obj[i].b<=obj[j].b){
			if(obj[i].id<0){
				bit.add(obj[i].c,obj[i].op);
				bit.add(-obj[i].id,-obj[i].op);
			}
			++i;
		} 
		if(obj[j].id>0){
			ans[obj[j].id]+=bit.qry(obj[j].c);
		}
	}
	bit.undo(t);
	sort(obj.begin()+l,obj.begin()+r+1,[&](const Obj&a,const Obj&b){
		return a.b==b.b?a.id<b.id:a.b<b.b;	
	});
}

signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		p1[i]=ins(s[i][0]);
		p2[i]=ins(s[i][1]);
	}
	build();
	obj.reserve(2*n+q);
	for(int i=1;i<=n;++i){
		int x=s[i][0].size();
		obj.push_back({x,dfn[p1[i]],dfn[p2[i]],dfn[p2[i]]+siz[p2[i]],dfn[p1[i]]+siz[p1[i]]});
//		obj.push_back({x,dfn[p1[i]]+siz[p1[i]],dfn[p2[i]],-dfn[p2[i]]-siz[p2[i]],-1});
	}
	for(int i=1;i<=q;++i){
		string t0,t1; cin>>t0>>t1;
		int q1=1,q2=1,l=0,r=t0.size()-1;
		while(l<t0.size()&&t0[l]==t1[l])
			++l;
		while(r>=0&&t0[r]==t1[r])
			--r;
		for(int j=0;j<t0.size();++j){
			q1=tr[q1][t0[j]-'a'];
			q2=tr[q2][t1[j]-'a'];
			obj.push_back({max(0,r-l+1),dfn[q1],dfn[q2],i,0});
		}
	}
	sort(obj.begin(),obj.end(),[&](const Obj&a,const Obj&b){
		return a.a==b.a?a.id<b.id:a.a>b.a;	
	});
//	for(auto[a,b,c,d,e]:obj){
//		cerr<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
//	}
	if(obj.size()<=10000){
		for(int i=0;i<obj.size();++i){
			if(!obj[i].op){
				for(int j=0;j<obj.size();++j){
					if(obj[j].op&&obj[j].a>=obj[i].a&&obj[j].b<=obj[i].b&&obj[i].b<obj[j].op&&obj[j].c<=obj[i].c&&obj[i].c<obj[j].id)
						++ans[obj[i].id];
				}	
			}
		}	
	}
	else cdq(0,obj.size()-1);
	
	for(int i=1;i<=q;++i) cout<<ans[i]<<"\n";
	return 0;
}

struct Code{
	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }
	~Code(){ cout.flush(),fin.close(),fout.close(); }
} wtl;