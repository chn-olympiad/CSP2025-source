#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define ull unsigned long long
#define Ckmax(x,y) x=max((x),(y))
#define Ckmin(x,y) x=min((x),(y))
using namespace std;
const int N=6e6+5;
const int IINF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3fll;

inline void FileIO(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}

template<typename Type>
inline void read(Type &res){
	Type x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	res=x*f;
}

int n,Q;
int tp,ans[N];
map<pair<ull,ull>,int> mp;
const ull bs=13331;
ull pw[N],hs[N];
char a[N],b[N],s[N]; int len;

int root1[N],root2[N],tot;
int trie[N][26];
int lp[N],rp[N],tim;
pii path[N];

int Insert(int rt){
	int p=rt;
	for(int i=1;i<=len;i++){
		int c=s[i]-'a';
		if(!trie[p][c]) trie[p][c]=++tot;
		p=trie[p][c];
	}
	return p;
}

int Find(int rt){
	int p=rt;
	for(int i=1;i<=len;i++){
		int c=s[i]-'a';
		if(!trie[p][c]) return p;
		p=trie[p][c];
	}
	return p;
}

struct Node{
	int x,v,id;
	
	bool operator<(const Node& tmp)const{
		return x<tmp.x||(x==tmp.x&&id<tmp.id);
	}
};
vector<Node> c[N];

pair<ull,ull> Gethash(int l,int r){
	hs[l-1]=0;
	for(int i=l;i<=r;i++)
		hs[i]=hs[i-1]*bs+(a[i]-'a'+1);
	ull val1=hs[r];
	hs[l-1]=0;
	for(int i=l;i<=r;i++)
		hs[i]=hs[i-1]*bs+(b[i]-'a'+1);
	ull val2=hs[r];
	return {val1,val2};
}

void dfs(int x){
	lp[x]=++tim;
	for(int i=0;i<26;i++){
		if(trie[x][i]){
			dfs(trie[x][i]);
		}
	}
	rp[x]=tim;
}

int tr[N];

void Update(int p,int v){
	for(;p<=tim;p+=p&-p) tr[p]+=v;
}

int Ask(int p){
	int res=0;
	for(;p;p-=p&-p) res+=tr[p];
	return res;
}

signed main(){
	//静心，longlong，大小，空间，格式，文件，复杂度
	FileIO();
	read(n),read(Q);
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*bs;
	for(int i=1;i<=n;i++){
		scanf("%s",a+1);
		scanf("%s",b+1);
		int k=strlen(a+1);
		int l=0,r=k+1;
		while(l<k&&a[l+1]==b[l+1]) ++l;
		while(r>1&&a[r-1]==b[r-1]) --r;
		if(l==k) continue;
		pair<ull,ull> val=Gethash(l+1,r-1);
		int id=0;
		if(!mp.count(val)){
			mp[val]=++tp; id=tp;
			root1[tp]=++tot;
			root2[tp]=++tot;
		}
		else id=mp[val];
		len=0;
		for(int j=l;j;j--) s[++len]=a[j];
		path[i].first=Insert(root1[id]);
		len=0;
		for(int j=r;j<=k;j++) s[++len]=a[j];
		path[i].second=Insert(root2[id]);
	}
	for(int i=1;i<=tp;i++) dfs(root1[i]),dfs(root2[i]);
	for(int i=1;i<=n;i++){
		int p=path[i].first,q=path[i].second;
		if(!p) continue;
		c[lp[p]].push_back(Node{lp[q],1,0});
		c[lp[p]].push_back(Node{rp[q]+1,-1,0});
		c[rp[p]+1].push_back(Node{lp[q],-1,0});
		c[rp[p]+1].push_back(Node{rp[q]+1,1,0});
	}
	for(int i=1;i<=Q;i++){
		scanf("%s",a+1);
		scanf("%s",b+1);
		int k=strlen(a+1);
		if((signed)strlen(b+1)!=k) continue;
		int l=0,r=k+1;
		while(l<k&&a[l+1]==b[l+1]) ++l;
		while(r>1&&a[r-1]==b[r-1]) --r;
		pair<ull,ull> val=Gethash(l+1,r-1);
		int id=mp[val];
		if(!id) continue;
		len=0;
		for(int j=l;j;j--) s[++len]=a[j];
		int p=Find(root1[id]);
		len=0;
		for(int j=r;j<=k;j++) s[++len]=a[j];
		int q=Find(root2[id]);
		c[lp[p]].push_back(Node{lp[q],0,i});
	}
	for(int i=1;i<=tim;i++){
		sort(c[i].begin(),c[i].end());
		for(Node j:c[i]){
			if(!j.id) Update(j.x,j.v);
			else ans[j.id]=Ask(j.x);
		}
	}
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/

