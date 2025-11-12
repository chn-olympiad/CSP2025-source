#include<bits/stdc++.h>
using namespace std;
const int maxn=505,MOD=998244353;
int n,m;
int s[maxn],c[maxn];
int main() {
	freopen("employ.in","r",stdout);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>s[i];
	}
	for(int i=1; i<=n; ++i) {
		cin>>c[i];
	}
	int summ=1,sumn=1,sum=1;
	for(int i=1; i<=n; ++i) {
		sumn=sumn*i%MOD;
		if(i==m) summ=sumn;
		if(i==n-m) sum=sumn; 
	}
	cout<<sumn/summ/sum%MOD;
	return 0;
}