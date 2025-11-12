#include <bits/stdc++.h>
using namespace std;

const int N=2000011;
int n,m;
long long ans[N];
string s[N][2];

struct ACM{
	int to[N][26];
	int dfn[N],lst[N],siz[N];
	vector<int> v[N];
	int top,tot;
	inline void init(){
		top=1,tot=0;
		memset(to,0,sizeof(to));
	}
	inline int insert(string s){
		int x=1;
		for (int i=0;i<s.length();++i){
			int t=s[i]-97;
			if (!to[x][t]) to[x][t]=++top;
			x=to[x][t];
		}
		return x;
	}
	inline void dfs(int x){
		siz[x]=1,dfn[x]=++tot;
		for (int y:v[x]) dfs(y),siz[x]+=siz[y];
	}
	inline void build(){
		for (int i=0;i<26;++i) to[0][i]=1;
		lst[1]=0;
		queue<int> q;
		q.push(1);
		while (!q.empty()){
			int x=q.front(); q.pop();
			for (int i=0;i<26;++i){
				if (!to[x][i]){to[x][i]=to[lst[x]][i]; continue;}
				lst[to[x][i]]=to[lst[x]][i];
				v[to[lst[x]][i]].push_back(to[x][i]);
				q.push(to[x][i]);
			}
		}
		dfs(1);
	}
	inline void walk(int &x,char ch){x=to[x][ch-97];}
}A[2];

struct st{
	int x,y,z,id;
}e[N<<1];

int top;

struct BIT{
	int s[N];
	BIT(){memset(s,0,sizeof(s));}
	inline void upd(int x,int z){while (x<N) s[x]+=z,x+=x&-x;}
	inline long long query(int x){long long sum=0; while (x) sum+=s[x],x-=x&-x; return sum;}
}cat;

inline void solve(int l,int r){
	if (l>=r) return;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
	int now=l;
	for (int i=mid+1;i<=r;++i) if (e[i].id>0){
		while (now<=mid && (e[now].id>0 || e[now].y>e[i].y)){
			if (e[now].id<=0) cat.upd(N-1-e[now].z,e[now].id*2+1);
			++now;
		}
		ans[e[i].id]+=cat.query(N-2-e[i].z);
	}
	for (int i=l;i<now;++i) if (e[i].id<=0) cat.upd(N-1-e[i].z,-(e[i].id*2+1));
	inplace_merge(e+l,e+mid+1,e+r+1,[](st A,st B){return A.y>B.y;});
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);

	cin>>n>>m;
	A[0].init(),A[1].init();
	for (int i=1;i<=n;++i) cin>>s[i][0]>>s[i][1],A[0].insert(s[i][0]),A[1].insert(s[i][1]);

	// for (int i=0;i<=A[0].top;++i) for (int j=0;j<26;++j) if (A[0].to[i][j]) cout<<i<<" --"<<char(j+97)<<"-> "<<A[0].to[i][j]<<'\n';

	A[0].build(),A[1].build();

	// for (int i=0;i<=A[0].top;++i) cout<<i<<':'<<A[0].lst[i]<<'\n';

	for (int i=1;i<=m;++i){
		string t[2];
		cin>>t[0]>>t[1];

		// if (i<m-25) continue;

		int L=t[0].length();
		int l=-1,r=-1;
		for (int j=0;j<L;++j) if (t[0][j]!=t[1][j]){
			r=j; if (l==-1) l=j;
		}
		int p[2]={1,1};
		for (int j=0;j<L;++j){
			A[0].walk(p[0],t[0][j]);
			A[1].walk(p[1],t[1][j]);
			if (j>=r){
				int lim=1;
				if (l!=-1) lim=j-l+1;
				e[++top]={A[0].dfn[p[0]],A[1].dfn[p[1]],lim,i};
			}
		}
	}

	// for (int i=1;i<=top;++i) cout<<e[i].x<<' '<<e[i].y<<' '<<e[i].z<<' '<<e[i].id<<'\n';

	for (int i=1;i<=n;++i){
		int p[2]={A[0].insert(s[i][0]),A[1].insert(s[i][1])};
		int l[2]={A[0].dfn[p[0]],A[1].dfn[p[1]]};
		int r[2]={A[0].dfn[p[0]]+A[0].siz[p[0]]-1,A[1].dfn[p[1]]+A[1].siz[p[1]]-1};
		int len=s[i][0].length();
		e[++top]={r[0]+1,r[1]+1,len+1,0};
		e[++top]={r[0]+1,l[1],len+1,-1};
		e[++top]={l[0],r[1]+1,len+1,-1};
		e[++top]={l[0],l[1],len+1,0};
		// cout<<l[0]<<' '<<r[0]<<' '<<l[1]<<' '<<r[1]<<' '<<len<<'\n';
	}

	for (int i=1;i<=top;++i) if (e[i].id>0){
		for (int j=1;j<=top;++j) if (e[j].id<=0 && e[j].x>e[i].x && e[j].y>e[i].y && e[j].z>e[i].z) ans[e[i].id]+=e[j].id*2+1;
	}

	// sort(e+1,e+top+1,[](st A,st B){return A.x>B.x;});
	// solve(1,top);
	
	for (int i=1;i<=m;++i) cout<<ans[i]<<'\n';

	return 0;
}