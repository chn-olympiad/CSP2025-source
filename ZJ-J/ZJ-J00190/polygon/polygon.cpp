#include<bits/stdc++.h>
using namespace std;
int a[5005];
int f[500005];
int getint(){
	int res=0;
	char ch;
	ch=getchar();
	while (!isdigit(ch))ch=getchar();
	while (isdigit(ch)){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	n=getint();
	int sum=0;
	for (int i=1;i<=n;i++){
		a[i]=getint();
	}
	sort(a+1,a+n+1);
	int m=0;
	f[0]=1;
	int z=0;
	for (int i=1;i<n;i++){
		m+=a[i];
		for (int j=m;j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%mod;
			if (j<=a[i+1]||i==1)continue;
			z+=f[j];
			z%=mod;
		}
	}
	printf("%d\n",z);
	return 0;
}
