#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[100000];
int c[1000000];
long long w[10000000];

int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,a+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	w[1]=1;
	for(int i=2;i<=n+1;i++){
		w[i]=w[i-1]*i;
	}
	printf("%lld",w[n]%998244353);
	return 0;
} 
