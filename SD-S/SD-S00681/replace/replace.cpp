#include<bits/stdc++.h>
#define ll long long
#define low(X) (X&(-X))
#define pb(A) push_back(A)
#define mk(A,B) make_pair(A,B)
using namespace std;
ll read(){
	ll S=0,F=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')F*=-1;
		ch=getchar();
	}while(isdigit(ch)){
		S=(S<<3)+(S<<1)+(ch^48);
		ch=getchar();
	}return S*F;
}const int N=2e5,M=5e6;
struct tr{
	int son[M+N+10][27],n=1;
	int v[M+N+10];
	void init(){
		n=1;
		memset(son,0,sizeof(son));
		memset(v,0,sizeof(v));
	}
	int add(int now,vector<int>str){
		for(int i:str){
			if(!son[now][i]){
				son[now][i]=++n;
			}now=son[now][i];
		}
		return now;
	}int ask(int now,vector<int>str){
		for(int i:str){
			if(!son[now][i])return 0;
			now=son[now][i];
		}return v[now];
	}
}tr0;
struct AC{
	int n;
	vector<int>son[27],fail,h;
	void init(){n=1;
		for(int i=0;i<27;i++){
			son[i].pb(1);son[i].pb(0);
		}fail.pb(0);fail.pb(0);
		h.pb(0);h.pb(0);
	}void ppb(){
		for(int i=0;i<27;i++)son[i].pb(0);
		fail.pb(0);h.pb(0);
	}void add(vector<int>str){
		int now=1;
		for(int i:str){
			if(!son[i][now]){
				son[i][now]=++n;
				ppb();
			}now=son[i][now];
		}h[now]++;
	}void get_fail(){
//		puts("in");
		queue<int>que;que.push(1);
		while(!que.empty()){
			int x=que.front();que.pop();
			h[x]+=h[fail[x]];
			for(int i=0;i<27;i++){
				if(!son[i][x])continue;
				int fl=fail[x];
				while(!son[i][fl])fl=fail[fl];
				fail[son[i][x]]=son[i][fl];
				que.push(son[i][x]);
			}
		}
//		puts("HH");
//		for(int i=0;i<=n;i++)printf("h %d %d\n",fail[i],h[i]);
//		puts("out");
	}ll ask(vector<int>str){
		int now=1;ll ans=0;
		for(int i:str){
			while(!son[i][now]){
//				puts("A");
				now=fail[now];
			}
			now=son[i][now];
			ans+=h[now]; 
		}return ans;
	}
}tr1[N+10];
int n,q,ac;vector<int>s0,s1;
string s[N+10][2];
int sl[N+10],sr[N+10];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	tr0.init();
	n=read();q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];sr[i]=s[i][0].length()-1;
		while(sl[i]<=sr[i]&&s[i][0][sl[i]]==s[i][1][sl[i]])sl[i]++;
		while(sl[i]<=sr[i]&&s[i][0][sr[i]]==s[i][1][sr[i]])sr[i]--;
		if(sl[i]>sr[i])continue;
//		printf("%d\n",i);
		s0.clear();
		for(int j=sl[i];j<=sr[i];j++){
			s0.pb(s[i][0][j]-'a');
			s0.pb(s[i][1][j]-'a');
		}int gt=tr0.add(1,s0);
		if(!tr0.v[gt]){
			tr0.v[gt]=++ac;
			tr1[ac].init();
		}gt=tr0.v[gt];
//		printf("%d %d %d\n",sl[i],sr[i],gt);
		s1.clear();
		for(int j=0;j<sl[i];j++)s1.pb(s[i][0][j]-'a');
		s1.pb(26);
		for(int j=sr[i]+1;j<s[i][0].length();j++)s1.pb(s[i][0][j]-'a');
		tr1[gt].add(s1);
	}for(int i=1;i<=ac;i++)tr1[i].get_fail();
	while(q--){
		string t0,t1;
		cin>>t0>>t1;
		int l=0,r=t0.length()-1;
		if(t0.length()!=t1.length())puts("0");
		else{
			s0.clear();s1.clear();
			while(l<=r&&t0[l]==t1[l])l++;
			while(l<=r&&t0[r]==t1[r])r--;
			s0.clear();
			for(int j=l;j<=r;j++){
				s0.pb(t0[j]-'a');
				s0.pb(t1[j]-'a');
			}int gt=tr0.ask(1,s0);
			s1.clear();
			for(int j=0;j<l;j++)s1.pb(t0[j]-'a');
			s1.pb(26);
			for(int j=r+1;j<t0.length();j++)s1.pb(t0[j]-'a');
			ll ans=0;
			if(gt)ans=tr1[gt].ask(s1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
