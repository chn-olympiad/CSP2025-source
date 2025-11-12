#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n >>m;
	cin >>s;
	for(int i=1;i<=n;i++){
		cin >>c[i];
	}
	int tmp=1;
	for(int i=1;i<=n;i++){
		tmp=tmp*i;
		tmp%=mod;
	}
	cout <<tmp;
	return 0;
}