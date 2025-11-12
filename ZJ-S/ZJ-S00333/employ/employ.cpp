#include<bits/stdc++.h>
using namespace std;
#define int long long
#define p_ putchar(' ')
#define pn putchar('\n')
void write(int x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int read(){
	int w=1,s=0;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-'){
		w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
const int mod=998244353;
int n,m,s[505],c[505];
string S;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>S;
	int p=1;
	for(int i=1;i<=n;i++){
		s[i]=S[i-1]-'0';
		if(!s[i])p=0;
	}
	if(p){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		write(ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++){
		
	}
}

