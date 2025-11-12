#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=505,mod=998244353;
int n,m;
string s;
int a[N];
int f[1<<18][20];
bool fl[N];
int ppct(int x){
	int ret=0;
	while(x)ret+=x&1,x>>=1;
	return ret;
}
void add(int &x,int y){
	x=(x+y)%mod;
}
void bl1(){
	f[0][0]=1;
	for(int s=0;s<(1<<n);s++){
		int i=ppct(s);
		for(int j=0;j<=i;j++)
			for(int k=1;k<=n;k++){
				if(s&(1<<(k-1)))continue;
				add(f[s|(1<<(k-1))][j+(fl[i+1]&&i-j<a[k])],f[s][j]);
			}
	}
	int as=0;
	for(int j=m;j<=n;j++)
		add(as,f[(1<<n)-1][j]);
	cout<<as<<"\n";
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		fl[i]=s[i-1]-'0';
	bl1();
	return 0;
}

