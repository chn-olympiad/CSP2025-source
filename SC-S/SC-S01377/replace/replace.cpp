#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N=200005,M=(int)5e6+5,P=5e6;
struct Operation{
	int x,yl,yr,w;
	bool operator<(const Operation& t) const{
		return x<t.x;
	}
}op1[N*2];
struct Question{
	int x,y,p;
	bool operator<(const Question& t) const{
		return x<t.x;
	}
}qu2[N];
int n,q,res[N],al[N],ar[N],bl[N],br[N],len1,len2;
string a1[N],a2[N],b1[N],b2[N]; char ch[M];
int dfn[M],son[M],pas1[N],pas2[N],pbs1[N],pbs2[N];
inline int lowbit(int x){
	return x&-x;
}
namespace BIT{
	int n,node[P+5];
	void init(int len){ n=len; }
	void modify(int u,int x){
		for(int i=u;i<=n;i+=lowbit(i)) node[i]+=x;
	}
	int query(int u){
		int ans=0;
		for(int i=u;i> 0;i-=lowbit(i)) ans+=node[i];
		return ans;
	}
}
namespace Trie2{
	int len_node=0,ne[M][26];
	void init(){ len_node=0; }
	int make_node(){
		len_node++;
		for(int i=0;i<26;i++) ne[len_node][i]=0;
		return len_node;
	}
	int insert(int cur,const int& len,const char* const a){
		for(int i=0;i<len;i++){
			if(!ne[cur][a[i]-'a']) ne[cur][a[i]-'a']=make_node();
			cur=ne[cur][a[i]-'a'];
		}
		return cur;
	}
	void dfs(int u,int& p){
		dfn[u]=++p,son[u]=1;
		for(int i=0;i<26;i++){
			if(!ne[u][i]) continue;
			dfs(ne[u][i],p),son[u]+=son[ne[u][i]];
		}
	}
}
namespace Trie1{
	int len_node=1,ne[M][26];
	vector<int> op[M],qu[M];
	void insert1(const string& a,int p){
		int cur=1,i;
		for(i=0;i<a.size();i++){
			if(!ne[cur][a[i]-'a'])
				ne[cur][a[i]-'a']=++len_node;
			cur=ne[cur][a[i]-'a'];
		}
		op[cur].push_back(p);
	}
	void insert2(const string& a,int p){
		int cur=1,i;
		for(i=0;i<a.size();i++)
			if(!ne[cur][a[i]-'a']) return ;
			else cur=ne[cur][a[i]-'a'];
		qu[cur].push_back(p);
	}
	void solve(int u){
		int i,j,s1,s2;
		for(i=0;i<26;i++) if(ne[u][i]>0) solve(ne[u][i]);
		if(op[u].empty()||qu[u].empty()) return ;
		Trie2::init(),Trie2::make_node(),Trie2::make_node();
		for(i=0;i<op[u].size();i++){
			s1=op[u][i];
			for(j=0;j<al[s1];j++) ch[j]=a1[s1][j];
			reverse(ch,ch+al[s1]);
			pas1[i]=Trie2::insert(1,al[s1],ch);
			for(j=ar[s1]+1;j<a1[s1].size();j++) ch[j-ar[s1]-1]=a1[s1][j];
			pas2[i]=Trie2::insert(2,a1[s1].size()-ar[s1]-1,ch);
		}
		for(i=0;i<qu[u].size();i++){
			s1=qu[u][i];
			for(j=0;j<bl[s1];j++) ch[j]=b1[s1][j];
			reverse(ch,ch+bl[s1]);
			pbs1[i]=Trie2::insert(1,bl[s1],ch);
			for(j=br[s1]+1;j<b1[s1].size();j++) ch[j-br[s1]-1]=b1[s1][j];
			pbs2[i]=Trie2::insert(2,b1[s1].size()-br[s1]-1,ch);
		}
		Trie2::dfs(1,s1=0),Trie2::dfs(2,s1=0),len1=len2=0;
		for(i=0;i<op[u].size();i++){
			s1=pas1[i],s2=pas2[i];
			op1[++len1]={dfn[s1],dfn[s2],dfn[s2]+son[s2]-1,1};
			op1[++len1]={dfn[s1]+son[s1],dfn[s2],dfn[s2]+son[s2]-1,-1};
		}
		for(i=0;i<qu[u].size();i++)
			qu2[++len2]={dfn[pbs1[i]],dfn[pbs2[i]],qu[u][i]};
		sort(op1+1,op1+len1+1),sort(qu2+1,qu2+len2+1);
		for(i=j=1;i<=len2;i++){
			while(j<=len1&&op1[j].x<=qu2[i].x)
				BIT::modify(op1[j].yl,op1[j].w),BIT::modify(op1[j].yr+1,-op1[j].w),j++;
			res[qu2[i].p]=BIT::query(qu2[i].y);
		}
		while(j<=len1)
			BIT::modify(op1[j].yl,op1[j].w),BIT::modify(op1[j].yr+1,-op1[j].w),j++;
	}
}
void write(int x){
	static char a[12]; int n=0,i;
	do a[++n]=x%10+'0',x/=10; while(x>0);
	for(i=n;i>0;i--) putchar(a[i]);
	putchar('\n');
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int i; cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
		if(a1[i]==a2[i]) continue;
		al[i]=0,ar[i]=a1[i].size()-1;
		while(a1[i][al[i]]==a2[i][al[i]]) al[i]++;
		while(a1[i][ar[i]]==a2[i][ar[i]]) ar[i]--;
		Trie1::insert1(a1[i].substr(al[i],ar[i]-al[i]+1)+a2[i].substr(al[i],ar[i]-al[i]+1),i);
	}
	for(i=1;i<=q;i++){
		cin>>b1[i]>>b2[i];
		if(b1[i].size()!=b2[i].size()) continue;
		bl[i]=0,br[i]=b1[i].size()-1;
		while(b1[i][bl[i]]==b2[i][bl[i]]) bl[i]++;
		while(b1[i][br[i]]==b2[i][br[i]]) br[i]--;
		Trie1::insert2(b1[i].substr(bl[i],br[i]-bl[i]+1)+b2[i].substr(bl[i],br[i]-bl[i]+1),i);
	}
	BIT::init(P+2),Trie1::solve(1);
	for(i=1;i<=q;i++) write(res[i]);
	return 0;
}