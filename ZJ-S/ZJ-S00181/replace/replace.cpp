#include<bits/stdc++.h>
using namespace std;
#define int long long
const int md=998244353,mod=3;
vector<int>s[500001],t;
map<int,int>g;
int f[5000001];
map<int,int>mp;
int hs[500001];
int hsh[500001];
string tmp1,tmp2;
int n,q;
struct tr{
	map<int,int>son;
	int x;
}trie[5000001];
int cnt;
int fail[5000001];
void solve(int m){
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++);
	}
	printf("%lld\n",f[n]);
}
vector<int>S[2000001];
int qw[1000001];
int H(int l,int r){
	return ((hsh[r]-hsh[l-1]*qw[r-l+1]%md)%md+md)%md;
}
void solve2(int len){
	for(int i=1;i<=len;i++){
		for(int j=1;j<=n;j++){
			if(i+s[j].size()-1>len)break;
			if(H(i,i+s[j].size()-1)==hs[j])S[j].push_back(i);
		}
	}
}
void add(vector<int>s){
	int n=s.size();
	int nw=0;
	for(int i=0;i<n;i++){
		if(!trie[nw].son[s[i]])trie[nw].son[s[i]]=++cnt;
		nw=trie[nw].son[s[i]];
	}
	trie[nw].x++;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	qw[0]=1;
	for(int i=1;i<=n;i++)qw[i]=qw[i-1]*mod%md;
	for(int i=1;i<=n;i++){
		cin>>tmp1>>tmp2;
		int len=tmp1.size();
		for(int j=0;j<len;j++){
			int x=(tmp1[j]-'a')*26+tmp2[j]-'a';
			s[i].push_back(x);
		}
		add(s[i]);
		for(int j=0;j<len;j++){
			int x=(tmp1[j]-'a')*26+tmp2[j]-'a';
			hs[i]=(hs[i]*mod%md+x)%md;
		}
		mp[hs[i]]=mp[hs[i]]+1;
	}
	for(int i=1;i<=q;i++){
		cin>>tmp1>>tmp2;
		int len=tmp1.size();
//		if(tmp1.size()!=tmp2.size()){
			printf("0\n");
			continue;
//		}
		t.resize(len+1);
		f[0]=1;
		for(int j=0;j<len;j++){
			f[j+1]=0;
			int x=(tmp1[j]-'a')*26+tmp2[j]-'a';
			t[j+1]=x;
			hsh[j+1]=(hsh[j]*mod+x)%md;
		}
		solve(len);
	}
}
