#include<bits/stdc++.h>
const int Mod=998244353;
using namespace std;
int n,m;
long long A(int x){
	long long  res=1;
	for(long long  i=1;i<=n;i++){
		res=res*i;
		res=res%Mod;
	}
	return res%Mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	printf("%lld",A(n));
}
