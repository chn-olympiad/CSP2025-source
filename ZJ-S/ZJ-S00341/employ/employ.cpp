#include<bits/stdc++.h>
#define int long long
#define debug printf("!!!\n")
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-') f=-1;
	}
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(int x,char c){
	write(x);putchar(c);
}
const int N=1e5+5,mod=998244353;
int n,m,c[N],p[N],ans;
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=read(),p[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=c[p[i]]){
				cnt++;continue;
			}
		}
		if(n-cnt>=m) ans=(ans+1)%mod;
	}
	while(next_permutation(p+1,p+1+n));
	write(ans,'\n');
	return 0;
}
/*
3 2
101
1 1 2
*/
