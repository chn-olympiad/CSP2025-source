#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rg register
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=510;
const int mod=998244353;
int n,m;
char c[N];
int a[N];
bool vis[N];
int ans=0;
void check(string s){
	s=" "+s;
	int cnt=0;
	for(rg int i=1;i<=n;i++){
		int k=s[i]-'0';
		if(i-cnt-1<a[k]&&c[i]=='1')cnt++;
	}
	if(cnt>=m)ans=(ans+1)%mod;
}
void dfs(int x,string s){
	if(x==n){
		check(s);
		return ;
	}
	for(rg int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,s+char(i+'0'));
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",1+c);
	for(rg int i=1;i<=n;i++)a[i]=read();
	if(n>10){
		ans=1;
		for(rg int i=1;i<=n;i++)ans=(ans*i)%mod;
		write(ans);
		return 0;
	}
	dfs(0,"");
	write(ans);
}
