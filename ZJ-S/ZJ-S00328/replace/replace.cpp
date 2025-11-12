#include<bits/stdc++.h>
using namespace std;
int n,m,ans[200005];
char s[5000005],t[5000005];
struct qry{
	int x,y,op,id;
};
struct qry2{
	int l,r,op;
};
vector<qry>ask[2500005];
vector<qry2>chg[2500005];
struct acam{
	struct trie{
		int ch[26];
		int fail,id;
	}a[2500005];
	int tot,dfn[2500005],siz[2500005],pos[200005],cnt,dep[2500005];
	void insert(char *s,int id){
		int n=strlen(s),x=0;
		for(int i=0;i<n;i++){
			if(!a[x].ch[s[i]-'a'])a[x].ch[s[i]-'a']=++tot,dep[tot]=dep[x]+1;
			x=a[x].ch[s[i]-'a'];
		}
		a[x].id=id,pos[id]=x;
	}
	void setfail(){
		queue<int>p;
		for(int i=0;i<26;i++)if(a[0].ch[i])p.push(a[0].ch[i]);
		while(p.size()){
			int x=p.front();p.pop();
			for(int i=0;i<26;i++){
				if(a[x].ch[i])a[a[x].ch[i]].fail=a[a[x].fail].ch[i],p.push(a[x].ch[i]);
				else a[x].ch[i]=a[a[x].fail].ch[i];
			}
		}
	}
	int fa[2500005][23];
	vector<int>q[2500005];
	void build(){
		fa[0][0]=-1;
		for(int i=1;i<=tot;i++)fa[i][0]=a[i].fail,q[a[i].fail].push_back(i);//printf("[%d %d]->[%d %d]\n",a[i].fail,a[a[i].fail].id,i,a[i].id);
		//cout<<endl;
		for(int j=1;j<=22;j++){
			for(int i=0;i<=tot;i++){
				if(fa[i][j-1]==-1)fa[i][j]=-1;
				else fa[i][j]=fa[fa[i][j-1]][j-1];
			}
		}
	}
	void dfs(int x){
		dfn[x]=++cnt,siz[x]=1;
		for(auto v:q[x])dfs(v),siz[x]+=siz[v];
	}
}acam1,acam2;
struct bit{
	int c[2500005];
	int lowbit(int i){
		return i&-i;
	}
	void add(int x,int v){
		for(int i=x;i<=acam2.tot+1;i+=lowbit(i))c[i]+=v;
	}
	int query(int x){
		int sum=0;
		for(int i=x;i;i-=lowbit(i))sum+=c[i];
		return sum;
	}
	void add(int l,int r,int v){
		add(l,v),add(r+1,-v);
	}
}bit;
signed main(){
	//system("fc replace.out replace4.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s),acam1.insert(s,i);
		scanf("%s",t),acam2.insert(t,i);
	}
	acam1.setfail(),acam1.build(),acam1.dfs(0);
	acam2.setfail(),acam2.build(),acam2.dfs(0);
	for(int i=1;i<=m;i++){
		scanf("%s%s",s,t);
		int l=-1,len=strlen(s),r=len;
		if((int)strlen(t)!=len)continue;
		for(int j=0;j<len;j++){
			if(s[j]==t[j])l=j;
			else break;
		}
		for(int j=len-1;j>=0;j--){
			if(s[j]==t[j])r=j;
			else break;
		}
		int x=0,y=0;
		for(int j=0;j<r-1;j++){
			x=acam1.a[x].ch[s[j]-'a'];
			y=acam2.a[y].ch[t[j]-'a'];
		}
		for(int j=r-1;j<len;j++){
			x=acam1.a[x].ch[s[j]-'a'];
			y=acam2.a[y].ch[t[j]-'a'];
			int x2=x,y2=y;
			//cout<<x<<" "<<y<<" "<<acam1.dep[x]<<" "<<acam2.dep[y]<<endl;
			if(j-acam1.dep[x]>l||j-acam2.dep[y]>l)continue;
			for(int k=22;k>=0;k--)if(acam1.fa[x2][k]!=-1&&j-acam1.dep[acam1.fa[x2][k]]<=l)x2=acam1.fa[x2][k];
			for(int k=22;k>=0;k--)if(acam2.fa[y2][k]!=-1&&j-acam2.dep[acam2.fa[y2][k]]<=l)y2=acam2.fa[y2][k];
			x2=acam1.fa[x2][0],y2=acam2.fa[y2][0];
			ask[acam1.dfn[x]].push_back(qry{acam1.dfn[x],acam2.dfn[y],1,i});
			if(x2!=-1)ask[acam1.dfn[x2]].push_back(qry{acam1.dfn[x2],acam2.dfn[y],-1,i});
			if(y2!=-1)ask[acam1.dfn[x]].push_back(qry{acam1.dfn[x],acam2.dfn[y2],-1,i});
			if(x2!=-1&&y2!=-1)ask[acam1.dfn[x2]].push_back(qry{acam1.dfn[x2],acam2.dfn[y2],1,i});
//			x2=x,y2=y;
//			while(x2!=-1)cout<<acam1.a[x2].id<<" ",x2=acam1.fa[x2][0];
//			cout<<endl;
//			while(y2!=-1)cout<<acam2.a[y2].id<<" ",y2=acam2.fa[y2][0];
//			cout<<endl;
		}
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		int lx=acam1.dfn[acam1.pos[i]],rx=lx+acam1.siz[acam1.pos[i]]-1;
		int ly=acam2.dfn[acam2.pos[i]],ry=ly+acam2.siz[acam2.pos[i]]-1;
		//cout<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<endl;
		chg[lx].push_back(qry2{ly,ry,1});
		chg[rx+1].push_back(qry2{ly,ry,-1});
	}
	for(int i=1;i<=acam1.tot+1;i++){
		for(auto v:chg[i])bit.add(v.l,v.r,v.op);
		for(auto v:ask[i])ans[v.id]+=v.op*bit.query(v.y);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}