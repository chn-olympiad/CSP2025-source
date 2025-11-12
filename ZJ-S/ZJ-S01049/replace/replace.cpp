#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define eb emplace_back
const int N=2e5+5;
const int M=5e6+5;
const ll inf=1e17+5;
int t[M];
struct ACAM{
	struct node{
		int son[27],nx,dfn,sz,len;
		vector<int> id;
		vector<int> g;
	}tr[M];
	int cnt;
	inline void ins(char *s,int Id){
		int n=strlen(s+1),u=0;
		for(int i=1;i<=n;i++){
			int v=s[i]-'a';
			if(!tr[u].son[v]) tr[u].son[v]=(++cnt),tr[cnt].len=i;
			u=tr[u].son[v];
		}
		tr[u].id.eb(Id);
	}
	queue<int> q;
	void bld(){
		for(int i=0;i<26;i++) if(tr[0].son[i]) q.push(tr[0].son[i]);
		while(!q.empty()){
			int u=q.front();q.pop();
			//printf("fail:%d %d\n",u,tr[u].nx);
			for(int i=0;i<26;i++){
				int v=tr[u].son[i];
				if(v) tr[v].nx=tr[tr[u].nx].son[i],q.push(v);
				else tr[u].son[i]=tr[tr[u].nx].son[i];
			} 
		}
	}
	inline void ju1(int u,int lim){
		while(tr[u].len>=lim){
			//printf("ju1:%d %d %d\n",u,tr[u].len,lim);
			for(int v:tr[u].id) t[v]++;
			u=tr[u].nx;
		}
	}
	inline int ju2(int u,int lim){
		int res=0;
		while(tr[u].len>=lim){
			for(int v:tr[u].id) res+=t[v];
			u=tr[u].nx;
		}
		//printf("ju2:%d %d\n",u,res);
		return res;
	}
	inline void ju3(int u,int lim){
		while(tr[u].len>=lim){
			for(int v:tr[u].id) t[v]--;
			u=tr[u].nx;
		}
	}
}T1,T2;
int n,q;
ll ans[N];
char s1[M],s2[M];
void sol(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		T1.ins(s1,i),T2.ins(s2,i);
	}
	T1.bld(),T2.bld();
	while(q--){
		scanf("%s%s",s1+1,s2+1);
		n=strlen(s1+1);
		int n2=strlen(s2+1);
		if(n!=n2){
			puts("0");
			continue;
		}
		int pre=0,suf=n+1;
		for(int i=n;i;i--){
			if(s1[i]==s2[i]) suf--;
			else break;
		}
		for(int i=1;i<=n;i++){
			if(s1[i]==s2[i]) pre++;
			else break;
		}
		int u=0,v=0;
		ll res=0;
		for(int i=1;i<=n;i++){
			u=T1.tr[u].son[s1[i]-'a'];
			v=T2.tr[v].son[s2[i]-'a'];
			//printf("i:%d %d %d\n",i,u,v);
			if(i+1>=suf) T1.ju1(u,i-pre),res+=T2.ju2(v,i-pre),T1.ju3(u,i-pre); 
		}
		printf("%lld\n",res);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	//scanf("%d",&T);
	while(T--) sol();
	return 0;
}
