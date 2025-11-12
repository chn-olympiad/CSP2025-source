#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],m;
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m+=a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]*2<m){
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
