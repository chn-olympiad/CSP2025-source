#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i = l; i<=r; i++)
#define ROF(i,r,l) for(int i = r; i>=l; i--)
#define all(x) x.begin(),x.end()
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define int long long
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0,f=1;
    while(!isdigit(ch)) {
    	if(ch=='-') f=-1;
    	ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
bool ST;
const int N = 550,mod=998244353;
int c[N],p[N], s[N];
bool ED;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n = read(), m = read();
	char ch; 
	bool fg = 1;
	FOR(i,1,n){
		cin>>ch;
		s[i]=ch-'0';
		fg &= s[i];
	}
	FOR(i,1,n)c[i]=read();
	if(n<=10){
		int ans = 0;
		FOR(i,1,n)p[i]=i;
		do{
			int cnt = 0;
			FOR(i,1,n){
				if(!s[i]||cnt>=c[p[i]]){
					cnt++;
				}
			}
			ans += cnt<=n-m;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n){
		bool f = 0;
		FOR(i,1,n){
			f |= s[i]==0||c[i]==0;
		}
		if(f)cout<<"0\n";
		else{
			int res = 1;
			FOR(i,1,n) res = res*i%mod;
			cout<<res<<"\n";
		}
		return 0;
	} 	
//	cerr << "\nused: " <<abs(&ST-&ED)/1024/1024<<" MB\n";
	return 0;
}



