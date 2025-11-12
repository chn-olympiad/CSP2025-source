#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=5.5e6+10;
int n,q,a[N],ans;
string s[N][2];

int totid,rt[N];

int ch[M][27],tot;
int sum[M],fail[M];
inline void add(int id,string &s){
	int p=rt[id];
	for(int i=0;i<s.size();++i){
		int c=s[i]-'a';
		if(!ch[p][c]) ch[p][c]=++tot;
		p=ch[p][c];
	}
	++sum[p];
	return;
}
inline void getfail(){
	queue<int> q;
	for(int id=1;id<=totid;++id){
		for(int i=0;i<=26;++i){
			int t=ch[rt[id]][i];
			if(t){
				fail[t]=rt[id];
				q.push(t);
			}else ch[rt[id]][i]=rt[id];
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<=26;++i){
				int v=ch[u][i];
				if(v){
					fail[v]=ch[fail[u]][i];
					sum[v]+=sum[fail[v]];
//					cout<<sum[v]<<',';
					q.push(v);
				}else{
					ch[u][i]=ch[fail[u]][i];
				}
			}
		}
	}
	return;
}

bool bbb;
/*****************************Change me to double hash!************************************/
const int b1=571247,e1=+37,mod1=765423819;
const int b2=367663,e2=-73,mod2=964382361;
map<pair<int,int>,int> mp;
inline int getid(string &s1,string &s2,int l,int r){
	int re1=0,re2=0;
	for(int i=l;i<=r;++i) re1=(re1*b2+s1[i]+e2)%mod2;
	for(int i=l;i<=r;++i) re2=(re2*b2+s2[i]+e2)%mod2;
	auto tt=mp.find({re1,re2});
	if(tt!=mp.end()) return tt->second;
	if(bbb) return -1;
	mp[{re1,re2}]=++totid;
	rt[totid]=++tot;
	return totid;
}
/*****************************Change me to double hash!************************************/
/*I'm sorry. But                                                                          */
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i][0]>>s[i][1];
		string ss="";
		int l=-1,r=-1;
		for(int j=0;j<(int)s[i][0].size();++j){
			if(s[i][0][j]!=s[i][1][j]){
				if(l==-1) l=j,ss+='{';
				r=j;
			}else ss+=s[i][0][j];
		}
		if(l==-1) --i,--n;
		else{
			int id=getid(s[i][0],s[i][1],l,r);
			add(id,ss);
//			cout<<s[i][0]<<'\n';
//			cout<<s[i][1]<<'\n';
//			cout<<id<<' '<<l<<'~'<<r<<'\n'<<ss<<'\n';
//			cout<<"\n---------------\n";
		}
	}
	getfail();bbb=1;
	while(q--){
		string t[2];
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){
			cout<<0<<'\n';
			continue;
		}
		string ss="";
		int l=-1,r=-1;
		for(int j=0;j<(int)t[0].size();++j){
			if(t[0][j]!=t[1][j]){
				if(l==-1) l=j,ss+='{';
				r=j;
			}else ss+=t[0][j];
		}
		int id=getid(t[0],t[1],l,r);
		if(id==-1){
			cout<<0<<'\n';
			continue;
		}
//		cout<<t[0]<<'\n';
//		cout<<t[1]<<'\n';
//		cout<<id<<' '<<l<<'~'<<r<<'\n'<<ss<<'\n';
//		cout<<"\n---------------\n";
		int p=rt[id];ans=0;
		for(int i=0;i<ss.size();++i){
			int c=ss[i]-'a';
			if(!ch[p][c]){
				cout<<ss<<'\n';
				cout<<i<<' ';
				return 1;
			}
			p=ch[p][c];
			ans+=sum[p];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
