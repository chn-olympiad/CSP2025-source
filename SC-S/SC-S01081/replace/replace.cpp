#include<bits/stdc++.h>
using namespace std;
#ifdef __unix
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
inline void Write(char c){pc(c);}
inline void Write(const char *a){
	for(int i=0;a[i];++i) pc(a[i]);
}
template<typename T>
void Write(T x){
	if(x<0) pc('-'),x=-x;
	if(x<10) return pc(x^48),void(0);
	Write(x/10),pc((x%10)^48);
}
inline int write(){return 0;}
template<typename A,typename ...B>
int write(A x,B...y){
	Write(x);
	return write(y...)+1;
}
#define int long long
//#define NoFreopen
#define N 200010
unordered_map<string,string>mp;
string a,b;
int n,m,ans;
signed main(){
	#ifndef NoFreopen
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		mp[a]=b;
	}
	while(m--){
		cin>>a>>b;
		if(a.size()^b.size()){
			puts("0");
			continue;
		}
		int siz=a.size(),l(0),ll(0),r(0);
		for(int i=0;i<siz;++i){
			if(a[i]^b[i]){
				ll=l=i;break;
			}
		}
		for(int i=l;i<siz;++i){
			if(a[i]==b[i]){
				r=i-1;
				break;
			}
		}
		if(!r) r=siz-1;
		string ss(a.begin()+l,a.begin()+r+1),bb(b.begin()+l,b.begin()+r+1),sss,bbb;
		ans=0;
		for(;r<siz;++r){
			sss=ss,bbb=bb;
			l=ll;
			for(;~l;--l){
				if(mp.count(sss)&&mp[sss]==bbb) ++ans;
				if(l) sss=a[l-1]+sss,bbb=b[l-1]+bbb;
			}
			if(r<siz-1) ss+=a[r+1],bb+=b[r+1];
		}
		write(ans,'\n');
	}
	return 0;
}
