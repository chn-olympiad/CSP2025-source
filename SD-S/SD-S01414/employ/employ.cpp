#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
void read(T &x){x=0;ll f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}x*=f;}
template <typename T,typename ...Args>
void read(T &x,Args &...args){read(x);read(args...);}
template <typename T>
void write(T x){if(x<0){x=-x;putchar('-');}if(x>9)write(x/10);putchar(x%10+48);}
template <typename T,typename ...Args>
void write(T x,Args ...args){write(x);if(sizeof...(args)){putchar(' ');write(args...);}}
const ll N=500+5,M=3e6+5,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;
ll n,m,k;
ll jc[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<ksm(2,10);
	jc[1]=1;
	for(int i=2;i<=n;i++)jc[i]=jc[i-1]*i%mod;
	ll a,b;
	read(a,b);
	cout<<jc[b];
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


4 3 1
1 2 999
1 3 1
3 4 10
10 1 1 9999 9
*/

