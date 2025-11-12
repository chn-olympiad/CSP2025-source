#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<unordered_map>
#define For(a,b,c) for(int a=b;a<=c;++a)
using namespace std; const int N=2e5+8,LEN=5e6+8;
struct Rep{string a,b;}s[N];
bool operator<(Rep x,Rep y){return x.a!=y.a?x.a<y.a:x.b<y.b;}
bool operator==(Rep x,Rep y){return x.a==y.a&&x.b==y.b;}
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q; cin>>n>>q;
	For(i,1,n){
		string a,b; cin>>a>>b; //const int sz=a.size(); int s1=0,s2=0,s3=0;
		s[i]={a,b};
//		while(s1<sz&&a[s1]==b[s1]) ++s1;
//		while(s1+s2<sz&&a[s1+s2]!=b[s1+s2]) ++s2;
//		s3=sz-s1-s2;
//		rep[s2].push_back({a,b,s1,s3});
//		cout<<s1<<", "<<s2<<", "<<s3<<"\n";
	}
//	sort(s+1,s+1+n); const int un=unique(s+1,s+1+n)-s-1-n;
	For(i,1,q){
		string a,b; cin>>a>>b; const int sz=a.size();
		int ans=0;
		vector<int>v;
		int s1=0,s3=a.size()-1;
		while(s1<sz&&a[s1]==b[s1]) ++s1;
		while(s3>s1&&a[s3]==b[s3]) --s3;
		int s2=s3-s1+1;
		For(i,1,n){
			const int sz=s[i].a.size(),ed=a.size()-sz;
			if(sz>=s2){
				For(j,0,ed) if(a.substr(j,sz)==s[i].a) v.push_back(j);
				for(int p:v) if(b.substr(p,sz)==s[i].b){++ans; break;}
				v.clear();
			}
		}
		cout<<ans<<"\n";
	}
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
