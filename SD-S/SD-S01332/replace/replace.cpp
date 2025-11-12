#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
typedef long long ll;
namespace FastIO{
	template<typename T=int>T read(){
		T x=0;int f=1;char c=getchar();
		while(!isdigit(c)){if(c=='-') f=~f+1;c=getchar();};
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		return x*f;
	}
	template<typename T>void write(T x){
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	template<typename T>void Write(T x,char c='\n'){
		write(x),putchar(c);
	}
}
using namespace FastIO;
const int maxn=2e5+5;
const int maxm=5e6+5;
struct Trie{
	int ch[maxm][26],L[maxm],R[maxm],pos[maxn],tot,cnt;
	void insert(string s,int id){
		int p=0;
		for(char z:s){
			int c=z-'a';
			if(!ch[p][c]) ch[p][c]=++tot;
			p=ch[p][c];
		}
		pos[id]=p;
	}
	void dfs(int x){
		L[x]=++cnt;
		for(int i=0;i<26;i++)
			if(ch[x][i]) dfs(ch[x][i]);
		R[x]=cnt;
	}
	int Query(string s){
		int p=0;
		for(char z:s){
			int c=z-'a';
			if(!ch[p][c]) return tot+1;
			p=ch[p][c];
		}
		return p;
	}
}T1,T2;
struct Node{
	#define lowbit(x) x&(-x)
	map<int,int>t;int N;
	void add(int x,int k){
		for(;x<=N;x+=lowbit(x)) t[x]+=k;
	}
	int Query(int x){
		int ans=0;
		for(;x;x-=lowbit(x)) if(t.count(x)) ans+=t[x];
		return ans;
	}
}T[maxn];
string ss1[maxn],ss2[maxn];
pair<ll,ll>hsh[maxn],hah[maxn];
map<pair<ll,ll>,int>rid;
vector<pair<int,int>>c[maxm],Q[maxm];
int ans[maxn];
const int MOD1=998244353;
const int MOD2=1e9+7;
ll B1=13331,B2=13567;
pair<ll,ll>calc(string S){
	ll H1=0,H2=0;
	for(char c:S) H1=(H1*B1+c)%MOD1,H2=(H2*B2+c)%MOD2;
	return make_pair(H1,H2);
}
void Yorushika(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>ss1[i]>>ss2[i];
	for(int i=1;i<=q;i++){
		string t1,t2;cin>>t1>>t2;
		int m=t1.size(),j1=0,j2=m-1;
		while(j1<m&&t1[j1]==t2[j1]) j1++;
		while(j2>=0&&t1[j2]==t2[j2]) j2--;
		string S1="",S2="",S3="";
		for(int j=j1-1;j>=0;j--) S1+=t1[j];
		for(int j=j2+1;j<m;j++) S2+=t1[j];
		for(int j=j1;j<=j2;j++) S3+=t1[j];
		S3+='{';
		for(int j=j1;j<=j2;j++) S3+=t2[j];
		T1.insert(S1,i),T2.insert(S2,i);
		hsh[i]=calc(S3);
	}
	T1.dfs(0),T2.dfs(0);
	for(int i=1;i<=q;i++) Q[T1.L[T1.pos[i]]].push_back({T2.L[T2.pos[i]],i});
	for(int i=1;i<=q;i++) cin>>ans[i];
	for(int i=1;i<=n;i++){
		string s1=ss1[i],s2=ss2[i]; 
		if(s1==s2) continue;
		int m=s1.size(),j1=0,j2=m-1;
		while(j1<m&&s1[j1]==s2[j1]) j1++;
		while(j2>=0&&s1[j2]==s2[j2]) j2--;
		string S1="",S2="",S3="";
		for(int j=j1-1;j>=0;j--) S1+=s1[j];
		for(int j=j2+1;j<m;j++) S2+=s1[j];
		int x1=T1.Query(S1),x2=T2.Query(S2);
		if(x1==T1.tot+1) continue;
	//	printf("%d %d %d %d\n",x1,x2,T1.L[x1],T1.R[x1]);
		c[T1.L[x1]].push_back({x2,i});
		c[T1.R[x1]+1].push_back({x2,-i});
		for(int j=j1;j<=j2;j++) S3+=s1[j];
		S3+='{';
		for(int j=j1;j<=j2;j++) S3+=s2[j];
		hah[i]=calc(S3);
	}
	int mum=0;
	for(int i=1;i<=n;i++) T[i].N=T2.tot+1;
	vector<int>SS(T2.tot+1);
	for(int i=1;i<=T1.tot+1;i++){
		for(auto now:c[i]){
			int x2=now.first,l=T2.L[x2],r=T2.R[x2],id=max(-now.second,now.second),v=now.second<0?-1:1;
			if(x2==T2.tot+1) continue;
			if(!rid.count(hah[id])) rid[hah[id]]=++mum;
			T[rid[hah[id]]].add(l,v);
	//		printf("%d %d %d %d %d\n",l,r,v,rid[hah[id]],now.second);
	//		if(rid[hah[id]]==2) printf("%d %d %d %d\n",l,r,v,i);
			if(r<=T2.tot) T[rid[hah[id]]].add(r+1,-v);
		}
		for(auto now:Q[i]){
			int x=now.first,id=now.second;
			if(!rid.count(hsh[id])){
				ans[id]=0;
				continue;
			}
			ans[id]=T[rid[hsh[id]]].Query(x);
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}
int main(){
	file("replace");
	int Tc=1;
	while(Tc--) Yorushika();
	return 0;
}
/*
106 1
*/
