#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//#define int ll
const int N=2e5+5,M=5e6+5,K=12;
template<typename T=int>inline T read(){
	T x=0;bool f=false;char c=getchar();
	while(c<'0'||c>'9') f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return f?-x:x;
}
int n,m,T,res;string a,b;
struct Rep{string a,b;}r[N];
inline bool special(string s){
	int b=0;bool f=true;
	for(char c:s){
		if(c=='b') ++b;
		else if(c!='a') f=false;
	}
	return f&(b==1);
}
inline bool cmp(string s,string t,int p){
	if(p+t.size()>s.size()) return false;
	for(int i=0;i<t.size();++i) if(s[p+i]!=t[i]) return false;
	return true;
}
inline bool check(string s,string t,int p,string r){
	for(int i=0;i<s.size();++i){
		if(i<p||i>p+t.size()-1){
			if(s[i]!=r[i]) return false;
		}
		else{
			if(t[i-p]!=r[i]) return false;
		}
	}
	return true;
}
namespace SUB1_2{
	int res;
	inline int main(){
		res=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<a.size();++j){
				if(!cmp(a,r[i].a,j)) continue;
				if(check(a,r[i].b,j,b)) ++res;
			}
		}
		return res;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	bool B=true;
	n=read(),T=read();
	for(int i=1;i<=n;++i){
		cin>>r[i].a>>r[i].b;
//		B&=(special(r[i].a)&&special(r[i].b));
	}
	while(T--){
		cin>>a>>b;
//		B&=(special(a)&&special(b));
		res=SUB1_2::main();
		printf("%d\n",res);
	} 
	return 0;
}