#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,M=5e6+5;
const int B=35,P1=1e9+7,P2=998244353;
int n,q,idcnt,ans[N];
string s1[N],s2[N],t1[N],t2[N];

int rt1[N],rt2[N];
int son1[M][26],son2[M][26],pos[N],cntv[M],c1,c2;
vector<int> tmp[M];
vector<pair<int,string>> qs[M];
unordered_map<ull,int> id;

void add(int id,int cur,string s,string t){
	if(!rt1[id]) rt1[id]=++c1;
	int u=rt1[id];
	for(int i=0;i<s.size();i++){
		if(!son1[u][s[i]-'a']) son1[u][s[i]-'a']=++c1;
		u=son1[u][s[i]-'a'];
	}
	tmp[u].push_back(cur);
	if(!rt2[id]) rt2[id]=++c2;
	u=rt2[id];
	for(int i=0;i<t.size();i++){
		if(!son2[u][t[i]-'a']) son2[u][t[i]-'a']=++c2;
		u=son2[u][t[i]-'a'];
	}
	pos[cur]=u;
}
void query(int id,int cur,string s,string t){
	int u=rt1[id];
	for(int i=0;i<s.size();i++){
		if(!son1[u][s[i]-'a']) break;
		u=son1[u][s[i]-'a'];
	}
	qs[u].push_back({cur,t});
}
int now;
void dfs(int u){
	for(int x:tmp[u]){
		cntv[pos[x]]++;
	}
	for(auto tmp:qs[u]){
		int id=tmp.first;
		string str=tmp.second;
		int u=rt2[now];
		for(int i=0;i<=str.size();i++){
			ans[id]+=cntv[u];
			if(i==str.size()) break;
			if(!son2[u][str[i]-'a']) break;
			u=son2[u][str[i]-'a'];
		}
	}
	for(int i=0;i<26;i++){
		if(son1[u][i]) dfs(son1[u][i]);
	}
	for(int x:tmp[u]){
		cntv[pos[x]]--;
	}
}
void process(int p){
	now=p;
	dfs(rt1[p]);
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i]) continue;
		int len=s1[i].size(),l=len,r=-1;
		for(int k=0;k<len;k++){
			if(s1[i][k]!=s2[i][k]){
				l=min(l,k),r=max(r,k);
			}
		}
		int x1=0,x2=0;
		for(int k=l;k<=r;k++){
			x1=(1ll*x1*B+(s1[i][k]-'a'+1))%P1;
			x2=(1ll*x2*B+(s1[i][k]-'a'+1))%P2;
		}
		for(int k=l;k<=r;k++){
			x1=(1ll*x1*B+(s2[i][k]-'a'+1))%P1;
			x2=(1ll*x2*B+(s2[i][k]-'a'+1))%P2;
		}
		ull hsh=x1*P2+x2;
		if(!id[hsh]) id[hsh]=++idcnt;
		string x="",y="";
		for(int k=l-1;k>=0;k--){
			x+=s1[i][k];
		}
		for(int k=r+1;k<len;k++){
			y+=s1[i][k];
		}
		add(id[hsh],i,x,y);
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		if(t1[i].size()!=t2[i].size()) continue;
		int len=t1[i].size(),l=len,r=-1;
		for(int k=0;k<len;k++){
			if(t1[i][k]!=t2[i][k]){
				l=min(l,k),r=max(r,k);
			}
		}
		int x1=0,x2=0;
		for(int k=l;k<=r;k++){
			x1=(1ll*x1*B+(t1[i][k]-'a'+1))%P1;
			x2=(1ll*x2*B+(t1[i][k]-'a'+1))%P2;
		}
		for(int k=l;k<=r;k++){
			x1=(1ll*x1*B+(t2[i][k]-'a'+1))%P1;
			x2=(1ll*x2*B+(t2[i][k]-'a'+1))%P2;
		}
		ull hsh=x1*P2+x2;
		if(!id.count(hsh)) continue;
		string x="",y="";
		for(int k=l-1;k>=0;k--){
			x+=t1[i][k];
		}
		for(int k=r+1;k<len;k++){
			y+=t1[i][k];
		}
		query(id[hsh],i,x,y);
	}
	for(auto x:id) process(x.second);
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}