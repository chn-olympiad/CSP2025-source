#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
long long sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]+a[2]>a[3]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
