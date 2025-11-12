#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=5e6+2e5+10;
int n,q;
bitset<N> f[30];
bitset<N> g[30];
bitset<N> ansx;
bitset<N> ansy;
string s,t;
int bkx;
int x_size;
int opx;
int l;
int lx,rx;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		x_size=s.size();
		for(int j=1;j<=x_size;j++){
			f[(int)(s[j-1]-'a')][++bkx]=1;
			g[(int)(t[j-1]-'a')][bkx]=1;
		}
		bkx++;
	}
	bkx--;
//	cout<<bkx<<endl;
	while(q--){
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<0<<"\n";
			continue;
		}
		x_size=s.size();
		opx=0;
		for(int j=1;j<=x_size;j++){
			if(s[j-1]!=t[j-1]){
				lx=j;
				break;
			}
		}
		for(int j=x_size;j>=1;j--){
			if(s[j-1]!=t[j-1]){
				rx=j;
				break;
			}
		}
//		cerr<<lx<<" "<<rx<<endl;
		ansx.set();
		ansy.set();
		for(int i=lx;i<=rx;i++){
			ansx=ansx&(f[(int)(s[i-1]-'a')]>>(i-lx));
			ansy=ansy&(g[(int)(t[i-1]-'a')]>>(i-lx));
		}
		ansx=ansx&ansy;
		cout<<ansx.count()<<"\n";
	}
	return 0;
}
