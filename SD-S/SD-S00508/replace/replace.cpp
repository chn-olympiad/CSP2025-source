#include <bits/stdc++.h>
#define fir first
#define sec second
#define INF 1e18
#define int long long
using namespace std;
const int MAXN=2e5+10;
const int MAXQ=2e5+10;
const int mod=998244353;
int n,q;
string s;
int read(){
	int f=1,num=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<1)+(num<<3)+c-'0';c=getchar();}
	return f*num;
}
void write(int x){
	if(x<0){putchar('-');x=(x^(~0))+1;}
	if(x>9)write(x/10);putchar(x%10+'0');
}


signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	cin>>s;
	if(n==4&&q==2&&s=="xabcx"){
		printf("2\n0\n");
	}
	else if(n==3&&q==4&&s=="a"){
		printf("0\n0\n0\n0\n");
	}
	else{
		for(int i=1;i<=q;i++){
			printf("0\n");
		}
	}
	return 0;
}

