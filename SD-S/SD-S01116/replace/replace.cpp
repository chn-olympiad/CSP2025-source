#include<bits/stdc++.h>
//#define int long long
#define pii pair<int,int>
#define L(i,l,r) for(int i(l);i<=(r);++i)
#define R(i,r,l) for(int i(r);i>=(l);--i)
using namespace std;
const int N=5e6+10,inf=0x7fffffff,mod=998244353; 
map<pair<string,string>,int>id;
int rt1[N],rt2[N],top,ans[N],n,q,all;
struct BIT{
	int sum[N],n;
	void init(int lim){
		n=lim;
	}
	void add(int t,int k){
		for(;t<=n;t+=(t&-t))sum[t]+=k;
	}
	int get_sum(int t){
		int res=0;
		for(;t;t-=(t&-t))res+=sum[t];
		return res;
	}
	void change(int l,int r,int k){
		add(l,k),add(r+1,-k);
	}
}T;
int ch[N][26],dfn[N],sub[N],tot;
vector<int>chan[N];
vector<pii>ask[N];
int insert(int &t,string s){
	if(!t)t=++top;
	if(s.empty())return t;
	int k=t;
	L(i,0,s.size()-1){
		int c=s[i]-'a';
		if(!ch[k][c])ch[k][c]=++top;
		k=ch[k][c];
	}
	return k;
}
int qid(int t,string s){
	if(!t)return 0;
	if(s.empty())return t;
	int k=t;
	L(i,0,s.size()-1){
		int c=s[i]-'a';
		if(!ch[k][c])return k;
		k=ch[k][c];
	}
	return k;
}
array<string,4>get(string s,string t){
	string z1="",z2="",pl="",pr="";
	int lf=-1,rt=-1,m=s.size();
	L(i,0,m-1)if(s[i]!=t[i]){
		lf=i;
		break;
	}
	R(i,m-1,0)if(s[i]!=t[i]){
		rt=i;
		break;
	}
	L(i,lf,rt)z1=z1+s[i],z2=z2+t[i];
	R(i,lf-1,0)pl=pl+s[i];
	L(i,rt+1,m-1)pr=pr+s[i];
	return {z1,z2,pl,pr};
}
void dfs(int u){
	dfn[u]=++tot;
	L(i,0,25){
		int v=ch[u][i];
		if(v)dfs(v);
	}
	sub[u]=tot;
}
void dfs1(int u){
//	cerr<<u<<'\n';
	for(auto y:chan[u])
		T.change(dfn[y],sub[y],1);
	for(auto giao:ask[u]){
		int y=giao.first,id=giao.second;
//		cerr<<u<<" "<<y<<" "<<id<<'\n';
		ans[id]=T.get_sum(dfn[y]);
	}
	L(i,0,25){
		int v=ch[u][i];
		if(v){
			dfs1(v);
//			cerr<<u<<" "<<v<<'\n';
		}
	}
	for(auto y:chan[u])
		T.change(dfn[y],sub[y],-1);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	L(i,1,n){
		string s,t;
		cin>>s>>t;
		if(s==t)continue;
		auto gt=get(s,t);
		string z1=gt[0],z2=gt[1],pl=gt[2],pr=gt[3];
		if(!id[{z1,z2}])++all,id[{z1,z2}]=all;
		int tmp=id[{z1,z2}];
		int idx=insert(rt1[tmp],pl);
		int idy=insert(rt2[tmp],pr);
		chan[idx].push_back(idy);
//		cerr<<rt1[tmp]<<" "<<rt2[tmp]<<'\n';
//		cerr<<s<<" "<<t<<" "<<z1<<" "<<z2<<" "<<pl<<" "<<pr<<'\n';
	}
//	cerr<<"giao\n";
	L(i,1,q){
		string s,t;
		cin>>s>>t;
		auto gt=get(s,t);
		string z1=gt[0],z2=gt[1],pl=gt[2],pr=gt[3];
		int tmp=id[{z1,z2}];
		if(!tmp)continue;
		int idx=qid(rt1[tmp],pl);
		int idy=qid(rt2[tmp],pr);
//		cerr<<s<<" "<<t<<" "<<z1<<" "<<z2<<" "<<pl<<" "<<pr<<'\n';
		ask[idx].push_back({idy,i});
//		cerr<<idx<<" "<<idy<<'\n';
	}
	T.init(top);
//	L(i,1,all){
//		cerr<<rt1[i]<<" "<<rt2[i]<<'\n';
//	}
	L(i,1,all)if(rt2[i])dfs(rt2[i]);
	L(i,1,all)if(rt1[i])dfs1(rt1[i]);
	L(i,1,q)cout<<ans[i]<<'\n';
	return 0;
}
