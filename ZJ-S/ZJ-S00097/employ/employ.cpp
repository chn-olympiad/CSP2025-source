#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
string ip;
int ipp;
int zcnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d", &n, &m);
	cin>>ip;
	for (int i = 1;i <= n;i ++){
		scanf("%d", &ipp);
	}
	ans = 1;
	for (int i = 2;i <= n;i ++){
		ans = ans * i % 998244353;
	}
	printf("%d", ans);
	return 0;
}


