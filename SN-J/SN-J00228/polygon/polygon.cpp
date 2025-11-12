#include <bits/stdc++.h>

using namespace std;

const int mod=998244353;
int n,a[1010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ma=max({a[1],a[2],a[3]})*2;
	int sum=a[1]+a[2]+a[3];
	if(sum>ma)
		printf("1");
	else
		printf("0");
}
