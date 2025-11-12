#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=2e6+5;
int n,k,a[N],sum[N],ans,x,f[N],flag,num[M];
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
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(); k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	memset(f,-1,sizeof f);
	memset(num,-1,sizeof num);
	num[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		f[i]=num[sum[i]^k];
		num[sum[i]]=i;
	}
	x=0;
	for(int i=1;i<=n;i++){
		if(f[i]>=x){
			ans++;
			x=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*#Shang4Shan3Ruo6Shui4*/
