#include<bits/stdc++.h>
#define long long
using namespace std;
int a[5001],f[5001];
bool b[5001];
int n,z=0,k=0;
int qpl(int s,int m){
	for(int i=1;i<=s;i++){
		if(b[i]==true) continue;
		z+=a[i];
		if(z>m) k++;
		b[i]=true;
		qpl(s,m);
		b[i]=false;
		z=0;
	}
	return k;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=5000;i++){
		b[i]=false;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if((a[1]+a[2]+a[3])>2*a[3]) f[3]=1;
	else f[3]=0;
	if(n==3){
		printf("%d",f[3]);
		return 0;
	}
	for(int i=4;i<=n;i++){
		f[i]=f[i-1]+qpl(i-1,a[i]);
		k=0;
		z=0;
	}
	printf("%d",f[n]%998244353);
	return 0;
}
