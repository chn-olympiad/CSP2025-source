#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 200005
#define N 5000006
#define P std::make_pair
#define pair std::pair<int,int>
// #define p first
// #define q second
int n,m,ans[M],cnt;
int lens[M],lent[M];
std::string s[M][2],t[M][2];
int pl[M],pr[M],tl[M],tr[M];
std::map<pair,signed>ap;
std::vector<int>aid[M],fid[M];
struct Hash {
	int mod,base;
	int hash(string &str,int l,int r) {
		if(l>r||l<0||r>=str.length()) {
			// cerr<<"Error";
			return -1;
		}
		int res=1;
		for(int i=l;i<=r;i++)
			res=(res*base+str[i]-'a'+1)%mod;
		return res;
	}
}H1,H2;
signed cs[N][26],ct[N][26],cnts,cntt,sum[N];
std::vector<signed>sp[N],/*tp[N],*/qp[N];
int /*frs[M],*/frt[M];
void dfs(int x) {
	for(int i=0;i<sp[x].size();i++) sum[frt[sp[x][i]]]++;
	for(int _i=0,i,cur;_i<qp[x].size();_i++) {
		i=qp[x][_i],cur=0,ans[i]=sum[cur];
		for(int j=tr[i]+1;j<lent[i];j++) {
			if(!ct[cur][t[i][0][j]-'a']) break;
			cur=ct[cur][t[i][0][j]-'a'],ans[i]+=sum[cur];
		}
	}
	for(int i=0;i<26;i++) if(cs[x][i]) dfs(cs[x][i]);
	for(int i=0;i<sp[x].size();i++) sum[frt[sp[x][i]]]--;
}
signed main() {
	H1.mod=99824435320090627,H1.base=31;
	H2.mod=20090515998244381,H2.base=37;
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	// s[i][1]=s[i][2]
	// len[t[i][1]]!=len[t[i][2]]
	std::cin>>n>>m;
	for(int i=1,len;i<=n;i++) {
		std::cin>>s[i][0]>>s[i][1],len=lens[i]=s[i][0].length();
		if(s[i][0]==s[i][1]) {
			i--,n--;
			continue;
		}
		pl[i]=0,pr[i]=len-1;
		for(int j=0;j<len;j++) {
			if(s[i][0][j]==s[i][1][j]) pl[i]++;
			else break;
		}
		for(int j=len-1;j>=0;j--) {
			if(s[i][0][j]==s[i][1][j]) pr[i]--;
			else break;
		}
		pair val=P(H1.hash(s[i][0],pl[i],pr[i]),H2.hash(s[i][1],pl[i],pr[i])); // bing fei shuang ha xi
		int id=ap[val]; if(!id) ap[val]=id=++cnt;
		aid[id].push_back(i);
	}
	for(int i=1,len;i<=m;i++) {
		std::cin>>t[i][0]>>t[i][1],len=lent[i]=t[i][0].length();
		if(t[i][1].length()!=len) {ans[i]=0;continue;}
		tl[i]=0,tr[i]=len-1;
		for(int j=0;j<len;j++) {
			if(t[i][0][j]==t[i][1][j]) tl[i]++;
			else break;
		}
		for(int j=len-1;j>=0;j--) {
			if(t[i][0][j]==t[i][1][j]) tr[i]--;
			else break;
		}
		pair val=P(H1.hash(t[i][0],tl[i],tr[i]),H2.hash(t[i][1],tl[i],tr[i])); // bing fei shuang ha xi
		int id=ap[val]; if(!id) {ans[i]=0;continue;}
		fid[id].push_back(i);
	}
	for(int id=1;id<=cnt;id++) {
		for(int i=0;i<=cnts;i++) memset(cs[i],0,sizeof cs[i]),qp[i].clear(),sp[i].clear(); cnts=0;
		for(int i=0;i<=cntt;i++) memset(ct[i],0,sizeof ct[i]); cntt=0;
		for(int _i=0,i;_i<aid[id].size();_i++) {
			i=aid[id][_i];
			int cur=0;
			for(int j=pl[i]-1;j>=0;j--) {
				if(!cs[cur][s[i][0][j]-'a']) cs[cur][s[i][0][j]-'a']=++cnts;
				cur=cs[cur][s[i][0][j]-'a'];
			} sp[cur].push_back(i);
			cur=0;
			for(int j=pr[i]+1;j<lens[i];j++) {
				if(!ct[cur][s[i][0][j]-'a']) ct[cur][s[i][0][j]-'a']=++cntt;
				cur=ct[cur][s[i][0][j]-'a'];
			} frt[i]=cur;
		}
		for(int _i=0,i;_i<fid[id].size();_i++) {
			i=fid[id][_i];
			int cur=0;
			for(int j=tl[i]-1;j>=0;j--) {
				if(!cs[cur][t[i][0][j]-'a']) break;
				cur=cs[cur][t[i][0][j]-'a'];
			} qp[cur].push_back(i);
		}
		dfs(0);
	}
	for(int i=1;i<=m;i++) {
		std::cout<<ans[i]<<' ';
		std::cout<<'\n';
	}
	return 0;
}

// zi fu chuan ha xi hai zai zhui wo
// wo de nao zi li wei shen me yi zhi zai xiang "Ready To Rock"
// dan shi wo xiang ting Heavenly Me,how qie ge