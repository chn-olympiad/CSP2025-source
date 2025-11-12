#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}
const int MAXN=5e5+5;
int n,k,last;
int a[MAXN],xo[MAXN],f[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	read(n);read(k);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) xo[i]=xo[i-1]^a[i];
	for (int i=1;i<=n;i++){
		f[i]=f[i-1];
		int j;
		bool flag=false;
		for (j=i-1;j>=last;j--){
			int x=xo[i]^xo[j];
			if (x==k){
				flag=true;
				break;
			}
		}
		if (flag){
			f[i]=max(f[i],f[j]+1);
			last=i;
		}
	}
	printf("%d",f[n]);
	return 0;
}
//[60,100]pts?
