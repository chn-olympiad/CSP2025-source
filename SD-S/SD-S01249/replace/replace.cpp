#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}
ll trie[5000010][27],trie_cnt=1;
ll endd[5000010];
string s1,s2;
string s[5000010];
ll ans;
inline void insert(string s,ll o){
	ll siz=s.size(),pos=1;
	for(ll i=0;i<siz;i++){
		ll x=s[i]-'a'+1;
		if(!trie[pos][x]) trie[pos][x]=++trie_cnt;
		pos=trie[pos][x];
	}
	endd[pos]=o;
}
inline void tryy(ll st,ll len,ll o){ 
	bool cmp=1;
	for(ll i=st,j=0;j<len;i++,j++){
		if(s2[i]!=s[o][j]){
			cmp=0;
			break;
		}
	}
	ll siz=s1.size();
	for(ll i=st+len;i<siz;i++){
		if(s1[i]!=s2[i]){
			cmp=0;
			break;
		}
	}
	ans+=cmp;
}
inline void ask(ll pos){
	ll siz=s1.size(),len=0,poss=1;
	for(ll i=pos;i<siz;i++){
		ll x=s1[i]-'a'+1;
		if(!trie[poss][x]) return;
		poss=trie[poss][x],len++;
		if(endd[poss]){
			tryy(pos,len,endd[poss]);
		}		
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n=read(),t=read();
	for(ll i=1;i<=n;i++){
		cin>>s1>>s2;
		s[i]=s2;
		insert(s1,i);
	}
	while(t--){
		cin>>s1>>s2;
		ans=0;
		ll siz=s1.size();
		for(ll i=0;i<siz;i++){
			ask(i);
			if(s1[i]!=s2[i]) break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
