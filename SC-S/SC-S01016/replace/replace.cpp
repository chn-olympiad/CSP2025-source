#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
const int N=2e5+5,LG=24,LEN=2e6+5;
int n,q;
int fail[LEN],tot,ex[LEN],dep[LEN];
int HS(int a,int b){
	return a*26+b;
}
unordered_map<int,int>tr[LEN];
void add(string x,string y){
    int p=0;
    for(int i=0;i<x.size();i++){
    	int a=x[i]-'a',b=y[i]-'a';
        if(!tr[p].count(HS(a,b)))tr[p][HS(a,b)]=++tot,dep[tot]=dep[p]+1;
        p=tr[p][HS(a,b)];
    }
    ex[p]++;
}
void get(int p,int a,int b){
	if(!p)return tr[p][HS(a,b)]=0,void();
	if(!tr[fail[p]].count(HS(a,b)))get(fail[p],a,b);
	tr[p][HS(a,b)]=tr[fail[p]][HS(a,b)];
}
void bfs(){
    queue<int>Q;
    for(int i=0;i<26;i++)for(int j=0;j<26;j++){
    	if(tr[0].count(HS(i,j)))Q.push(tr[0][HS(i,j)]),fail[tr[0][HS(i,j)]]=0;
	}
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i=0;i<26;i++)for(int j=0;j<26;j++){
            if(!tr[u].count(HS(i,j)))continue;
            int x=tr[u][HS(i,j)];
            if(!tr[fail[u]].count(HS(i,j)))get(fail[u],i,j);
            fail[x]=tr[fail[u]][HS(i,j)];
            Q.push(x);
        }
    }
}
int dp[LEN],fa[LEN][LG];
vector<int>G[LEN];
void dfs(int u){
	dp[u]=dp[fail[u]]+ex[u];
	for(auto v:G[u])dfs(v);
}
void init(){
	for(int i=1;i<=tot;i++)fa[i][0]=fail[i],G[fail[i]].push_back(i);
	for(int j=1;j<LG;j++)for(int i=1;i<=tot;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	string a,b;cin>>a>>b;
        add(a,b);
    }
    bfs();
    init();
    dfs(0);
    while(q--){
        string x,y;cin>>x>>y;
        int p=0,len=x.size(),p1=-1,p2=len;
        for(int i=0;i<len;i++)if(x[i]!=y[i]){p1=i;break;}
        for(int i=len-1;i>=0;i--)if(x[i]!=y[i]){p2=i;break;}
        int ans=0;
        for(int i=0;i<len;i++){
            int a=x[i]-'a',b=y[i]-'a';
            if(!tr[p].count(HS(a,b)))get(p,a,b);
            p=tr[p][HS(a,b)];
            if(i>=p2){
            	int lst=i-p1+1;
            	if(dep[p]<lst)continue;
            	int now=p;
            	for(int j=LG-1;j>=0;j--){
            		if(dep[fa[now][j]]>=lst)now=fa[now][j];
				}
				ans+=dp[p]-dp[fail[now]];
			}
        }
        cout<<ans<<'\n';
    }
    return 0;
}/*

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/