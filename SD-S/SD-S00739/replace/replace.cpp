#include<bits/stdc++.h>
using namespace std;
using ll=long long;
namespace StarRail{
	struct Node{
		map<char,int>nxt;
		int v;
	}nd[5200005];
	int cnt;
	map<pair<string,string>,int>mp;
	void main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		//freopen("replace4.in","r",stdin);
		//freopen("replace4.out","w",stdout);
		ios::sync_with_stdio(0);cin.tie(0);
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			string a,b;
			cin>>a>>b;
			int l=0,r=a.size()-1,m=a.size();
			if(a==b)continue;
			while(a[l]==b[l])l++;
			while(a[r]==b[r])r--;
			auto j=make_pair(a.substr(l,r-l+1),b.substr(l,r-l+1));
			int h=mp[j],now;
			if(h)now=h;
			else{
				mp[j]=++cnt;now=cnt;
			}
			while(l>0){
				l--;
				int f=nd[now].nxt[a[l]];
				if(f)now=f;
				else{
					nd[now].nxt[a[l]]=++cnt;
					now=cnt;
				}
			}
			if(r==m-1){
				nd[now].v++;
				continue;;
			}
			if(nd[now].nxt[' '])now=nd[now].nxt[' '];
			else{
				nd[now].nxt[' ']=++cnt;
				now=cnt;
			}
			while(r<m-1){
				r++;
				int f=nd[now].nxt[a[r]];
				if(f)now=f;
				else{
					nd[now].nxt[a[r]]=++cnt;
					now=cnt;
				}
			}
			nd[now].v++;
		}
		while(q--){
			string a,b;
			cin>>a>>b;
			if(a.size()!=b.size()){
				cout<<0<<'\n';
				continue;
			}
			int l=0,r=a.size()-1,m=a.size();
			while(a[l]==b[l])l++;
			while(a[r]==b[r])r--;
			int h=mp[make_pair(a.substr(l,r-l+1),b.substr(l,r-l+1))],now=h;
			if(!h){
				cout<<0<<'\n';
				continue;
			}
			ll ans=nd[now].v;
			if(nd[now].nxt[' ']){
				int rr=r,nnow=nd[now].nxt[' '];
				while(rr<m-1){
					rr++;
					nnow=nd[nnow].nxt[a[rr]];
					if(!nnow)break;
					ans+=nd[nnow].v;
				}
			}
			while(l>0){
				l--;
				now=nd[now].nxt[a[l]];
				if(!now)break;
				ans+=nd[now].v;
				if(nd[now].nxt[' ']){
					int rr=r,nnow=nd[now].nxt[' '];
					ans+=nd[nnow].v;
					while(rr<m-1){
						rr++;
						nnow=nd[nnow].nxt[a[rr]];
						if(!nnow)break;
						ans+=nd[nnow].v;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
}
int main(){
	StarRail::main();
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
