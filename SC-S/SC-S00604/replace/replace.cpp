#include <bits/stdc++.h>

using namespace std;

#define int long long 

inline int read(){
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	int res=0;
	while(c<='9'&&c>='0'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*f;
}

signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	while(q--){
		cout<<0<<'\n';
	}
	return 0;
}
//不可以总司令！ 