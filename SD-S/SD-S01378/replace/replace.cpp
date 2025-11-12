#include<bits/stdc++.h>
#define pii pair<int,int>
#define fst first
#define snd second
using namespace std;
typedef long long ll;
ll R(){
	ll f=1,w=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-f;c=getchar();}
	while(c>='0'&&c<='9'){w=w*10-'0'+c;c=getchar();}
	return w*f;
}
void W(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) W(x/10);
	putchar(x%10+'0');
}
int const L=5e6+10,N=2e5+10;
queue<int> qu;
vector<int> vt[L];
struct AC{
	int trie[L][27],tag[L],leng[L],fail[L],in[L],cnt=0;
	int ins(vector<char> s){
		int now=0;
		for(auto c:s){
			int to=c-'a';
			if(!trie[now][to]) trie[now][to]=++cnt,leng[cnt]=leng[now]+1;
			now=trie[now][to];
		}
		tag[now]++;
		return now;
	}
	void build(){
		for(int i=0;i<26;i++){
			if(trie[0][i]) qu.push(trie[0][i]);
		}
		while(qu.size()){
			int u=qu.front();qu.pop();
			for(int i=0;i<26;i++){
				if(trie[u][i]){
					fail[trie[u][i]]=trie[fail[u]][i];
					qu.push(trie[u][i]);
				} 
				else trie[u][i]=trie[fail[u]][i];
			}
		}
		for(int i=1;i<=cnt;i++){
			vt[fail[i]].push_back(i);
		}
		qu.push(0);
		while(qu.size()){
			int u=qu.front();qu.pop();
			for(auto v:vt[u]){
				tag[v]+=tag[u];
				qu.push(v);
			}
		}
	}
	int qry(vector<char> s,int r,int o){
		int len=s.size(),sum=0,now=0;
		for(int i=0;i<len;i++){
			now=trie[now][s[i]-'a'];
			if(i>=r&&(i&1)==o) sum+=tag[now];
		}
		return sum;
	}
}ac;
vector<char> s;
char ss1[L],ss2[L];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=R(),q=R();
	for(int i=1;i<=n;i++){
		scanf("%s %s",ss1+1,ss2+1);
		int len=strlen(ss1+1),l=n,r=1;
		for(int j=1;j<=len;j++){
			s.push_back(ss1[j]);
			s.push_back(ss2[j]);
		}
		ac.ins(s);
		vector<char>().swap(s);
	}
	ac.build();
	for(int i=1;i<=q;i++){
		scanf("%s %s",ss1+1,ss2+1);
		if(strlen(ss1+1)!=strlen(ss2+1)){
			printf("0\n");
			continue;
		}
		int len=strlen(ss1+1),r=0,l=n;
		for(int j=1;j<=len;j++){
			s.push_back(ss1[j]);
			s.push_back(ss2[j]);
			if(ss1[j]!=ss2[j]) l=min(l,j),r=max(r,j);
		}
		int ans=0;
		ans+=ac.qry(s,r*2-1,1);
		vector<char>().swap(s);
		s.push_back(ss2[l]);
		for(int j=l+1;j<=len;j++){
			s.push_back(ss1[j]);
			s.push_back(ss2[j]);
		}
		ans-=ac.qry(s,(r-l+1)*2-2,0);	
		vector<char>().swap(s);
		printf("%d\n",ans);
	}
	return 0;
}
/*
”„¥Ω£° 
*/
