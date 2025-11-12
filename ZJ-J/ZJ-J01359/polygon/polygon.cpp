#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5,MOD=998244353;
int n,a[N],ans;
inline int read(){
	int t=1,tot=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return tot*t;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) puts("1");
		else puts("0");
		return 0;
	}
	puts("0");
	return 0;
}
/*#Shang4Shan3Ruo6Shui4*/
