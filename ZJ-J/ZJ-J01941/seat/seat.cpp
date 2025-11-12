#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=1,x,y,o,a;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();a=read();
	for(int i=2;i<=n*m;i++){
		o=read();
		if(o>a)ans++;
	}
	y=(ans-1)/n+1;
	if((ans-1)/n%2==0)x=(ans-1)%n+1;
	else x=n-(ans-1)%n;
	cout<<y<<' '<<x;
	return 0;
}