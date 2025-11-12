#include <bits/stdc++.h>

using namespace std;

int n,m,c[200020];
string s;

int main(){
	scanf("%d%d",&n,&m);
	cin>>s;
	int sum=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++){
		if(c[i]==0)
			sum++;	
	}
	if(n-sum>=m)
		printf("%lld",n*(n-1)%998244353);
	else
		printf("0");
}
