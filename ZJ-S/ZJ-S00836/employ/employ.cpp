#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i<=n;i++)	sum = sum*i%998244353;
	cout << sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
