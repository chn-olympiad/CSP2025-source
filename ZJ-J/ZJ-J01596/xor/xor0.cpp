//checker
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
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
int n,k;
int a[N];
int sum[N];
int f[N];
int w(int x,int y){return sum[y]^sum[x-1];}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor0.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			f[i]=max(f[i],f[j-1]+(w(j,i)==k));
		}
	}
	write(f[n]);
	return 0;
}