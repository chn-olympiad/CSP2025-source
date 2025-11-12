#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb emplace_back
#define mk make_pair
#define int long long
#define fi first
#define se second
#ifdef int
#define inf ((1e18)+10)
#else 
#define inf ((1e9)+10)
#endif
//#define ls (now<<1)
//#define rs (now<<1|1)
//#define mid ((l+r)>>1)
using namespace std;
bool Mst;
const int Max=2e5+10;
const int mod=998244353;
const double eps=1e-9;


inline int read(){
	int res=0,v=1;
	char c=getchar();
	while(c<'0'||c>'9'){v=(c=='-'?-1:1);c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res*v;
}

char c[Max];
int a[Max],p[Max],v[Max];
bool Med;
signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	int n,m;
	n=read();m=read();
	scanf("%s",c+1);
	int flag=0;
	for(int i=1;i<=n;++i){
		if(c[i]=='1')a[i]=1;
		else a[i]=0,flag=1;
	}
	for(int i=1;i<=n;++i)v[i]=read();
	if(n==m){
		for(int j=1;j<=n;++j){
			if(!v[j]){
				cout << "0\n";
				return 0;
			}
		}
		if(flag)cout << "0\n";
		else{
			int ans=1;
			for(int i=1;i<=n;++i){
				ans=ans*i%mod;
			}
			cout << ans << '\n';
		}
	}else{
		for(int i=1;i<=n;++i){
			p[i]=i;
		}
		int ans=0;
		do{
			int num=0,val=0;
			for(int i=1;i<=n;++i){
				if(!a[i]){
					++num;
				}else{
					if(num>=v[p[i]]){
						++num;
					}else ++val;
				}
			}
			if(val>=m){++ans;}
		}while(next_permutation(p+1,p+1+n));
		cout << ans%mod << '\n';
	}
	
	
	cerr << "Time: "<< clock()/1000.0 << "s\n";
	cerr << "Me: "<< abs(&Mst-&Med)/1048576.0 << "MB\n";
	return 0;
}
/*


*/