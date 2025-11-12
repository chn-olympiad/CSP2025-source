#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
inline ll read(){
	ll x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(int)(c-'0');
		c=getchar();
	}
	return x*w;
}
inline void print(ll x){
	char s[20];
	int top=0;
	if(x==0){
		putchar('0');
		return ;
	}
	if(x<0){
		x=-x;
		putchar('-');
	}
	while(x){
		top++;
		s[top]=(char)(x%10+'0');
		x/=10;
	}
	while(top){
		putchar(s[top]);
		top--;
	}
}
inline ll fac(int x){
	int res=1;
	for(int i=2;i<=x;i++){
		res=(res*i)%mod;
	}
	return res;
}
inline ll C(int n,int m){
	return(fac(n)/(fac(m)*fac(n-m)));
}
int n,m;
bool s[505];
int c[505],fl;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		char cc;
		cc=getchar();
		s[i]=(int)(cc-'0');
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(c[i]==0)fl++;
	}
	if(fl)print(C(n,m));
	else{
		print(C(n-fl,m));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

