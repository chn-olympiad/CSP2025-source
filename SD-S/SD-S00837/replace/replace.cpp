#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch = getchar();
	while(ch<'0' || '9'<ch){
		if(ch == '-') f=-1;
		ch = getchar();
	}
	while('0'<=ch && ch<='9'){
		x = (x<<3)+(x<<1)+ch-'0';
		ch = getchar();
	}
	return x*f;
}
typedef long long ll;
const int N=2e5+10;
int n,q;
string str[5][N];
string t1,t2;
ll ans = 0;
map<string,bool> vis;
map<string,string> chg;
inline void work(int l,int r){
	string p = t1;
	for(int i=1;i<=n;i++){
		bool flag = true;
		for(int j=l;j<=r;j++) if(p[j] != str[1][i][j-l]) flag = false;
		if(flag){
			for(int j=l;j<=r;j++) p[j] = str[2][i][j-l];
		}
		if(p == t2) ans++;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read(),q = read();
	for(int i=1;i<=n;i++){
		cin>>str[1][i]>>str[2][i];
		vis[str[1][i]] = true;
		chg[str[1][i]] = str[2][i];
	}
	while(q--){
		ans = 0;
		cin>>t1>>t2;
		int l1 = t1.length();
		for(int i=0;i<l1;i++){
			for(int j=i;j<l1;j++) work(i,j);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

