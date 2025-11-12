#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+3,MAXM=2.5e6+3,INF=0x3f3f3f3f;
inline ll read(){
	ll x=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct node{
	int ch[26],p,sum,dep;
}nd;
vector<node> trie[2];
int insert(int k,string s){
	int cur=0;
	for(int i=0;i<s.size();i++){
		int to=s[i]-'a';
		if(trie[k][cur].ch[to]==0){
			trie[k].push_back(nd);
			trie[k][cur].ch[to]=trie[k].size()-1;
		}
		cur=trie[k][cur].ch[to];
	}
	trie[k][cur].sum++;
	return cur;
}
void ac(int k){
	queue<int> q;
	for(int i=0;i<=25;i++){
		int v=trie[k][0].ch[i];
		if(v!=0){
			trie[k][v].dep=1;
			q.push(v);
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<=25;i++){
			int v=trie[k][u].ch[i];
			if(v!=0){
				trie[k][v].p=trie[k][trie[k][u].p].ch[i];
				trie[k][v].dep=trie[k][u].dep+1;
				q.push(v);
			}
			else{
				trie[k][v].ch[i]=trie[k][trie[k][v].p].ch[i];
			}
		}
	}
}
int n,q;
struct que{
	string t1,t2;
	int l,r,len;
};
vector<que> tes;
bool cmp(que x,que y){
	return y.len<x.len;
}
map<int,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	trie[0].push_back(nd);
	trie[1].push_back(nd);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int u=insert(0,s1),v=insert(1,s2);
		mp[u]=v;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			printf("0\n");
			continue;
		}
		int l,r,len;
		int m=t2.size();
		for(int i=0;i<m;i++){
			if(t1[i]!=t2[i]){
				l=i;
				break;
			}
		}
		for(int i=m-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				r=i;
				break;
			}
		}
		len=r-l+1;
		tes.push({t1,t2,l,r,len});
	}
	ac(0);ac(1);
	return 0;
}
