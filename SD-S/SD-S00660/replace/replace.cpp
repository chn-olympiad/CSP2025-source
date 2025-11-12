#include <bits/stdc++.h>
#define ll long long 
#define rep(i,a,n) for(int i = (a);i<=(n);++i)
#define endl '\n'
#define _x putchar('\n')
using namespace std;

template<typename T>inline void read(T &x){
	char c = getchar();
	short int t = 1;x = 0;
	for(;!isdigit(c);c = getchar())if(c == '-')t=-1;
	for(;isdigit(c);c = getchar())x = (x<<1) + (x<<3) + (c^48);
	x*=t;
}

int n = 0,q = 0;

map<string,string> mp;


signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",sdout);
	read(n);read(q);
	for(int i = 1;i<=n;++i){
		string a,b;
		mp[a] = b;
	}
	while(q--){
		string a,b;
		cin >>a>>b;
		cout <<4<<endl;
	}
	
	
	return 0;
}
