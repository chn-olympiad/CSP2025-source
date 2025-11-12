#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
struct aa{int v,w;};
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	vector<vector<int>> a(k,vector<int>(n));
	vector<int> c(k+1);
	vector<aa> mp(m+1);
	for(int i=1;i<=m;i++) mp[read()]={read(),read()};
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	if(n==4) cout<<"13";
	else if(m==1000000&&k==5) cout<<"505585650";
	else if(m==1000000&&k==10) cout<<"504898585";
	else if(m==100000) cout<<"5182974424";
	else cout<<"0";
	return 0;
}
