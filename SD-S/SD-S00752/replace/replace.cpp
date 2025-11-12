#include<bits/stdc++.h>
#define N 200005
#define M 5000005
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;int f=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) f=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	if(f) x=-x; 
}
int n,q;

const int P1=1000000007,B1=13331,P2=1000000009,B2=131;
map<pair<ll,ll>,int> mp;

int tot,cnt,rt1[N],rt2[N];
int t[M][26];
struct node{
	int x,y,num;
};
vector<node> b[N];
char s1[M],s2[M];

int dfn[M],siz[M],cd;
void dfs(int x){
	dfn[x]=++cd;siz[x]=1;
	for(int c=0;c<26;c++) if(t[x][c]) dfs(t[x][c]),siz[x]+=siz[t[x][c]];
}

struct node2{
	int x,y,k,op;
}b2[N*5];
bool cmp(node2 a,node2 b){
	return a.x<b.x||a.x==b.x&&a.op<b.op;
}
int ans[N];

int bit[M];
void add(int x,int k){
	for(;x<M;x+=x&-x) bit[x]+=k;
}
int ask(int x){
	int ans=0;
	for(;x;x-=x&-x) ans+=bit[x];
	return ans;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=n;i++){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int len=strlen(s1+1);
		int pl=0,pr=0;
		for(int i=1;i<=len;i++){
			if(s1[i]!=s2[i]){
				if(!pl) pl=i;
				pr=i;
			}
		}
		if(!pl) continue;
		ll h1=0,h2=0;
		for(int i=pl;i<=pr;i++) h1=(h1*B1+s1[i])%P1,h2=(h2*B2+s1[i])%P2;
		for(int i=pl;i<=pr;i++) h1=(h1*B1+s2[i])%P1,h2=(h2*B2+s2[i])%P2;
		if(!mp[make_pair(h1,h2)]){
			mp[make_pair(h1,h2)]=++cnt;
			rt1[cnt]=++tot;
			rt2[cnt]=++tot;
		}
		int num=mp[make_pair(h1,h2)];
		int p1=rt1[num],p2=rt2[num];
		for(int i=pl-1;i>=1;i--){
			int c=s1[i]-'a';
			if(!t[p1][c]) t[p1][c]=++tot;
			p1=t[p1][c];
		}
		for(int i=pr+1;i<=len;i++){
			int c=s1[i]-'a';
			if(!t[p2][c]) t[p2][c]=++tot;
			p2=t[p2][c];
		}
		b[num].push_back({p1,p2,0});
	}
	for(int i=1;i<=q;i++){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int len=strlen(s1+1),len2=strlen(s2+1);
		if(len!=len2) continue;
		int pl=0,pr=0;
		for(int i=1;i<=len;i++){
			if(s1[i]!=s2[i]){
				if(!pl) pl=i;
				pr=i;
			}
		}
		ll h1=0,h2=0;
		for(int i=pl;i<=pr;i++) h1=(h1*B1+s1[i])%P1,h2=(h2*B2+s1[i])%P2;
		for(int i=pl;i<=pr;i++) h1=(h1*B1+s2[i])%P1,h2=(h2*B2+s2[i])%P2;
		if(!mp[make_pair(h1,h2)]) continue;
		int num=mp[make_pair(h1,h2)];
		int p1=rt1[num],p2=rt2[num];
		for(int i=pl-1;i>=1;i--){
			int c=s1[i]-'a';
			if(!t[p1][c]) break;
			p1=t[p1][c];
		}
		for(int i=pr+1;i<=len;i++){
			int c=s1[i]-'a';
			if(!t[p2][c]) break;
			p2=t[p2][c];
		}
		b[num].push_back({p1,p2,i});
	}
	for(int i=1;i<=cnt;i++){
		cd=0;
		dfs(rt1[i]);
		cd=0;
		dfs(rt2[i]);
		int cnt2=0;
		for(node st:b[i]){
			int x=st.x,y=st.y,num=st.num;
			if(!num){
				b2[++cnt2]={dfn[x],dfn[y],1,1};
				b2[++cnt2]={dfn[x],dfn[y]+siz[y],-1,1};
				b2[++cnt2]={dfn[x]+siz[x],dfn[y],-1,1};
				b2[++cnt2]={dfn[x]+siz[x],dfn[y]+siz[y],1,1};
			}else{
				b2[++cnt2]={dfn[x],dfn[y],num,2};
			}
		}
		sort(b2+1,b2+cnt2+1,cmp);
		for(int i=1;i<=cnt2;i++){
			if(b2[i].op==1) add(b2[i].y,b2[i].k);
			else ans[b2[i].k]=ask(b2[i].y);
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}

