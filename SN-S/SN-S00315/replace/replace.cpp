#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,B=31;
struct node{
	int l[26];
}t[N];
struct str{
	unsigned long long hsh;
	int nxt;
}va[N];
struct edge{
	int v,nxt;
}e[N];
struct que{
	unsigned long long hsh;
	int id,nxt;
}q[N];
char ch[N],s[N];
int n,tot,cnt,tt,qtt,Q,f[N],head[N],hd[N],hdq[N],ans[N];
void ad(int u,unsigned long long hsh){
	va[++cnt].hsh=hsh;
	va[cnt].nxt=head[u];
	head[u]=cnt;
}
void addd(int u,int v){
	e[++tt].v=v;
	e[tt].nxt=hd[u];
	hd[u]=tt;
}
void ask(int u,unsigned long long hsh,int id){
	q[++qtt].hsh=hsh;
	q[qtt].id=id;
	q[qtt].nxt=hdq[u];
	hdq[u]=qtt;
}
void add(int nn){
	int p=0;
	for(int i=1;i<=nn;i++){
		if(!t[p].l[ch[i]-'a']) t[p].l[ch[i]-'a']=++tot;
		p=t[p].l[ch[i]-'a']; 
	}
	unsigned long long hsh=0;
	bool fl=0;
	for(int i=1;i<=nn;i++){
		int x=0;
		if(fl) x=27;
		if(ch[i]!=s[i]) x=s[i]-'a'+1,fl=1;
		hsh=(hsh*B+x);
//		cout<<hsh<<'\n';
	}
//	if(hsh==0) cout<<(ch+1)<<' '<<(s+1)<<' '<<p<<' '<<hsh<<'\n';
	ad(p,hsh);
}
void build(){
	queue<int> q;
	for(int i=0;i<26;i++) if(t[0].l[i]) q.push(t[0].l[i]);
	while(!q.empty()){
		int x=q.front();q.pop();
//		cout<<x<<' '<<f[x]<<'\n';
		if(x) addd(f[x],x);
		for(int i=0;i<26;i++){
			if(t[x].l[i]) f[t[x].l[i]]=t[f[x]].l[i],q.push(t[x].l[i]);
			else t[x].l[i]=t[f[x]].l[i];
		}
	} 
}
unordered_map<unsigned long long,int> mp;
void dfs(int x){
	for(int i=head[x];i;i=va[i].nxt){
		mp[va[i].hsh]++;
//		cout<<x<<' '<<va[i].hsh<<'\n';
	}
//	if(x==157979) cout<<mp[0]<<' ';
	for(int i=hdq[x];i;i=q[i].nxt){
		ans[q[i].id]+=mp[q[i].hsh];
	}
	for(int i=hd[x];i;i=e[i].nxt){
		int y=e[i].v;
//		cout<<y<<' '<<x<<'\n';
		dfs(y);
	}
	for(int i=head[x];i;i=va[i].nxt){
		mp[va[i].hsh]--;
	}
}
int main(){
//	system("fc replace.out replace4.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cout<<sizeof(t)+sizeof(va)+sizeof(e)+sizeof(q)+sizeof(head)*7;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",ch+1,s+1);
//		bool fl=1;
//		for(int i=1;i<=10;i++) if(s[i]!='c') fl=0;
//		if(fl) cout<<(ch+1)<<' '<<(s+1)<<'\n';
		add(strlen(ch+1));
	}
	build();
	for(int I=1;I<=Q;I++){
		scanf("%s%s",ch+1,s+1);
//		if(I==61) cout<<(ch+1)<<' '<<(s+1)<<'\n';
		int ps=0,p=0,ll=strlen(ch+1);
		unsigned long long hsh=0;bool fl=0;
		for(int i=ll;i>=1;i--) if(ch[i]!=s[i]) {ps=i;break;}
		for(int i=1;i<=ll;i++){
			p=t[p].l[ch[i]-'a'];
			int x=0;
			if(fl) x=27;
			if(ch[i]!=s[i]) x=s[i]-'a'+1,fl=1;
			hsh=(hsh*B+x);
//			if(I==61) cout<<p<<' '<<hsh<<' '<<I<<'\n';
			if(i>=ps) ask(p,hsh,I);
		}
	}
	dfs(0);
	for(int i=1;i<=Q;i++){
//		if(ans[i]==10) cout<<i<<' ';
		printf("%d\n",ans[i]);
	}
	return 0;
}
//17:50
