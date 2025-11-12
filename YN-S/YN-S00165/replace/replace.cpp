//I love Nagato Yuki forever!!!
//pretest passed,but it's O(nq)
//final score:[50,god knows...]
#include<bits/stdc++.h>
using namespace std;
namespace Z3k7223{
	const int N=2e5+10,L=6e6+10;
	map<pair<string,string>,pair<int,int>>mp;
	int n,q;
	struct node{
		vector<int>val;
		int son[26];
	}tree[L];
	int tot;
	int s[N];
	void insert(string s,int rt,int id){
		int cur=rt;
		for(char ch:s){
			int nxt=ch-'a';
			if(!tree[cur].son[nxt]){
				tree[cur].son[nxt]=++tot;
			}
			cur=tree[cur].son[nxt];
		}
		tree[cur].val.push_back(id);
	}
	bool vis[N];
	vector<int>st;
	void clr(){
		for(int i:st)vis[i]=0;
		st.clear();
	}
	int ans=0;
	void query(string s,int rt,int mode){
		int cur=rt;
		for(char ch:s){
			if(mode==0){
				for(int i:tree[cur].val){
					vis[i]=1;
					st.push_back(i);
				}
			}else{
				for(int i:tree[cur].val){
					if(vis[i])++ans;
				}
			}
			int nxt=ch-'a';
			if(!tree[cur].son[nxt]){
				return;
			}
			cur=tree[cur].son[nxt];
		}
		if(mode==0){
			for(int i:tree[cur].val){
				vis[i]=1;
				st.push_back(i);
			}
		}else{
			for(int i:tree[cur].val){
				if(vis[i])++ans;
			}
		}
	}
	void main(){
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			string x,y;
			cin>>x>>y;
			if(x==y){
				continue;
			}
			int l=0,r=x.size()-1;
			while(x[l]==y[l])++l;
			while(x[r]==y[r])--r;
			string x1="",x2="";
			for(int i=l;i<=r;i++){
				x1+=x[i],x2+=y[i];
			}
			if(!mp.count(make_pair(x1,x2))){
				pair<int,int>tmp;
				tmp.first=++tot;
				tmp.second=++tot;
				mp[make_pair(x1,x2)]=tmp;
			}
			pair<int,int>tmp=mp[make_pair(x1,x2)];
			string ls="",rs="";
			for(int i=l-1;~i;i--)ls+=x[i];
			for(int i=r+1;i<x.size();i++)rs+=x[i];
			insert(ls,tmp.first,i);
			insert(rs,tmp.second,i);
		}
		while(q--){
			string x,y;
			cin>>x>>y;
			if(x.size()!=y.size()){
				cout<<"0\n";
				continue;
			}
			int l=0,r=x.size()-1;
			while(x[l]==y[l])++l;
			while(x[r]==y[r])--r;
			string x1="",x2="";
			for(int i=l;i<=r;i++){
				x1+=x[i],x2+=y[i];
			}
			if(!mp.count(make_pair(x1,x2))){
				cout<<"0\n";
				continue;
			}
			string ls="",rs="";
			for(int i=l-1;~i;i--)ls+=x[i];
			for(int i=r+1;i<x.size();i++)rs+=x[i];
			pair<int,int>tmp=mp[make_pair(x1,x2)];
			ans=0;
			query(ls,tmp.first,0);
			query(rs,tmp.second,1);
			clr();
			cout<<ans<<'\n';
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Z3k7223::main();
	return 0;
}
