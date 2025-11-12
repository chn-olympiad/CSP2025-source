#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,TT=998244353;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m;
string s;
int c[N];
int vis[N];
int p[N];
int ans;
void dfs(int x){
	if(x==n+1){
		int tot=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')tot++;
			else if(c[p[i]]<=tot)tot++;
		}
		tot=n-tot;
		if(tot>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		vis[i]=1;p[x]=i;dfs(x+1);vis[i]=0;
	}
}
int f[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();cin>>s;s=" "+s;
	for(int i=1;i<=n;i++)c[i]=read();
	sort(c+1,c+1+n);
	if(m==n){
		int flg=0;
		for(int i=1;i<=n;i++)if(s[i]=='0')flg=1;
		for(int i=1;i<=n;i++)if(c[i]==0)flg=1;
		if(flg==1){write(0);putchar('\n');exit(0);}
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%TT;
		write(ans);putchar('\n');
		return 0;
	}
	if(m==1){
		f[0]=1;int tot=0,geshu=0,now=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				geshu++;
				while(tot<n && c[tot+1]<i)tot++;
				if(tot<geshu){
					write(0);
					exit(0);
				}
				now=now*(tot-geshu+1)%TT;
			}
		}
		int tmp=now;
		for(int i=1;i<=n-geshu;i++)tmp=tmp*i%TT;
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%TT;
		ans-=tmp;
		ans=(ans%TT+TT)%TT;
		write(ans);putchar('\n');
		return 0;
	}
	if(n<=10){
		dfs(1);
		write(ans);
		return 0;
	}
	write(0);
	return 0;
}