#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}
const int mod=998244353;
int n,ans;
int a[5005];
int f[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=5000;j++){
			f[i][j]=(f[i-1][j]+f[i-1][max(j-a[i],0)])%mod;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			for (int k=a[i];k>=0;k--) f[j][k]--;
		}
	}
	for (int i=3;i<=n;i++) ans=(ans+f[i-1][a[i]+1])%mod;
	printf("%d",ans);
	return 0;
}

//100pts?
