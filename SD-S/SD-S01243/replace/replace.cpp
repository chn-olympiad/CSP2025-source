#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define ull unsigned long long
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N = 5e6+5;
const int M = 2e5+5;
ull base=233;

char s[N],t[N];
struct AM{
	int ch[26][N],nxt[26][N],siz[N],ct = 1,fa[N];
	void clr(){
		for(int i=0;i<=ct;i++){
			siz[i] = fa[i] = 0;
			for(int j=0;j<26;j++){
				ch[j][i] = nxt[j][i] = 0;
			}
		}
		ct = 1;
	}
	void ins(int n){
		int p = 1;
		for(int i=1;i<=n;i++){
			int y = s[i]-'a';
			if(!ch[y][p]){
				ch[y][p] = ++ct;
			}
			p = ch[y][p];
		}
		siz[p]++;
	}
	void dfs(int u,int f){
		fa[u] = f;
		for(int j=0;j<26;j++){
			if(ch[j][u]){
				siz[ch[j][u]]+=siz[u];
				dfs(ch[j][u],u);
				
			}
		}
	}
	queue<int>q;
	void init(){
		for(int j=0;j<26;j++){
			nxt[j][1] = ch[j][1];
			if(ch[j][1]){
				q.push(ch[j][1]);
			}else{
				nxt[j][1] = 1;
			}
		}
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i=0;i<26;i++){
				if(ch[i][u]){
					fa[ch[i][u]] = nxt[i][fa[u]];
					q.push(ch[i][u]);
				}
				
				nxt[i][u] = ch[i][u]?ch[i][u]:nxt[i][fa[u]];
				
			}
		}
	}
	int qry(int n){
		int p = 1;
		int res = 0;
		for(int i=1;i<=n;i++){
			p = nxt[s[i]-'a'][p];
			res+=siz[p];
			cout<<"P:"<<p<<" "<<siz[p]<<"\n";
		}
		return res;
	}
}T;
vector<short>s1[M],s2[M];
int L[M*2],R[M*2],ans[M];
struct bb{
	int id;ull v;
	bool operator<(const bb&u)const{
		if(v==u.v){
			return id<u.id;
		}
		return v<u.v;
	}
}in[N*2];
void qry(int m,int p){
	L[p] = 1;R[p] = m;
	for(int i=1;i<=m;i++){
		if(s[i]==t[i]){
			L[p]++;
		}else{
			break;
		}
	}
	for(int i=m;i>=1;i--){
		if(s[i]==t[i]){
			R[p]--;
		}else{
			break;
		}
	}
	if(L[p]>m){
		in[p] = (bb){p,0};
	}else{
		ull v1=0,v2=0;
		for(int i=L[p];i<=R[p];i++){
			v1 = v1*base+(s[i]-'a'+1);
			v2 = v2*base+(t[i]-'a'+1);
		}
		for(int i=L[p];i<=R[p];i++){
			v2 = v2*base;
		}
		in[p] = (bb){p,v1+v2};
	}
}
int n,q;
void sol(int l,int r){
	if(in[r].v==-1ull){
		return;
	}
	T.clr();
	for(int i=l;i<=r;i++){
		if(in[i].id<=n){
			int m = s1[in[i].id].size();
			for(int j=0;j<m;j++){
				s[j+1] = s1[in[i].id][j]+'a';
				t[j+1] = s2[in[i].id][j]+'a';
			}
			T.ins(m);
		}else{
			int m = s1[in[i].id].size();
			cout<<"I:"<<in[i].id<<" "<<m<<" "<<L[in[i].id]<<"\n";
			for(int j=0;j<L[in[i].id]-1;j++){
				s[j+1] = s1[in[i].id][j]+'a';
			}
			ans[in[i].id-n]-=T.qry(L[in[i].id]-1);
//			for(int j=0;j<(m-R[in[i].id]);j++){
//				s[j+1] = s1[in[i].id][j+R[in[i].id]]+'a';
//			}
//			ans[in[i].id-n]-=T.qry(m-R[in[i].id]);
			for(int j=0;j<m;j++){
				s[j+1] = s1[in[i].id][j];
			}
//			ans[in[i].id]+=T.qry(m);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read();q = read();
	for(int i=1;i<=n;i++){
		scanf("%s %s",s+1,t+1);
		int m = strlen(s+1);
		for(int j=0;j<m;j++){
			s1[i].push_back(s[j+1]-'a');
			s2[i].push_back(t[j+1]-'a');
		}
		qry(m,i);
	}
	for(int i=1;i<=q;i++){
		scanf("%s %s",s+1,t+1);
		int m = strlen(s+1);
		if(m!=(int)strlen(t+1)){
			in[i+n] = (bb){i+n,-1ull};
		}else{
			for(int j=0;j<m;j++){
				s1[i+n].push_back(s[j+1]-'a');
				s2[i+n].push_back(t[j+1]-'a');
			}
			qry(m,i+n);
		}
	}
	sort(in+1,in+1+q+n);
	int l = 1;
//	cout<<"??????????\n";
	for(int i=1;i<=n+q;i++){
		if(in[i].v!=in[i+1].v||i==n+q){
			sol(l,i);
			l = i+1;
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
/*
我一定要在考前复习 AC 自动机/ll 

*/
