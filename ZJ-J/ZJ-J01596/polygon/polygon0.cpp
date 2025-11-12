//checker
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,TT=998244353;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,V;
int a[N];
int f[N];
int b[N];
int ans;
void dfs(int x){
	if(x==n+1){
		int sum=0,maxi=0;
		for(int i=1;i<=n;i++)if(b[i]==1)sum+=a[i],maxi=max(maxi,a[i]);
		if(sum>2*maxi)ans++;
		return;
	}
	b[x]=0;dfs(x+1);
	b[x]=1;dfs(x+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon0.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	dfs(1);
	write(ans);
	return 0;
}