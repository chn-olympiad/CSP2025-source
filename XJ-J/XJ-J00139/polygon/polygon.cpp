#include<bits/stdc++.h>
using namespace std;
int a[500100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<(1ll*((n*114514)%998244353*1919810)%998244353);
	return 0;
} 
