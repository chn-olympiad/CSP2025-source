#include<iostream>
#include<cstdio>

using namespace std;

const int MOD=998244353;

int jc(int x){
	long long f=1;
	for(int i=2;i<=x;i++){
		f=f*i%MOD;
		f%=MOD;
	}
	return f;
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d",jc(n));
	
	return 0;
}

//0pts.
//So I gave it up.
