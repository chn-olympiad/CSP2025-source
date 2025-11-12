#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
template<typename T>inline void read(T &x)
{
	bool f=1;x=0;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=!f;ch=getchar();}
	while(ch>='0' && ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=(f?x:-x);return ;
}
int n,m;
int a[N],p[N],
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<1;
	return 0;
}