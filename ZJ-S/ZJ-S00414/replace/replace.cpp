#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=6e6+25;
int n,q,nx[N][27],ct,tg[N],fail[N];
vector<int>v[N];
char s[2][N],t[N];
void ins(int len){
	if(len==-1) return;
	int p=0;
	for(int i=1;i<=len;i++){
		int c=t[i]-'a';
		if(!nx[p][c]) nx[p][c]=++ct;
		p=nx[p][c];
	}
	tg[p]++;
}
queue<int>q1;
void build(){
	for(int i=0;i<=26;i++)
		if(nx[0][i]) q1.push(nx[0][i]);
	fail[0]=-1;
	while(q1.size()){
		int u=q1.front();q1.pop();
		v[fail[u]].pb(u);
		for(int i=0;i<=26;i++){
			if(nx[u][i]) fail[nx[u][i]]=nx[fail[u]][i],q1.push(nx[u][i]);
			else nx[u][i]=nx[fail[u]][i];
		}
	}
}
void dfs(int u){
	for(int i:v[u]) tg[i]+=tg[u],dfs(i);
}
int query(int len){
	int p=0,res=0;
	for(int i=1;i<=len;i++){
		int c=t[i]-'a';
		p=nx[p][c],res+=tg[p];
	}
	return res;
}
int in(){
	int len=strlen(s[0]+1),nw=0;
	int st=-1,ed=-1;
	for(int j=1;j<=len;j++){
		if(s[0][j]!=s[1][j]){
			if(st==-1) st=j;
			ed=j;
		}
	}
	if(st==-1) return -1;
	for(int j=1;j<st;j++) t[++nw]=s[0][j];
	t[++nw]='a'+26;
	for(int j=st;j<=ed;j++) t[++nw]=s[0][j];
	t[++nw]='a'+26;
	for(int j=st;j<=ed;j++) t[++nw]=s[1][j];
	t[++nw]='a'+26;
	for(int j=ed+1;j<=len;j++) t[++nw]=s[0][j];
	return nw;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%s%s",s[0]+1,s[1]+1),ins(in());
	build(),dfs(0);
	while(q--){
		scanf("%s%s",s[0]+1,s[1]+1);
		int l1=strlen(s[0]+1),l2=strlen(s[1]+1);
		if(l1!=l2) printf("0\n");
		else printf("%d\n",query(in()));
	}
	return 0;
}