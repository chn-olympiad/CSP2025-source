#include <bits/stdc++.h>
#define ss second
#define ff first
using namespace std;
//#define int long long
int read() {
	char c;int t=1;
	while(1) {
		c=getchar();
		if(c>='0'&&c<='9') break ; 
	}
	int s=c-'0';
	while(1) {
		c=getchar() ;
		if(c<'0'||c>'9') break ;
		s=s*10+c-'0';
	}
	return s ;
}
int n,q ;
string s[200005][2] ;
int t[2][2700005][26] ;
int id[1000005],toi;
int tot[2] ;
map<pair<int,int>,int> mp ;
//struct AC {
//	vector<string> s ;
//	vector<int> t[26] ;
//	void ins() {
//		int sum=0,tot=0 ;
//		for(int i=0;i<s.size();i++) sum+=s[i].size() ;
//		for(int i=0;i<26;i++) {
//			t[i].resize(sum+5) ;
//			for(int j=0;j<t[i].size();j++) t[i][j]=0 ;
//		} 
//		for(int i=0;i<s.size();i++) {
//			int p=1 ;
//			for(int j=0;j<s[i].size();j++) {
//				int x=s[i][j]-'a' ;
//				if(!t[x][p]) t[x][p]=++tot; 
//				p=t[x][p] ;
//			}
//		}
//	}
//}ac[200005];
vector<pair<string,int> > g[200005] ;
void work() {
	cin>>n>>q ;
	for(int i=1;i<=n;i++) {
		cin>>s[i][0]>>s[i][1] ;
		int len=s[i][0].size() ;
		int l=0,r=s[i][0].size()-1 ;
		while(l<s[i][0].size()&&s[i][0][l]==s[i][1][l]) l++ ;
		while(r>=0&&s[i][0][r]==s[i][1][r])r-- ;
		if(l>r) continue ;
		string now="" ;
		string zj1="",zj0="" ;
		for(int j=0;j<s[i][0].size();j++) {
			if(j<l||j>r) now+=s[i][0][j] ;
			else {
				zj0+=s[i][0][j] ;
				zj1+=s[i][1][j] ;
			}
		} 
		int p=0 ;
		for(int j=0;j<zj0.size();j++) {
			int x=zj0[j]-'a' ;
			if(!t[0][p][x]) t[0][p][x]=++tot[0] ;
			p=t[0][p][x] ;
		}
		int p1=0 ;
		for(int j=0;j<zj1.size();j++) {
			int x=zj1[j]-'a' ;
			if(!t[1][p1][x]) t[1][p1][x]=++tot[1] ;
			p1=t[1][p1][x] ;
		}
		if(!mp[{p,p1}]) mp[{p,p1}]=++toi ;
		id[i]=mp[{p,p1}] ;
		g[id[i]].push_back({now,l}) ;
//		cout<<i<<' '<<now<<' '<<zj0<<' '<<zj1<<' '<<p<<' '<<p1<<' '<<toi<<' '<<mp[{p,p1}]<<endl;
	}
	while(q--) {
		string t1,t2 ;
		cin>>t1>>t2 ;
		int l=0,r=t1.size()-1 ;
		while(l<t1.size()&&t1[l]==t2[l]) l++ ;
		while(r>=0&&t1[r]==t2[r])r-- ;
		string zj1="",zj0="",now="" ;
		for(int j=0;j<t1.size();j++) {
			if(j<l||j>r) now+=t1[j] ;
			else {
				zj0+=t1[j] ;
				zj1+=t2[j] ;
			}
		} 
		int p=0,flag=1 ;
		for(int j=0;j<zj0.size();j++) {
			int x=zj0[j]-'a' ;
			if(!t[0][p][x]) {
				flag=0 ;
				break ;
			}
			p=t[0][p][x] ;
		}
		int p1=0 ;
		for(int j=0;j<zj1.size()&&flag;j++) {
			int x=zj1[j]-'a' ;
			if(!t[1][p1][x]) {
				flag=0 ;
				break ;
			}
			p1=t[1][p1][x] ;
		}
		if(mp.find({p,p1})==mp.end()) flag=0 ;
		if(!flag) {
			printf("0\n") ;
			continue ;
		}
		int nid=mp[{p,p1}] ;
		int ans=0 ;
//		cout<<g[nid].size()<<endl;
		for(int i=0;i<g[nid].size();i++) {
			int flag=1 ;
			if(g[nid][i].ss>l) flag=0 ;
			else {
				for(int j=0;j<g[nid][i].ss&&flag;j++) {
					if(g[nid][i].ff[j]!=t1[l-(g[nid][i].ss-j)]) flag=0 ;
				}
			}
			if(g[nid][i].ff.size()-(g[nid][i].ss)>t1.size()-r-1) flag=0;
			else {
				for(int j=g[nid][i].ss;j<g[nid][i].ff.size()&&flag;j++) {
					if(g[nid][i].ff[j]!=t1[r+(j-g[nid][i].ss+1)]) flag=0 ;
				}
			}
			if(flag) ans++ ;
		}
		printf("%d\n",ans) ;
	}
}
signed main() {
	freopen("replace.in","r",stdin) ;
	freopen("replace.out","w",stdout) ;
//cin>>TT ;
int TT=1 ;
while(TT--) {work() ;}
	
	
	return 0 ;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
