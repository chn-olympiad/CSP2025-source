#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e6+10,mod=1e9+9,bs=1331;
int n,q,tot=0,cnt=0,ans[N];
//ac ,rt
string s1[N],s2[N],t1[N],t2[N];
map<pair<int,int>,int>id;
int ch[N][27],fail[N],rt[N];
vector<int>g[N],q1[N],q2[N],e[N];
map<int,int>dp;
void insert(string s,string t,int hs1,int hs2){
	if(!id[{hs1,hs2}])id[{hs1,hs2}]=++cnt,rt[cnt]=++tot;
	int pos=rt[id[{hs1,hs2}]];
	for(int i=0;i<(int)s.size();i++){
		int to=s[i]-'a'+1;
		if(!ch[pos][to])ch[pos][to]=++tot;
		pos=ch[pos][to];
	}
	int hs=0;
	for(int i=0;i<(int)t.size();i++)hs=(hs*bs+t[i])%mod;	
	g[pos].push_back(hs);
	return ;
}
void bfsFail(int now){
	for(int i=1;i<=26;i++)ch[0][i]=rt[now];
	fail[rt[now]]=0;
	queue<int>q;q.push(rt[now]);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=1;i<=26;i++){
			int y=ch[x][i];
			if(!y){ch[x][i]=ch[fail[x]][i];continue;}
			fail[y]=ch[fail[x]][i];
			e[fail[y]].push_back(y);
			q.push(y);
		}
	}
}
void dfs(int x,int fa){
	for(int i:g[x])dp[i]++;
	for(int i:q2[x]){
		int l=-1,r=-1;
		for(int j=0;j<(int)t1[i].size();j++)
			if(t1[i][j]!=t2[i][j]){if(l==-1)l=j;r=j;}
		int hs=0;ans[i]+=dp[hs];
		for(int j=l-1;j>=0;j--){
			hs=(hs*bs+t1[i][j])%mod;
			ans[i]+=dp[hs];
		}
	}
	for(int y:e[x]){
		if(y==fa)continue;
		dfs(y,x);
	}
	for(int i:g[x])dp[i]--;
}
void solve(int now){
	bfsFail(now);
	for(int i:q1[now]){
		int l=-1,r=-1;
		for(int j=0;j<(int)t1[i].size();j++)
			if(t1[i][j]!=t2[i][j]){if(l==-1)l=j;r=j;}
		int pos=rt[now];
		for(int j=t1[i].size()-1;j>r;j--){
			int to=t1[i][j]-'a'+1;
			pos=ch[pos][to];
		}
		q2[pos].push_back(i);
	}
	dp.clear();
	dfs(rt[now],0);
	return ;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int l=-1,r=-1;
		for(int j=0;j<(int)s1[i].size();j++)
			if(s1[i][j]!=s2[i][j]){if(l==-1)l=j;r=j;}
		int hs1=0,hs2=0;
		if(l==-1)continue;
		for(int j=l;j<=r;j++){
			hs1=(hs1*bs+s1[i][j])%mod;
			hs2=(hs2*bs+s2[i][j])%mod;
		}
		string t;t.clear();
		string t2;t2.clear();
		for(int j=s1[i].size()-1;j>r;j--)t+=s1[i][j];
		for(int j=l-1;j>=0;j--)t2+=s1[i][j];
		insert(t,t2,hs1,hs2);
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		if(t1[i].size()!=t2[i].size())continue;
		int l=-1,r=-1;
		for(int j=0;j<(int)t1[i].size();j++)
			if(t1[i][j]!=t2[i][j]){if(l==-1)l=j;r=j;}
		int hs1=0,hs2=0;
		if(l==-1)continue;
		for(int j=l;j<=r;j++){
			hs1=(hs1*bs+t1[i][j])%mod;
			hs2=(hs2*bs+t2[i][j])%mod;
		}
		if(id[{hs1,hs2}])q1[id[{hs1,hs2}]].push_back(i);
	}
	for(int i=1;i<=cnt;i++)solve(i);
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
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
*/
