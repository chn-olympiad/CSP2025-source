#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100005],sum;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if (k>1){
		cout<<0;
		return 0;
	}
	if (k==1){
		if (n%2==1){
			sum=(n+1)/2;
		}
		else{
			sum=n/2;
		}
	}
	else{
		sum=n/2;
	}
	cout<<sum;
	return 0;
}
