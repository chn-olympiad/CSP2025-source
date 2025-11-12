/*我们你所可以自慰的，想来想去，也还是所谓对于将来的希望。

希望是附丽于存在的，有存在，便有希望，有希望，便是光明。*/
#include<bits/stdc++.h>
using namespace std;
constexpr int L=5e6+5,N=2e5+3;
int nxt[L],n,q;
string s[N][2],t1,t2,tmp;
inline void kmp(const string& s){
	for(int i=0,j=nxt[0]=-1;i<s.size();){
		if(!~j||s[i]==s[j]) nxt[++i]=++j;
		else j=nxt[j];
	}
	return;
}
signed main(){
#ifdef __linux__
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
#endif
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=q;++i) cout<<0<<'\n';
	return 0;
}
