//T4
//8:32 idea
//8:38 AC
//8:43 check
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,TT=998244353;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,V;
int a[N];
int f[N];
int ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),V=max(V,a[i]);
	V++;sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		//calc
		for(int j=a[i]+1;j<=V;j++)ans=(ans+f[j])%TT;
		//add
		for(int j=V;j>=0;j--){
			if(j+a[i]>=V)f[V]=(f[V]+f[j])%TT;
			else f[j+a[i]]=(f[j+a[i]]+f[j])%TT;
		}
	}
	write(ans);
	return 0;
}