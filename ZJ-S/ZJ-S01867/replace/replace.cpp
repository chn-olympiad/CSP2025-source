#include<bits/stdc++.h>
using namespace std;
int n,qq,id,st,ed,ans,ll,x,l,u,t;
int go[5000010][26],fail[5000010],siz[5000010];
string s,s2,ss[200010],st1,st2;
vector<int> end[5000010];
queue<int> q;
char c;
inline void add(string s,int pos){
	x=0,l=s.size();
	for(int i=0;i<l;++i){
		if(!go[x][s[i]-'a']) go[x][s[i]-'a']=++id;
		siz[go[x][s[i]-'a']]=siz[x]+1;
		x=go[x][s[i]-'a'];
	}
	end[x].push_back(pos);
}
inline void getfail(){
	for(int i=0;i<26;++i)
		if(go[0][i]) q.push(go[0][i]);
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=0;i<26;++i)
			if(go[u][i]){
				fail[go[u][i]]=go[fail[u]][i];
				q.push(go[u][i]);
			}else go[u][i]=go[fail[u]][i];
	}
}
inline void query(){
	x=0,l=s.size();
	for(int i=0;i<l;++i){
		x=go[x][s[i]-'a'];
		if(st+siz[x]<=i) break;
		if(i>=ed){
			t=x;
			while(t){
				if(st+siz[t]<=i) break;
				ll=end[t].size();
				if(ll){
					for(int j=0;j<ll;++j)
						if(s2.substr(i-siz[t]+1,siz[t])==ss[end[t][j]]) ans++;
				}
				t=fail[t];
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>qq;
	for(int i=1;i<=n;++i){
		s="";
		c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while('a'<=c&&c<='z') s+=c,c=getchar();
		c=getchar();
		while('a'<=c&&c<='z') ss[i]+=c,c=getchar();
		add(s,i);
	}
	getfail();
	for(int i=1;i<=qq;++i){
		s="";
		c=getchar();
		while(c<'a'||c>'z') c=getchar();
		while('a'<=c&&c<='z') s+=c,c=getchar();
		s2="";
		c=getchar();
		while('a'<=c&&c<='z') s2+=c,c=getchar();
		int l=s.size();
		st=-1;
		for(int j=0;j<l;++j)
			if(s[j]!=s2[j]){
				st=j;
				break;
			}
		for(int j=l-1;j>=st;--j)
			if(s[j]!=s2[j]){
				ed=j;
				break;
			}
		ans=0;
		query();
		printf("%d\n",ans);
	}
	return 0;
}
