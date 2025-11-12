#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a;
		cin>>b;
	}
	int o=1;
	for(int i=m;i<=n;i++){
		o*=i*(i-m+1);
	}
	cout<<o;

	return 0;
}