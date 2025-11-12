#include<bits/stdc++.h>
inline int read(){
	int X=0;char ch;bool f=0;
	do{ch=getchar();f|=(ch=='-');}while(!isdigit(ch));
	do{X=(X<<1)+(X<<3)+(ch^48);}while(isdigit(ch=getchar()));
	return f?-X:X;
}
inline void get(std::string &s){
	char ch;
	do{ch=getchar();}while(ch<'a'||ch>'z');
	do{s=s+ch;ch=getchar();}while(ch>='a'&&ch<='z');
}
const int N=2e5+5,M=2.5e6+5;
std::string t1,t2,s[N][2];
int pre,suf;
int n,q;
int Trie[M][26][2],fail[M][2],tot[2];
std::vector<int> id[M][2];
int ans;
void solve(){
	ans=0;
	if (t1.size()!=t2.size()){puts("0");return;}
	int len=t1.size();pre=suf=0;
	for(int i=0;i<len;i++){
		if (t1[i]==t2[i]) pre++;
		else break;
	}
	for(int i=1;i<=len;i++){
		if (t1[len-i]==t2[len-i]) suf++;
		else break;
	}
	int q1=0,q2=0;
	for(int k=0;k<len;k++){
		int c1=t1[k]-'a',c2=t2[k]-'a';
		q1=Trie[q1][c1][0];q2=Trie[q2][c2][1];
		if (id[q1][0].empty()||id[q2][1].empty()) continue;
		for(int i=0,j=0;i<id[q1][0].size();i++){
			while(j<id[q2][1].size()&&id[q2][1][j]<id[q1][0][i]) j++;
			if (j>=id[q2][1].size()) break;
			if (id[q2][1][j]>id[q1][0][i]) continue;
			int qwq=id[q1][0][i];
			int awa=s[qwq][0].size();
			if (k+suf>=len-1&&k-awa+1-pre<=0){
//				if (q==27476){
//					printf("k=%d\n",k);
//					std::cout<<s[qwq][0]<<'\n';
//					std::cout<<s[qwq][1]<<'\n';
//				}
				ans++;
			}
		}
	}
//	if (ans==26){
//		std::cout<<t1<<std::endl;
//		std::cout<<t2<<std::endl;
//	}
	printf("%d\n",ans);
}
std::queue<int> que;
void init(){
	for(int i=1;i<=n;i++){
		int q=0;
		for(int j=0;j<s[i][0].size();j++){
			int c=s[i][0][j]-'a';
			if (!Trie[q][c][0]) Trie[q][c][0]=++tot[0];
			q=Trie[q][c][0];
		}id[q][0].emplace_back(i);
	}
	que.push(0);
	while(!que.empty()){
		int q=que.front();que.pop();
		for(int c=0;c<26;c++){
			if (Trie[q][c][0]){
				if (q) fail[Trie[q][c][0]][0]=Trie[fail[q][0]][c][0];
				que.push(Trie[q][c][0]);
			}
			else Trie[q][c][0]=Trie[fail[q][0]][c][0];
		}
		for(int qwq:id[fail[q][0]][0]) id[q][0].emplace_back(qwq);
	}
	for(int i=1;i<=n;i++){
		int q=0;
		for(int j=0;j<s[i][1].size();j++){
			int c=s[i][1][j]-'a';
			if (!Trie[q][c][1]) Trie[q][c][1]=++tot[1];
			q=Trie[q][c][1];
		}id[q][1].emplace_back(i);
	}
	que.push(0);
	while(!que.empty()){
		int q=que.front();que.pop();
		for(int c=0;c<26;c++){
			if (Trie[q][c][1]){
				if (q) fail[Trie[q][c][1]][1]=Trie[fail[q][1]][c][1];
				que.push(Trie[q][c][1]);
			}
			else Trie[q][c][1]=Trie[fail[q][1]][c][1];
		}
		for(int qwq:id[fail[q][1]][1]) id[q][1].emplace_back(qwq);
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){get(s[i][0]);get(s[i][1]);}init();
	while(q--){t1="";t2="";get(t1);get(t2);solve();}
	return 0;
}//AFO