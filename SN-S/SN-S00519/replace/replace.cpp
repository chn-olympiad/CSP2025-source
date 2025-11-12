#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,L=5e6+10;
const unsigned long long K=103;
unsigned long long P[L<<1];
struct hash_node{
	int len;
	unsigned long long hsh;
	hash_node operator+(hash_node b){
		return {len+b.len,hsh*P[b.len]+b.hsh};
	}
	bool operator==(hash_node b){
		return len==b.len&&hsh==b.hsh;
	}
	hash_node operator-(hash_node b){
		return {len-b.len,hsh-b.hsh*P[len-b.len]};
	}
	void work(char x){
		len=1;hsh=(x-'a'+1);
	}
	void work(string s){
		len=s.size();hsh=0;
		for(int i=0;i<s.size();i++)hsh=hsh*K+(s[i]-'a'+1);
	}
	bool operator<(const hash_node&b)const{
		return (hsh==b.hsh)?(len<b.len):(hsh<b.hsh);
	}
}h[L<<1];
hash_node hsh(int l,int r){
	return h[r]-h[l-1];
}
char a[L<<1];
int m;
int n,q;
map<hash_node,int>v;
struct trie{
	int pcnt;
	struct node{
		int son[26];
		long long num;
		hash_node hsh;
	}t[L<<1];
	void insert(string s){
		int now=0;
		for(int i=0;i<s.size();i++){
			int x=s[i]-'a';
			if(!t[now].son[x]){
				t[now].son[x]=++pcnt;
				hash_node h;h.work(s[i]);
				t[t[now].son[x]].hsh=t[now].hsh+h;
			}
			now=t[now].son[x];
		}
		t[now].num++;
	}
	void dfs(int x){
		for(int i=0;i<=25;i++){
			if(!t[x].son[i])continue;
			int y=t[x].son[i];
			t[y].num+=t[x].num;
			dfs(y);
		}
		if(v.count(t[x].hsh))while(1);
		v[t[x].hsh]=x;
	}
}s;
signed main(){
	P[0]=1;for(int i=1;i<=1e7;i++)P[i]=P[i-1]*K;
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1==s2)continue;
		string str;
		int l=-1,r=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				if(l==-1)l=j;
				r=j;
			}
		}
		for(int j=0;j<l;j++)str.push_back(s1[j]);
		for(int j=l;j<=r;j++)str.push_back(s1[j]);
		for(int j=l;j<=r;j++)str.push_back(s2[j]);
		for(int j=r+1;j<s1.size();j++)str.push_back(s1[j]);
		s.insert(str);
	//	cout<<"insert("<<str<<")\n";
	}
	s.dfs(0);
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int l=-1,r=0;
		m=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				if(l==-1)l=i;
				r=i;
			}
		}
		for(int i=0;i<l;i++)a[++m]=t1[i];
		for(int i=l;i<=r;i++)a[++m]=t1[i];
		for(int i=l;i<=r;i++)a[++m]=t2[i];
		for(int i=r+1;i<t1.size();i++)a[++m]=t1[i];
	//	cout<<"find(";for(int i=1;i<=m;i++)cout<<a[i];cout<<")\n";
		for(int i=1;i<=m;i++){
			h[i].work(a[i]);h[i]=h[i-1]+h[i];
		}
		l++;r++;r=r+r-l+1;
	//	cout<<"["<<l<<","<<r<<"]\n";
		long long ans=0;
		for(int i=1;i<=l;i++){
			int p=r-1;
			if(!v.count(hsh(i,p)))continue;
			ans-=s.t[v[hsh(i,p)]].num;
			for(int j=1<<23;j;j>>=1){
				if(p+j<=m&&v.count(hsh(i,p+j)))p+=j;
			}
			ans+=s.t[v[hsh(i,p)]].num;
	//		cout<<i<<":\n";
	//		cout<<s.t[v[hsh(i,p)]].hsh.hsh<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
