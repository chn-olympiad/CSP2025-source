#include<bits/stdc++.h>
using namespace std;
#define for1(i,a,b) for(int i=(a);i<=(b);i++)
#define for2(i,a,b) for(int i=(a);i<(b);i++)
#define for3(i,a,b) for(int i=(a);i>=(b);i--)
#define for4(i,a) for(auto &i:(a))
#define puba push_back
#define pii pair<int,int>
#define ll long long
#define mem(a,b) memset((a),(b),sizeof((a)))
const int N1=2e5+5;
int n,q,cnt,l[N1],r[N1];
ll ans[N1];
int mp[26][26];
string x,y;
struct str1{
	vector<int>s;
	int siz(){
		return s.size();
	}
}s[N1],t[N1];
namespace solve2{
	const int N=2e3+5,M=26*26;
	int son[N][M],nxt[N],tot[N],cnt;
	vector<int>v[N*M];
	void insert(vector<int>&s){
		int u=0;
		for4(i,s){
			if(!son[u][i]) son[u][i]=++cnt;
			u=son[u][i];
		}
		tot[u]++;
	}
	void build(){
		for1(i,1,n)
			insert(s[i].s);
//		cout<<cnt<<"\n";
		queue<int>q;
		for2(i,0,M){
			if(son[0][i]) q.push(son[0][i]);
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for2(i,0,M){
				int to=son[u][i];
				if(!to) son[u][i]=son[nxt[u]][i];
				else{
					nxt[son[u][i]]=son[nxt[u]][i];
					q.push(to);
				}
			}
		}
	}
	void dfs(int u){
		for4(to,v[u]){
			tot[to]+=tot[u];
			dfs(to);
		}
	}
	void solve(){
		build();
		for1(i,1,cnt)
		 	v[nxt[i]].puba(i);
		dfs(0);
//		for1(i,0,cnt){
//			cout<<tot[i]<<"-";
//			cout<<i<<":";
//			for2(j,0,M){
//				if(son[i][j]) cout<<son[i][j]<<" ";
//			}cout<<"\n";
//		}cout<<"\n";
		for1(i,1,q){
			if(ans[i]==-1) continue;
			int u=0;
			for4(j,t[i].s){
				u=son[u][j];
				ans[i]+=tot[u];
			}
//			cout<<ans[i]<<"\n";
			u=0;
			for2(j,l[i]+1,t[i].siz()){
				u=son[u][t[i].s[j]];
				ans[i]-=tot[u];
			}
			u=0;
			for1(j,0,r[i]-1){
				u=son[u][t[i].s[j]];
				ans[i]-=tot[u];
			}
			u=0;
			for1(j,l[i]+1,r[i]-1){
				u=son[u][t[i].s[j]];
				ans[i]+=tot[u];
			}
		}
	}
}
namespace solve1{
	const int N=5e6+5,M=4;
	int son[N][M],nxt[N],tot[N],cnt;
	vector<int>v[N*M];
	void insert(vector<int>&s){
		int u=0;
		for4(i,s){
			if(!son[u][i]) son[u][i]=++cnt;
			u=son[u][i];
		}
		tot[u]++;
	}
	void build(){
		for1(i,1,n)
			insert(s[i].s);
//		cout<<cnt<<"\n";
		queue<int>q;
		for2(i,0,M){
			if(son[0][i]) q.push(son[0][i]);
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for2(i,0,M){
				int to=son[u][i];
				if(!to) son[u][i]=son[nxt[u]][i];
				else{
					nxt[son[u][i]]=son[nxt[u]][i];
					q.push(to);
				}
			}
		}
	}
	void dfs(int u){
		for4(to,v[u]){
			tot[to]+=tot[u];
			dfs(to);
		}
	}
	void solve(){
		build();
		for1(i,1,cnt)
		 	v[nxt[i]].puba(i);
		dfs(0);
//		for1(i,0,cnt){
//			cout<<tot[i]<<"-";
//			cout<<i<<":";
//			for2(j,0,M){
//				if(son[i][j]) cout<<son[i][j]<<" ";
//			}cout<<"\n";
//		}cout<<"\n";
		for1(i,1,q){
			if(ans[i]==-1) continue;
			int u=0;
			for4(j,t[i].s){
				u=son[u][j];
				ans[i]+=tot[u];
			}
//			cout<<ans[i]<<"\n";
			u=0;
			for2(j,l[i]+1,t[i].siz()){
				u=son[u][t[i].s[j]];
				ans[i]-=tot[u];
			}
			u=0;
			for1(j,0,r[i]-1){
				u=son[u][t[i].s[j]];
				ans[i]-=tot[u];
			}
			u=0;
			for1(j,l[i]+1,r[i]-1){
				u=son[u][t[i].s[j]];
				ans[i]+=tot[u];
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for2(i,0,52)
		for1(j,0,i){
			if(j<26&&i-j<26) mp[j][i-j]=cnt++;
		}
			
	int ress=0;
	cin>>n>>q;
	for1(i,1,n){
		cin>>x>>y;
		ress+=x.size()+y.size();
		for2(j,0,x.size()){
			s[i].s.puba(mp[x[j]-'a'][y[j]-'a']);
		}
//		for4(j,s[i].s) cout<<j<<" ";
//		cout<<"\n";
	}
	for1(i,1,q){
		cin>>x>>y;
		if(x.size()!=y.size()){
			ans[i]=-1;
			continue;
		}
		l[i]=-1,r[i]=x.size();
		for2(j,0,x.size()){
			if(x[j]!=y[j]){
				l[i]=j;
				break;
			}
		}
		for3(j,x.size()-1,0){
			if(x[j]!=y[j]){
				r[i]=j;
				break;
			}
		}
		for2(j,0,x.size())
			t[i].s.puba(mp[x[j]-'a'][y[j]-'a']);
//		for4(j,t[i].s) cout<<j<<" ";
//		cout<<"\n";
	}
//	solve1::solve();
	if(ress<=2000) solve2::solve();
	else solve1::solve();
	for1(i,1,q){
		if(ans[i]==-1) cout<<0<<"\n";
		else cout<<ans[i]<<"\n";
	}
	
	return 0;
}/*
4 1
xabcx xadex
ab cd
bc de
aa bb
aaaa bbbb

2 1
a b
aa ab
aab
abb
*/