#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int maxm=5e6+5;
int n,Q;
string s[2][maxn];
struct node{
	string s1,s2,t1,t2;
	int l,r,n;
//	string s1L,s1R,s2L,s2R;
};
vector<node>o[maxm];
inline bool cmp(string t,int i,string s,int j){
	if(i<0||i>=t.size()||j<0||j>=s.size()) return 0;
	return t[i]==s[j];
}
inline string G(){
	string s="";
	char c=getchar();
	for(;c<'a'||c>'z';) c=getchar();
	s+=c;c=getchar();
	for(;c>='a'&&c<='z';) s+=c,c=getchar();
	return s;
}
vector<pair<int,int>>O[2][maxm];
inline void subtask(){
	for(int i=1;i<=n;++i){
		int m=s[0][i].size();
		int l=-1,r;
		for(int j=0;j<m;++j){
			if(s[0][i][j]!=s[1][i][j]){
				if(l==-1) l=j;
				r=j;
			}
		}
		if(l==-1) continue;
		if(s[0][i][l]=='b'){
			O[0][r-l+1].push_back({l-1,m-r-1});
		}
		else{
			O[1][r-l+1].push_back({l-1,m-r-1});
		}
	}
	for(string t[2];Q;--Q){
		t[0]=G();t[1]=G();
		int l=-1,r;int m=t[0].size();
		for(int i=0;i<m;++i){
			if(t[0][i]!=t[1][i]){
				if(l==-1) l=i;
				r=i;
			}
		}
		int o;
		if(t[0][l]=='b') o=0;
		else o=1;
		int res=0;
		for(auto p:O[o][r-l+1]){
			if(l-1>=p.fi&&m-r-1>=p.se) ++res;
		}
		printf("%d\n",res);
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i){
		s[0][i]=G();s[1][i]=G();
	}
	bool A=1;
	for(int i=1;i<=n;++i){
		int m=s[0][i].size();
		int o1=0,o2=0;
		for(int j=0;j<m;++j){
			if(s[0][i][j]=='a') ++o1;
			if(s[0][i][j]=='b') ++o2;
		}
		if(o1!=m-1||o2!=1) A=0;
		o1=0;o2=0;
		for(int j=0;j<m;++j){
			if(s[1][i][j]=='a') ++o1;
			if(s[1][i][j]=='b') ++o2;
		}
		if(o1!=m-1||o2!=1) A=0;
	}
	if(A){
		subtask();
		return 0;
	}
	for(int i=1;i<=n;++i){
		int m=s[0][i].size();
		int l=-1,r;
		for(int j=0;j<m;++j){
			if(s[0][i][j]!=s[1][i][j]){
				if(l==-1) l=j;
				r=j;
			}
		}
		if(l==-1) continue;
		string t1="",t2="";
		for(int j=l;j<=r;++j){
			t1+=s[0][i][j];
		}
		for(int j=l;j<=r;++j){
			t2+=s[1][i][j];
		}
		o[r-l+1].push_back((node){s[0][i],s[1][i],t1,t2,l,r,m});
	}
	for(string t[2];Q;--Q){
		t[0]=G();t[1]=G();
		int l=-1,r;int m=t[0].size();
		for(int i=0;i<m;++i){
			if(t[0][i]!=t[1][i]){
				if(l==-1) l=i;
				r=i;
			}
		}
		string u1="",u2="";
		for(int i=l;i<=r;++i){
			u1+=t[0][i];u2+=t[1][i];
		}
		int res=0;
		for(auto p:o[r-l+1]){
			if(p.t1!=u1||p.t2!=u2) continue;
			string s1=p.s1,s2=p.s2;
			int L=p.l,R=p.r,n=p.n;
			if(0-L+l<0) continue;
			if(n-1-R+r>=m) continue;
			bool fl=0;
			for(int i=0;i<L;++i){
				if(!cmp(t[0],i-L+l,s1,i)){
					fl=1;break;
				}
			}
			if(fl) continue;
			for(int i=R+1;i<n;++i){
				if(!cmp(t[0],i-R+r,s1,i)){
					fl=1;break;
				}
			}
			if(fl) continue;
			++res;
		}
		printf("%d\n",res);
	}
	return 0;
}
/*
I will AFO on 2025.11.29.
Goodbye,OI.
SuperCowHorse
*/