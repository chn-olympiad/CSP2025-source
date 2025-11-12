#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
template<typename T>
int SZ(const T &a){
	return a.size();
}
mt19937_64 rng(random_device{}());
constexpr int N=200010,M=5000010,mM=M-5;
constexpr ull B=19260817;
int n,q,ans[N];
ull h1[M],h2[M],pB[M];
ull H1(int l,int r){
	return h1[r]-h1[l-1]*pB[r-l+1];
}
ull H2(int l,int r){
	return h2[r]-h2[l-1]*pB[r-l+1];
}
struct Nd{
	string s1,s2;
	int id;
};
struct Trie{
	int nt,t,T[M][26],st[M],ed[M];
	struct Nd3{
		int u,id;
	};
	vector<Nd3> ps;
	void insert(const string &s,int id){
		int u=1;
		for(char i:s){
			int x=i-'a';
			if(!T[u][x]){
				T[u][x]=++nt;
				for(int j=0;j<26;j++){
					T[nt][j]=0;
				}
			}
			u=T[u][x];
		}
		ps.push_back({u,id});
	}
	void dfs(int u){
		st[u]=++t;
		for(int i=0;i<26;i++){
			if(T[u][i]){
				dfs(T[u][i]);
			}
		}
		ed[u]=t;
	}
	int query(const string &s){
		int u=1;
		for(char i:s){
			int x=i-'a';
			if(!T[u][x]){
				return 0;
			}
			u=T[u][x];
		}
		return u;
	}
}T1,T2;
struct Nd2{
	int x,l,r,w,id;
	friend int operator<(const Nd2 &a,const Nd2 &b){
		return a.x==b.x?a.id<b.id:a.x<b.x;
	}
};
struct BIT{
	int nt,s[M];
	void clear(){
		for(int i=1;i<=nt;i++){
			s[i]=0;
		}
	}
	int lb(int x){
		return x&-x;
	}
	int query(int x){
		int ans=0;
		for(;x;x-=lb(x)){
			ans+=s[x];
		}
		return ans;
	}
	void update(int x,int w){
		for(;x<=nt;x+=lb(x)){
			s[x]+=w;
		}
	}
	void update(int x,int y,int w){
		update(x,w);
		update(y+1,-w);
	}
}bit;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	pB[0]=1;
	for(int i=1;i<=mM;i++){
		pB[i]=pB[i-1]*B;
	}
	unordered_map<ull,unordered_map<ull,vector<Nd>>> U;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1==s2){
			continue;
		}
		int len=SZ(s1);
		s1=" "+s1;
		s2=" "+s2;
		for(int j=1;j<=len;j++){
			h1[j]=h1[j-1]*B+s1[j];
			h2[j]=h2[j-1]*B+s2[j];
		}
		int l=1,r=len;
		while(s1[l]==s2[l]){
			l++;
		}
		while(s1[r]==s2[r]){
			r--;
		}
		U[H1(l,r)][H2(l,r)].push_back({s1.substr(1,l-1),s2.substr(r+1,len),0});
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(SZ(s1)!=SZ(s2)){
			continue;
		}
		int len=SZ(s1);
		s1=" "+s1;
		s2=" "+s2;
		for(int j=1;j<=len;j++){
			h1[j]=h1[j-1]*B+s1[j];
			h2[j]=h2[j-1]*B+s2[j];
		}
		int l=1,r=len;
		while(s1[l]==s2[l]){
			l++;
		}
		while(s1[r]==s2[r]){
			r--;
		}
		U[H1(l,r)][H2(l,r)].push_back({s1.substr(1,l-1),s2.substr(r+1,len),i});
	}
	for(auto &[h1,_]:U){
		for(auto &[h2,A]:_){
			T1.nt=T2.nt=1;
			T1.t=T2.t=0;
			T1.ps.clear();
			T2.ps.clear();
			for(int i=0;i<26;i++){
				T1.T[1][i]=T2.T[1][i]=0;
			}
			for(auto &[s1,s2,id]:A){
				reverse(s1.begin(),s1.end());
				if(id){
					T1.insert(s1,id);
					T2.insert(s2,id);
				}
			}
			T1.dfs(1);
			T2.dfs(1);
			vector<Nd2> add;
			for(int i=0;i<SZ(T1.ps);i++){
				add.push_back({T1.st[T1.ps[i].u],T2.st[T2.ps[i].u],0,0,T1.ps[i].id});
			}
			for(auto &[s1,s2,id]:A){
				if(id){
					continue;
				}
				int u1=T1.query(s1),u2=T2.query(s2);
				if(u1&&u2){
					int l1=T1.st[u1],r1=T1.ed[u1];
					int l2=T2.st[u2],r2=T2.ed[u2];
					add.push_back({l1,l2,r2,1,0});
					add.push_back({r1+1,l2,r2,-1,0});
				}
			}
			sort(add.begin(),add.end());
			bit.nt=T2.nt;
			bit.clear();
			for(auto [x,l,r,w,id]:add){
				if(!id){
					bit.update(l,r,w);
				}
				else{
					ans[id]+=bit.query(l);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}