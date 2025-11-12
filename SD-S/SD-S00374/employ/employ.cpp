#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	int a[m+3];
	cin>>s;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	long long sum=1;
	for(int i=n;i>1;i--){
		sum=(sum*i)%998244353;
	}
	cout<<sum;
	return 0;
}
