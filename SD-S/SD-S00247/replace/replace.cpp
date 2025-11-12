#include<bits/stdc++.h>
//#define int long long
#define fi first
#define se second
#define pii std::pair<int,int>
#define vint std::vector<int>
#define vpair std::vector<pii>
#define all(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,##__VA_ARGS__)

template<typename T>
void read(T &x){
	x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=x*10+(int)(c-'0'),c=getchar();
	x*=f;
}

std::stack<char>st;
template<typename T>
void print(T x){
	if(x==0) putchar('0');
	if(x<0) putchar('-'),x=-x;
	while(x) st.push((char)('0'+x%10)),x/=10;
	while(st.size()) putchar(st.top()),st.pop();
}

template<typename T>
void printsp(T x){
	print(x),putchar(' ');
}

template<typename T>
void println(T x){
	print(x),putchar('\n');
}

template<typename T,typename I>
bool chkmax(T &a,I b){
	if(a<b) return a=b,1;
	return 0;
}

template<typename T,typename I>
bool chkmin(T &a,I b){
	if(a>b) return a=b,1;
	return 0;
}

template<typename T,typename I>
void addedge(std::vector<T>*vec,I u,I v){
	vec[u].push_back(v);
}

template<typename T,typename I,typename K>
void addedge(std::vector<T>*vec,I u,I v,K w){
	vec[u].push_back({v,w});
}

template<typename T,typename I>
void addd(std::vector<T>*vec,I u,I v){
	addedge(vec,u,v),addedge(vec,v,u);
}

template<typename T,typename I,typename K>
void addd(std::vector<T>*vec,I u,I v,K w){
	addedge(vec,u,v,w),addedge(vec,v,u,w);
}

bool Mbe;

const int inf=1e9,MOD1=998244353,MOD2=1e9+7;

const int maxn=2e5+10,maxm=5e6+10,B=5e4;

int ans[maxn],n,q,del[maxm][26],son[maxm][26],fail[maxm],c[maxn],pos0[maxn],pos1[maxn],rt0,rt1,tot,dfn[maxm],sz[maxm],dfncnt,bel[maxm],bl[110],br[110],lz[110],bcnt=0,tim;

int no[maxm];

vint a[maxm];

pii w[maxn];

struct info{
	int x,y,id;
};

std::vector<info>Q[maxm];

vint upd[maxm];

std::set<int>mst;

vpair updz[maxm],updf[maxm],qry[maxm];

std::string s1,s2,t1,t2;

struct BIT{
	int s[B+10],ti[B+10];
	int lowbit(int x){
		return x&(-x);
	}
	void upd(int x,int y){
		for(;x<=B;x+=lowbit(x)){
			if(ti[x]!=tim) ti[x]=tim,s[x]=0;
			s[x]+=y;
		}
	}
	int query(int pos){
		int res=0;
		while(pos){
			if(ti[pos]!=tim) ti[pos]=tim,s[pos]=0;
			res+=s[pos],pos-=lowbit(pos);
		}
		return res;
	}
}ds[110];

void ins1(int id){
	int now=rt1;
	for(char i:s2){
		int x=(i-'a');
		if(!son[now][x]) son[now][x]=++tot;
		now=son[now][x];
	}
	pos1[id]=now;
}

void ins0(int id){
	int now=rt0;
	for(char i:s1){
		int x=(i-'a');
		if(!son[now][x]) son[now][x]=++tot;
		now=son[now][x];
	}
	pos0[id]=now;
}

void build1(){
	std::queue<int>q;
	fail[rt1]=rt1;
	for(int i=0;i<26;i++) del[rt1][i]=rt1;
	for(int i=0;i<26;i++) if(son[rt1][i]) del[rt1][i]=son[rt1][i],fail[son[rt1][i]]=rt1,q.push(son[rt1][i]);
	while(q.size()){
		int x=q.front();
		q.pop();
		a[fail[x]].push_back(x);
		for(int i=0;i<26;i++)
			if(son[x][i]) del[x][i]=son[x][i],fail[son[x][i]]=del[fail[x]][i],q.push(son[x][i]);
			else del[x][i]=del[fail[x]][i];
	} 
}

void build0(){
	std::queue<int>q;
	for(int i=0;i<26;i++) if(son[rt0][i]) del[rt0][i]=son[rt0][i],q.push(son[rt0][i]);
	while(q.size()){
		int x=q.front();
		q.pop();
		a[fail[x]].push_back(x);
		for(int i=0;i<26;i++)
			if(son[x][i]) del[x][i]=son[x][i],fail[son[x][i]]=del[fail[x]][i],q.push(son[x][i]);
			else del[x][i]=del[fail[x]][i];
	} 
}

void dfs(int p,bool f){
//	debug("p=%d\n",p);
	dfn[p]=++dfncnt;
	sz[p]=1;
	if(!f)chkmax(no[p],no[fail[p]]);
	for(int i:a[p]) dfs(i,0),sz[p]+=sz[i];
}

void init_Build(){
	tim++,bcnt=0;
	for(int i=1;i<=tot+1;i++){
		bcnt++;
		lz[bcnt]=0;
		bl[bcnt]=i,br[bcnt]=std::min(i+B-1,tot+1);
		for(int j=bl[bcnt];j<=br[bcnt];j++) bel[j]=bcnt;
		i=br[bcnt];
	}
}

void Build(){
	tim++;
	for(int i=1;i<=bcnt;i++) lz[i]=0;
//	for(int i=1;i<=tot+1;i++){
////		bcnt++;
//		lz[bel[i]]=0;
////		bl[bcnt]=i,br[bcnt]=std::min(i+B-1,tot+1);
////		for(int j=bl[bcnt];j<=br[bcnt];j++) bel[j]=bcnt;
//		i=br;
//	}	
}

void add(int l,int r,int x){
	if(bel[l]==bel[r]){
		int p=bl[bel[l]];
//		debug("[%d,%d] %d\n",l,r,x);
		ds[bel[l]].upd(l-p+1,x);
		ds[bel[l]].upd(r+1-p+1,-x);
		return ;
	}
	for(int i=bel[l]+1;i<bel[r]-1;i++) lz[i]+=x;
	int p=bl[bel[r]];
	ds[bel[r]].upd(1,x);
	ds[bel[r]].upd(r-p+2,-x);
	p=bl[bel[l]];
	ds[bel[l]].upd(l-p+1,x);
}

bool vis[maxm];

int query(int p){
//	debug("%d\n",p);
	int res=0,l=bl[bel[p]];
	res=ds[bel[p]].query(p-l+1);
	return res+lz[bel[p]];
}

bool Men;

signed main(){
//	system("fc replace.out replace3.ans");
//	return 0;
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	debug("%.6lfMB\n",(&Mbe-&Men)/1048576.0);
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin>>n>>q;
	rt1=1,tot=1;
	for(int i=1;i<=n;i++){
//		int s=s1.size();
		std::cin>>s1>>s2;
		int s=s1.size(); 
		c[i]=0;
		while(c[i]<s&&s1[s-c[i]-1]==s2[s-c[i]-1]) c[i]++;
		ins0(i),ins1(i);
		upd[s].push_back(i);
		chkmax(no[pos0[i]],s),chkmax(no[pos1[i]],s);
//		debug("- %d %d %d %d\n",i,pos0[i],no[pos0[i]],s);
//		no[pos0[i]]=no[pos1[i]]=s;
//		debug("%d %d\n",i,s);
//		mst.insert(s);
	}
	build0(),build1();
	dfs(0,1),dfs(1,1);
	for(int i=1;i<=q;i++){
		std::cin>>t1>>t2;
		int s=t1.size()-1,l=0,r=s;
		while(t1[l]==t2[l]) l++;
		while(t1[r]==t2[r]) r--;
		l--,r++;
//		debug("l=%d r=%d\n",l,r);
		int now0=rt0,now1=rt1,cnt=-1;
		for(int j=0;j<=s;j++){
			int x0=t1[j]-'a',x1=t2[j]-'a';
			now0=del[now0][x0],now1=del[now1][x1],cnt++;
//			debug("now1=%d\n",now1);
			if(cnt<r-1) continue;
//			debug("%d %d %d %d\n",now0,now1,no[now0],no[now1]);
			if(std::min(no[now0],no[now1])<cnt-l) continue;
//			debug("dfn0=%d dfn1=%d %d\n",dfn[now0],dfn[now1],now0);
			//y=cnt-l
			//(dfn[now],y)
			info res;
			res.x=dfn[now0],res.y=dfn[now1],res.id=i;
			Q[cnt-l].push_back(res);
//			mst.insert(res);
//			qry[dfn[now0]].push_back({dfn[now1],i});
		}
	}
	init_Build();
	vint v1,v2; 
	for(int j=1;j<=5e6;j++){
//		if(j%1000==0) debug("j=%d\n",j);
//		Build();
		bool f=0;
		for(int i:upd[j]){
			//(dfn[pos[i]]~dfn[pos[i]]+sz[pos[i]]-1,c[i])
			updz[dfn[pos0[i]]].push_back({dfn[pos1[i]],dfn[pos1[i]]+sz[pos1[i]]-1});
			updf[dfn[pos0[i]]+sz[pos0[i]]].push_back({dfn[pos1[i]],dfn[pos1[i]]+sz[pos1[i]]-1});
			f=1;
			v1.push_back(dfn[pos0[i]]),v1.push_back(dfn[pos0[i]]+sz[pos0[i]]);
	//		debug("i=%d c=%d\n",i,c[i]);
//			debug("i=%d [%d,%d] [%d,%d]\n",i,dfn[pos0[i]],dfn[pos0[i]]+sz[pos0[i]]-1,dfn[pos1[i]],dfn[pos1[i]]+sz[pos1[i]]-1);
		}
		for(info res:Q[j]){
			if(!vis[res.x]) v2.push_back(res.x),vis[res.x]=1;
			qry[res.x].push_back({res.y,res.id});//,debug("%d %d %d\n",res.x,res.y,res.id);
		}
		if(!f) continue;
		for(int j:v2) v1.push_back(j);
		std::sort(all(v1));
		Build();
//		debug("j=%d\n",j);
//		debug("ok\n");
//		Build();
		int las=-1;
		for(int i:v1){
			if(i==las) continue;
			las=i;
			for(pii j:updz[i]) add(j.fi,j.se,1);
			for(pii j:updf[i]) add(j.fi,j.se,-1);
			for(pii j:qry[i]) ans[j.se]+=query(j.fi);
			updz[i].clear(),updf[i].clear();
		}
		v1.clear();
	}
	for(int i=1;i<=q;i++) println(ans[i]);
	debug("%.6lfms\n",1e3*clock()/CLOCKS_PER_SEC);
}

