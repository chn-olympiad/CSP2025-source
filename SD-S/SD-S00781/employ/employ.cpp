#include<iostream>
#include<cstdio>
#define int long long
#define re register
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0){x=-x;putchar('-');}if(x<=9){putchar(x+'0');return;}write(x/10);putchar(x%10+'0');}
int n,m,vis[505]={0},mod=998244353,a[505]={0},ans=0;
string s;
void dfs(int st,int person,int no){
	if(person==m){
		int fac=1,cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]) cnt++;
		}
		for(int i=1;i<=cnt;i++) fac*=i,fac%=mod;
		ans+=fac;
		ans%=mod;
		return;
	}
	if(st>n) return;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		else if(no>=a[i]) continue;
		vis[i]=1;
		if(s[st-1]=='0') dfs(st+1,person,no+1);
		else dfs(st+1,person+1,no);
		vis[i]=0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	dfs(1,0,0);
	write(ans);
	return 0;
}
