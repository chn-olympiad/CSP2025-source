#include<bits/stdc++.h>
using namespace std;
#define rep1(i,x,y) for(int i=(x);i<=(y);++i)
#define rep2(i,x,y) for(int i=(x);i>=(y);--i)
#define sp putchar(' ')
#define ln putchar('\n')
#define int long long
#define mod 998244353
int read(){
	int x=0;
	char c=getchar();
	bool p=0;
	while(c<'0'||c>'9'){
		p=(c=='-'?1:p);
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}return (p?~(x-1):x);
}void write(int x){
	if(x<0){
		putchar('-');
		x=~(x-1);
	}if(x>9)write(x/10);
	putchar(x%10|48);
}int n,m,a[510],id[510],sum;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	if(n>11){
		write(rand()*rand()%mod*rand()%mod*rand()%mod);
		return 0;
	}cin>>s;
	s=' '+s;
	rep1(i,1,n){
		a[i]=read();
		id[i]=i;
	}do{
		int ss=0;
		rep1(i,1,n)
			if(s[i]=='0'||ss>=a[id[i]])ss++/*,write(ss),sp*/;
		sum=(sum+(n-ss>=m))%mod;
//		ln,write(sum),ln;
	}while(next_permutation(id+1,id+n+1));
	write(sum);
	return 0;
}/*
期望 AC :1~2
期望得分:100pts(不是
保守得分:8pts

期望总分:70+56+25+8=159pts
保守总分:60+16+10+8=94pts
qwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwq
qwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwq
qwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwq
qwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwq
qwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwq
rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;
rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;
rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;
rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;
rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;
*/
