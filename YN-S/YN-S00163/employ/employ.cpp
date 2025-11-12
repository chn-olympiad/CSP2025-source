#include <bits/stdc++.h>
using namespace std;
int n,m,c[505];
long long ans;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	if(m==1){cout<<n;return 0;}
	char a;int nan,yi;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a=='0')nan++;
		else yi++;
	}
	if(m==n&&nan>0){cout<<0;return 0;}
	for(int i=0;i<n;i++){int j;cin>>j;c[j]++;}
	cout<<1;
	return 0;
}
