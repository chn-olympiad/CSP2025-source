#include <bits/stdc++.h>
using namespace std;

namespace quick_io{
	template<typename T>
	void input(T &x){
		x=0;
		bool f=0;
		char ch=' ';
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=1;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
		if(f) x=-x;
	}

	template<typename T>
	void print(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>10) print(x/10);
		putchar(x%10+'0');
	}
}
using namespace quick_io;
#define int long long
const int N=20;
const int mod=998244353;
int n,m;
int cnt[1<<N];
int f[1<<N][N];

string s;
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	input(n);
	input(m);
	cin>>s;
	for(int i=0;i<n;i++) input(c[i]);
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				cnt[i]++;
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			if(!(i&(1<<j)))
				for(int k=0;k<=n;k++)
					f[i|(1<<j)][k+(s[cnt[i]]=='1'&&k<c[j])]=(f[i|(1<<j)][k+(s[cnt[i]]=='1'&&k<c[j])]+f[i][k])%mod;
//	for(int i=0;i<(1<<n);i++){
//		for(int j=0;j<=m;j++) cout<<f[i][j]<<" ";
//		cout<<endl;
//	}
	int ans=0;
	for(int i=m;i<=n;i++) ans=(ans+f[(1<<n)-1][i])%mod;
	print(ans);
}
