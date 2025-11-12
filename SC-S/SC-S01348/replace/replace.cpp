#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
const int N=2e5+5,L=5e6+5,base=1331;
int n,q;
namespace SolveB{
	vector<pair<int,int>> x[L<<1];
	struct Query{
		int llen,rlen;
		int id;
	};
	vector<Query> que[L<<1];
	int ans[N];
	bool check(const string &str){
		for (char ch:str) if (ch!='a' && ch!='b') return false;
		return true;
	}
	int get(const string &s1,const string &s2){
		return (int)(s1.find('b'))-(int)(s2.find('b'));
	}
	void Addx(const string &s1,const string &s2){
		x[get(s1,s2)+L].push_back({(int)(s1.find('b')),(int)(s2.size()-s2.find('b')-1)});
	}
	void Addq(const string &s1,const string &s2,int id){
		que[get(s1,s2)+L].push_back({(int)(s1.find('b')),(int)(s2.size()-s2.find('b')-1),id});
	}
	int tr[L];
	int lowbit(int x){
		return x&(-x);
	}
	void update(int p,int x){
		p++;
		for (;p<L;p+=lowbit(p)) tr[p]+=x;
	}
	int ask(int p){
		p++;
		int ans=0;
		for (;p;p-=lowbit(p)) ans+=tr[p];
		return ans;
	}
	void solve(){
		for (int i=0;i<(L<<1);i++){
			sort(x[i].begin(),x[i].end(),[&](auto a,auto b){
				return a.first<b.first;
			});
			sort(que[i].begin(),que[i].end(),[&](auto a,auto b){
				return a.llen<b.llen;
			});
			size_t j=0;
			for (Query q:que[i]){
				while (j<x[i].size() && x[i][j].first<=q.llen)
					update(x[i][j++].second,1);
				ans[q.id]=ask(q.rlen);
			}
			for (size_t v=0;v<j;v++)
				update(x[i][v].second,-1);
		}
		for (int i=1;i<=q;i++)
			cout<<ans[i]<<"\n";
	}
}
struct ACNode{
	int nxt[26];
	int fail;
	int num;
	bool vis;
}tr[L];
int tot;
map<pair<ull,ull>,int> rt;
void insert(int &rt,const string &S){
	if (!rt) rt=++tot;
	int p=rt;
	for (const char &ch:S){
		if (!tr[p].nxt[ch-'a'])
			tr[p].nxt[ch-'a']=++tot;
		p=tr[p].nxt[ch-'a'];
	}
	tr[p].num++;
}
string x1[N],x2[N];
string q1[N],q2[N];
void build(int rt){
	queue<int> que;
	que.push(rt);
	while (!que.empty()){
		int p=que.front();
		que.pop();
		for (int i=0;i<26;i++){
			if (!tr[p].nxt[i]) continue;
			int x=tr[p].fail;
			while (x && !tr[x].nxt[i])
				x=tr[x].fail;
			if (tr[x].nxt[i])
				tr[tr[p].nxt[i]].fail=tr[x].nxt[i];
			else tr[tr[p].nxt[i]].fail=rt;
			que.push(tr[p].nxt[i]);
		}
	}
}
int check(int rt,const string &str){
	int now=rt,res=tr[rt].num;
	for (const char &ch:str){
		if (!tr[now].nxt[ch-'a']){
			while (now!=rt && !tr[now].nxt[ch-'a'])
				now=tr[now].fail;
			if (tr[now].nxt[ch-'a'])
				now=tr[now].nxt[ch-'a'];
			for (int x=now;x!=rt && !tr[x].vis;x=tr[x].fail)
				res+=tr[x].num,
				tr[x].vis=1;
		}
		else{
			now=tr[now].nxt[ch-'a'];
			for (int x=now;x!=rt && !tr[x].vis;x=tr[x].fail)
				res+=tr[x].num,
				tr[x].vis=1;
		}
	}	
	now=rt;
	for (const char &ch:str){
		if (!tr[now].nxt[ch-'a']){
			while (now!=rt && !tr[now].nxt[ch-'a'])
				now=tr[now].fail;
			if (tr[now].nxt[ch-'a'])
				now=tr[now].nxt[ch-'a'];
			for (int x=now;x!=rt && tr[x].vis;x=tr[x].fail)
				tr[x].vis=0;
		}
		else{
			now=tr[now].nxt[ch-'a'];
			for (int x=now;x!=rt && tr[x].vis;x=tr[x].fail)
				tr[x].vis=0;
		}
	}	
	return res;
}
signed main(){
#ifndef DEBUG
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#endif
//	freopen("replace\\replace4.in","r",stdin);
//	freopen("replace\\replace.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>x1[i]>>x2[i];
	for (int i=1;i<=q;i++) cin>>q1[i]>>q2[i];
	bool flag=true;
	for (int i=1;i<=n;i++)
		flag&=(SolveB::check(x1[i])),
		flag&=(SolveB::check(x2[i]));
	for (int i=1;i<=q;i++)
		flag&=(SolveB::check(q1[i])),
		flag&=(SolveB::check(q2[i]));
	if (flag){
		for (int i=1;i<=n;i++)
			SolveB::Addx(x1[i],x2[i]);
		for (int i=1;i<=q;i++)
			SolveB::Addq(q1[i],q2[i],i);
		SolveB::solve();
		return 0;
	}
	for (int i=1;i<=n;i++){
		string s1,s2;
		s1=x1[i];
		s2=x2[i];
		if (s1==s2) continue;
		size_t L=s1.size()-1,R=0;
		for (size_t i=0;i<s1.size();i++)
			if (s1[i]!=s2[i]){
				L=min(L,i);
				R=max(R,i);
			}
		ull hsh1=0,hsh2=0;
		for (size_t i=L;i<=R;i++){
			if (s1[i]==s2[i]){
				hsh1=hsh1*base;
				hsh2=hsh2*base;
			}
			else{
				hsh1=hsh1*base+(s1[i]-'a'+1);
				hsh2=hsh2*base+(s2[i]-'a'+1);
			}
		}
		string same;
		for (size_t i=0;i<s1.size();i++)
			if (s1[i]==s2[i])
				same.push_back(s1[i]);
		insert(rt[{hsh1,hsh2}],same);
	}
	for (pair<pair<ull,ull>,int> pr:rt)
		build(pr.second);
	string s1,s2;
	for (int i=1;i<=q;i++){
		s1=q1[i],s2=q2[i];
		size_t L=s1.size()-1,R=0;
		for (size_t i=0;i<s1.size();i++)
			if (s1[i]!=s2[i]){
				L=min(L,i);
				R=max(R,i);
			}
		ull hsh1=0,hsh2=0;
		for (size_t i=L;i<=R;i++){
			if (s1[i]==s2[i]){
				hsh1=hsh1*base;
				hsh2=hsh2*base;
			}
			else{
				hsh1=hsh1*base+(s1[i]-'a'+1);
				hsh2=hsh2*base+(s2[i]-'a'+1);
			}
		}
		string same;
		for (size_t i=0;i<s1.size();i++)
			if (s1[i]==s2[i])
				same.push_back(s1[i]);
		cout<<check(rt[{hsh1,hsh2}],same)<<"\n";
	}
}
/*
没招了

怎么又是字符串又是计数的

为什么不考数据结构口牙

投降
*/