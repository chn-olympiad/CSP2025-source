#include<bits/stdc++.h>
using namespace std;
int n,m;
long long cnt = 1;
int c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin >> s;
	for(int i = 1;i <= n;i++){
		scanf("%d",&c[i]);
	}
	for(int i = n;i >= 1;i++){
		cnt = cnt * i;
	}
	printf("%lld",cnt);
	return 0;
}
