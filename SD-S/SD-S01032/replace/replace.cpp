#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
//#include <ext/pb_ds/exception.hpp>
#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/list_update_policy.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
#define int long long
using namespace std;
const int mod=514520333,BB=13331;//zhe shi na ge qun de qun hao ne?
struct node{
	node*s[26];
	__gnu_pbds::gp_hash_table<int,int>q;
}*rt;
void ins(string s,int val){
	node*x=rt;
	x->q[val]++;
	for(auto c:s){
		int p=c-'a';
		if(x->s[p]==nullptr){
			x->s[p]=new node();
		} 
		x=x->s[p];
		x->q[val]++;
	}
}
node*ask(string s){
	node*x=rt;
	for(auto c:s){
		int p=c-'a';
		if(x->s[p]==nullptr)x->s[p]=new node();
		x=x->s[p];
	}
	return x;
}
int n,q;
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


*/
signed main(){
	rt=new node();
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		string s,t;
		cin>>s>>t;
		int n=s.size(),l=-1,r=n;
		string a,b;
		for(int i=0;i<n;++i){
			if(s[i]==t[i])l=i;
			else break;
		}
		if(l==n-1){
			continue;
		}
		for(int i=n-1;i>=0;--i){
			if(s[i]==t[i])r=i;
			else break;
		}
		for(int i=0;i<=l;++i){
			a.push_back(s[i]);
		}
		a.push_back('#');
		for(int i=l+1;i<r;++i){
			a.push_back(s[i]);
		}
		a.push_back('#');
		a.push_back('#');
		for(int i=l+1;i<r;++i){
			a.push_back(t[i]);
		}
		for(int i=r;i<n;++i){
			b.push_back(s[i]);
		}
		reverse(a.begin(),a.end());
		int ha=0;
		for(auto c:a){
			ha=ha*BB+c;
			ha%=mod;
		}
		ins(b,ha);
	}
	for(int i=1;i<=q;++i){
		string s,t;
		cin>>s>>t;
		int n=s.size(),l=-1,r=n;
		string a,b;
		for(int i=0;i<n;++i){
			if(s[i]==t[i])l=i;
			else break;
		}
		for(int i=n-1;i>=0;--i){
			if(s[i]==t[i])r=i;
			else break;
		}
		for(int i=0;i<=l;++i){
			a.push_back(s[i]);
		}
		a.push_back('#');
		for(int i=l+1;i<r;++i){
			a.push_back(s[i]);
		}
		a.push_back('#');
		a.push_back('#');
		for(int i=l+1;i<r;++i){
			a.push_back(t[i]);
		}
		for(int i=r;i<n;++i){
			b.push_back(s[i]);
		}
		node*tmp=ask(b);
		reverse(a.begin(),a.end());
		int ha=0;
		int cnt=0;
		int ans=0;		
		for(auto c:a){
			ha=ha*BB+c;
			ha%=mod;
			ans+=tmp->q[ha];
		}
		cout<<ans<<'\n';
	}
	return 0;
}


