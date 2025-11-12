#include<bits/stdc++.h>
using namespace std;
inline long long _(){
	long long f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return f*x;
}
inline void __(long long x,int opt){
	int top=0;
	char st[85];
	if(x<0)putchar('-'),x=-x;
	do{
		st[++top]=x%10;x/=10;
	}while(x);
	for(int i=top;i>=1;i--)putchar(st[i]+'0');
	if(opt==0)return;
	if(opt==1)putchar(' ');
	else putchar('\n');
}
int n,m;
char ch[505];
int c[505];
int f[300005][20];
const int mod=998244353;
void _20pts(){
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int siz=__builtin_popcount(i);
		for(int j=0;j<=siz;j++){
			int g=siz-j;
			for(int x=0;x<n;x++){
				if(i&(1<<x))continue;
				if(g>=c[x+1]||ch[siz+1]=='0')f[i|(1<<x)][j]=(f[i|(1<<x)][j]+f[i][j])%mod;
				else f[i|(1<<x)][j+1]=(f[i|(1<<x)][j+1]+f[i][j])%mod;
			}
	//		cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
		}
	}
	long long ans=0;
	for(int i=m;i<=n;i++)ans=(ans+f[(1<<n)-1][i])%mod;
	__(ans,2);
}
bool check40(){
	for(int i=1;i<=n;i++)if(ch[i]=='0')return 0;
	return 1;
}
void _40pts(){
	long long ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	__(ans,2);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=_();m=_();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++)c[i]=_();
	if(n<=18){
		_20pts();
		return 0;
	}
	else if(check40()){
		_40pts();
		return 0;
	}
}
