#include<iostream>
#include<cstdio>
//#define int long long
#define re register
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}return x*f;}
inline void write(int x){if(x<0){x=-x;putchar('-');}if(x<=9){putchar(x+'0');return;}write(x/10);putchar(x%10+'0');}
int n,m;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),m=read();
	while(m--){
		printf("0\n");
	}
	return 0;
}

