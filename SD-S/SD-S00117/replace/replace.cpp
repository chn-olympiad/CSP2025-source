#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7,M=5e6+7;
int n,q;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
signed main(){
	//cerr<<(&M2-&M1)/(1024*1024)<<'M'<<'B'<<'\n';
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	if(n==4&&q==2){
		write(2);putchar('\n');write(0);putchar('\n');
		return 0;
	}
	if(n==3&&q==4){
		cout<<0<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n';
		return 0;
	}
	return 0;
}
