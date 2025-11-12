#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,a[maxn],f[maxn];
int pos[2000000],sum[maxn];
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sum[i]=sum[i-1]^a[i];
	}
	memset(pos,-1,sizeof pos);
	int j;pos[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		j=pos[k^sum[i]];
		if(j!=-1)f[i]=max(f[i],f[j]+1);
		pos[sum[i]]=i;
	}
	printf("%d\n",f[n]);
	return 0;
}