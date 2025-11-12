#include <bits/stdc++.h>
#define ll long long
#define sc scanf
#define pr printf
#define v1 first
#define v2 second
#define IINF 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
const int N=2e5+5,M=2600006,T=680;
string s[N][2],t[N][2];
map<int,int> son[M];
int lst[M];
int num[M];
int tot=0;
int dep[M];
int len[M];
vector<int> v[M];
int get_num(char a,char b){
	return (a-'a')*26+b-'b';
}
void build(){
	for(int now=1; now<= tot; now++){
		for(int i=0; i < T; i++){
			if(son[now][i])lst[son[now][i]]=son[lst[now]][i];
			else son[now][i]=son[lst[now]][i];
		}
	}
}
int fa[M][25];
void dfs1(int k,int f){
	if(f)dep[k]=dep[f]+1;
	for(auto y:v[k])dfs1(y,k);
}
void dfs(int k){
	int f=lst[k];
	fa[k][0]=f;
	num[k]+=num[f];
	for(int j=1; j < 25; j++)fa[k][j]=fa[fa[k][j-1]][j-1];
	for(auto y:v[k])dfs(y);
}
int find_dep(int k,int dp){
	for(int i=24; i >= 0; i--){
		if(dep[fa[k][i]]>=dp)k=fa[k][i];
	}
	return k;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace3.in","r",stdin);
//	freopen("res.out","w",stdout);
	int n,q;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>> n >> q;
	for(int i=1; i <= n; i++)
		cin>> s[i][0]>>s[i][1];
	for(int i=1; i <= q; i++)
		cin>> t[i][0]>>t[i][1];
	for(int i=1; i <= n; i++){
		int now=0;
		for(int j=0; j < s[i][0].size(); j++){
			int res=get_num(s[i][0][j],s[i][1][j]);
			if(!son[now][res]){
				son[now][res]=++tot;
				dep[tot]=dep[now]+1;
				v[now].push_back(tot);
			}
			now=son[now][res];
		}
		num[now]++;
	}
	build();
	dfs(0);
	dfs1(0,0);
	for(int i=1; i <= q; i++){
		int now=0;
		int ans=0;
		int st=0,ed=0;
		for(int j=0; j < t[i][0].size(); j++){
			if(t[i][0][j]!=t[i][1][j]){
				st=j;
				break;
			}
		}
		for(int j=0; j < t[i][0].size(); j++){
			if(t[i][0][j]!=t[i][1][j])ed=j;
		}
		for(int j=0; j < t[i][0].size(); j++){
			int res=get_num(t[i][0][j],t[i][1][j]);
			while(now&&!son[now][res])now=lst[now];
			now=son[now][res];
			if(j<ed)continue;
			if(dep[now]>=j-st+1)ans+=num[now]-num[fa[find_dep(now,j-st+1)][0]];
		}
		cout << ans << '\n';
	}
	return 0;
}