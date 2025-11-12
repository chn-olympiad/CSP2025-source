#include<bits/stdc++.h>
using namespace std;

ifstream fin("employ.in");
ofstream fout("employ.out");
#define cin fin
#define cout fout

const int N=505;
using i64=long long;
const i64 mod=998244353;

int n,m,f[N][N][N],s[N],c[N],p[N];

signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		char in; cin>>in;
		s[i]=in-'0';
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	for(int i=1;i<=n;++i) p[i]=i;
	int ans=0;
	do {
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(cnt>=c[p[i]]||!s[i]){
				++cnt;
			}
		}
		if(n-cnt>=m) ++ans;
	} while(next_permutation(p+1,p+1+n));
	cout<<ans<<"\n";
}

struct Code{
	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }
	~Code(){ cout.flush(); }
} wtl;