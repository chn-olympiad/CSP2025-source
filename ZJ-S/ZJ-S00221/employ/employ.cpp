#include<bits/stdc++.h>
using namespace std;
long long jc(int n){
	int temp=1;
	for(int i=1;i<=n;i++){
		temp*=n;temp/=998244353;
	}
	return temp;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	cout<<jc(n);
	return 0;
}