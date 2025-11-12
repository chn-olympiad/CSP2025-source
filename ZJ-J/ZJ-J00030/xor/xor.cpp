#include<bits/stdc++.h>
using namespace std;
//bool h1;
long long sum[500010],a[500010],n,k,f[6010][6010];
//bool h2;
template<typename tp>void read(tp &x){
	x=0;
	bool f=1;char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())(ch==45)&&(f=0);
	for(;ch>=48&&ch<=57;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	x=(f?x:-x);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	printf("%fMB",abs(&h1-&h2)/1024.0/1024.0);
	read(n),read(k);
	for(int i=1;i<=n;i++){
		read(a[i]);
		sum[i]=sum[i-1]^a[i];
		f[i][i]=(a[i]==k);
	}
	for(int j=2;j<=n;j++){
		for(int i=j-1;i>=1;i--){
			if((sum[j]^sum[i-1])==k)f[i][j]=1;
			for(int k=i;k<j;k++){
				f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}