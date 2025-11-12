#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;
}
int n,m,c[505],ans,qzh[505];
string s;
bool b[505];
inline void dfs(int x,int y){
	if(x==n+1){
		ans+=(y==m);
		return;
	}
	if(y>m) return;
	for(int i=1;i<=n;++i) if(!b[i]){
		b[i]=1;
		if(c[i]>qzh[x-1]&&s[x]=='1') dfs(x+1,y+1);
		else dfs(x+1,y);
		b[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;s=" "+s;
	for(int i=1;i<=n;++i) qzh[i]=qzh[i-1]+(s[i]=='0');
	for(int i=1;i<=n;++i) c[i]=read();
	sort(c+1,c+1+n);
	dfs(1,0);
	cout<<ans;
	return 0;
}
