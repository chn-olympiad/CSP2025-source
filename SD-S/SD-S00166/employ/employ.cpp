#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("employ.in","w",stdin);
	freopen("employ.out","r",stdout);
	scanf("%d",&n);
	int sum = 1;
	for (int i = n ; i >= 2 ; i--) sum = (sum*i)%998244353;
	printf("%d",sum);
	return 0;
}
