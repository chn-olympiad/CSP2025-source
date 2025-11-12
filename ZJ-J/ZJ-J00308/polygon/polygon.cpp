#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ri register int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
namespace io{
	inline int r(){
		char chr=getchar();
		int a=1,b=0;
		while(chr>'9'||chr<'0'){if(chr=='-')a=-1;chr=getchar();}
		while(chr<='9'&&chr>='0'){b=(b<<1)+(b<<3)+(chr^48);chr=getchar();}
		return a*b;
	}
	inline void wr(int x){
		if(x==0)return;
		if(x<0){putchar('-');x=-x;}
		wr(x/10);
		putchar((x%10)^48);
	}
	inline char gc(){char C=getchar();while(C<=' ')C=getchar();return C;}
	inline string gs(){
		string S="";char chr=getchar();
		while(chr<=' ')chr=getchar();
		while(chr>' '){S+=chr;chr=getchar();}
		return S;
	}
	inline void ww(int a){if(a==0)putchar('0');else wr(a);putchar(' ');}
	inline void wln(int a){if(a==0)putchar('0');else wr(a);putchar('\n');}
	inline void w(int a){if(a==0)putchar('0');else wr(a);}
}
using namespace io;
const int N=5e3+9,p=998244353;
namespace dino{
	int dp[N];
	int a[N],n;
	inline int mint(int x){
		if(x>=p)return x-p;
		else return x;
	}
	inline void zyt(){
		n=r();for(ri i=1;i<=n;++i)a[i]=r();
		sort(a+1,a+1+n);
		int ans=0,pw2=1;
		dp[0]=1;
		for(ri i=1;i<=n;++i){
			int sum=0;
			for(ri j=0;j<=a[i];++j)sum=mint(sum+dp[j]);
			ans+=(pw2-sum+p);
			ans%=p;
			for(ri j=5000;j>=a[i];--j)dp[j]=mint(dp[j]+dp[j-a[i]]);
			pw2=pw2*2%p;
		}
		wln(ans);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	dino::zyt();
}
