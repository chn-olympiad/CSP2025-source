#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while (ch<'0' || '9'<ch){
		if (ch=='-') f*=-1;
		ch=getchar();
	}
	while ('0'<=ch && ch<='9'){
		x=(x*10+ch-'0');
		ch=getchar();
	}
	return f*x;
}
int n,m,ans,tme=1;
char s[505];
int c[505],d[505],tot;
int p[3628805][11];
int fac[505];
bool vis[505];
bool flag=true;
void dfs(int cur){
	if (cur==n){
		tot++;
		return;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			vis[i]=true;
			p[tot][cur+1]=i;
			dfs(cur+1);
			vis[i]=false;
		}
	return;
}
void init(){
	fac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=(fac[i-1]*i)%mod;
	return;
}
bool upd(){
	tme++;
	if (tme>fac[n]) return false;
	for (int i=1;i<=n;i++)
		d[i]=p[tme][i];
	return true;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	init();
	int tmp=n;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		if (s[i]!='1')
			flag=false;
	}
	for (int i=1;i<=n;i++){
		c[i]=read();
		if (c[i]==0)
			tmp--;
	}
	if (flag) cout<<fac[tmp]%mod;
	else{
		dfs(0);
		for (int i=1;i<=n;i++)
			d[i]=i;
		do{
			//cout<<"P:";
			//for (int i=1;i<=n;i++)
				//cout<<d[i]<<' ';
			//cout<<'\n';
			int res=0,tmp=0;
			for (int i=1;i<=n;i++){
				//cout<<"ev:"<<s[i]<<' '<<tmp<<' '<<c[d[i]]<<'\n';
				if (s[i]=='0' || tmp>=c[d[i]])
					tmp++;
				else res++;
			}
			if (res>=m){
				//cout<<"OK\n";
				ans++;
			}
		}while(upd()); 
		cout<<ans;
	}
	return 0;
}
/*
3 2 
101 
1 1 2 
*/
