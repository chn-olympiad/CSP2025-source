#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
inline int qread(){
	#define qr qread()
	int x=0,c=getchar(),t=1;
	while(c<'0'||c>'9'){
		t^=(c=='-');
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return (t?x:-x);
}
inline void qwrite(int x){
	#define qw(_) qwrite(_)
	#define qws(_) qw(_),putchar(' ')
	#define qwe(_) qw(_),putchar('\n')
	if(x<0) putchar('-'),x=-x;
	if(x>9) qw(x/10);
	putchar(x%10+'0');
	return;
}
string s;
int a[N],f[N],p[N],n,m;
bool vis[N];
inline int check(){
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=(a[p[i]]>i-f[i]&&f[i]>f[i-1]);
	return (cnt>=m);
}
inline int dfs(int x){
	if(x==n+1) return check();
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[x]=i;
			vis[i]=true;
			ans+=dfs(x+1);
			vis[i]=false;
		}
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=qr;m=qr;
	cin>>s;
	for(int i=0;i<s.size();i++) f[i+1]=s[i]-'0'+f[i];
	for(int i=1;i<=n;i++) a[i]=qr;
	qw(dfs(1));
	return 0;
} 
/*
3 2
101
1 1 2
*/
