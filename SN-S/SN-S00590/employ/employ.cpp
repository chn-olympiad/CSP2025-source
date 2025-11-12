#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string str;
int c[510],a[510];
int main(){
	freopen("employ.in", "r",stdin);
	freopen("employ.out", "w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",&str);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]); 
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	long long cnt=0;
	do{
		cnt++;
	}while(next_permutation(a+1,a+n+1));
	printf("%ld\n",cnt%mod);
	return 0;
} 
