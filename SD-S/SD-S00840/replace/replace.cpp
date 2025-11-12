#include<bits/stdc++.h>
#define ll long long
#define getchar() (p1==p2&&(p1 = buf)==(p2 = buf+fread(buf,1,1<<20,stdin))?EOF:*p1++)
#define ll long long
using namespace std;
const ll md = 1e9+9,bs = 103;
namespace FI{
	char buf[1<<20],*p1 = buf,*p2 = buf;
	inline int read(){
		int s = 0;char ch = getchar();
		while(!isdigit(ch))ch = getchar();
		while(isdigit(ch))s = (s<<1)+(s<<3)+ch-'0',ch = getchar();
		return s;
	}
	inline int rdstr(char* s){
		int len = 0;
		s[0] = getchar();
		while(islower(s[len]))s[++len] = getchar();
		s[len] = '\0';
		return len;
	}
}
using FI::read;
using FI::rdstr;
const int N = 2500005,sN = 2e5+5;
vector<ll> ahs[N],qhs[sN];
vector<int> qr[N];
unordered_map<ll,int> mp;
ll ans[sN];
int n,Q,tot = 1,ch[N][26],qp[sN],ql[sN];
char sa[N],sb[N];
ll geth(char* s,int sp,int ep){
	ll hs = 0;
	for(int i = sp;i<ep;i++)hs = (hs*bs+s[i]-'a'+1)%md;
	return hs; 
}
void dfs(int p){
	for(ll hs:ahs[p])mp[hs]++;
	for(int i:qr[p]){
		for(int j = qp[i];j<ql[i];j++)
			if(mp.find(qhs[i][j])!=mp.end())
				ans[i]+=mp[qhs[i][j]];
	}
	for(int c = 0;c<26;c++)
		if(ch[p][c])dfs(ch[p][c]);
	for(ll hs:ahs[p])mp[hs]--;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read();Q = read();
	ll pm;
	for(int i = 1,p,c,len,j;i<=n;i++){
		len = rdstr(sa);
		rdstr(sb);
		j = 0;
		while(j<len&&sa[j]==sb[j])j++;
		if(j==len)continue;
		pm = md*geth(sa,j,len)+geth(sb,j,len);
		if(!j)mp[pm]++;
		else{
			p = 1;
			while(j>0){
				j--;
				c = sa[j]-'a';
				if(!ch[p][c])ch[p][c] = ++tot;
				p = ch[p][c];
			}
			ahs[p].emplace_back(pm);
		}
	}
	ll nha,nhb;
	for(int i = 1,p,tp,len,jl,jr;i<=Q;i++){
		ql[i] = len = rdstr(sa);
		if(len!=rdstr(sb))continue;
		jl = 0;jr = len-1;
		while(sa[jl]==sb[jl])jl++;
		while(sa[jr]==sb[jr])jr--;
		nha = geth(sa,jl,jr);
		nhb = geth(sb,jl,jr);
		qhs[i].resize(len);
		for(int j = jr;j<len;j++){
			nha = (nha*bs+sa[j]-'a'+1)%md;
			nhb = (nhb*bs+sb[j]-'a'+1)%md;
			qhs[i][j] = md*nha+nhb;
		}
		qhs[i].resize(len);
		qp[i] = jr;
		p = 1;
		while(jl>0){
			jl--;
			tp = ch[p][sa[jl]-'a'];
			if(!tp)break;
			p = tp;
		}
		qr[p].emplace_back(i);
	}
	dfs(1);
	for(int i = 1;i<=Q;i++)printf("%lld\n",ans[i]);
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
