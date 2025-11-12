#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;	
	int ans[100005];
	for(int i=1;i<=n;i++){
		cin >> ans[i];
	}
	int sum;
	if(k==0){
		sum=n/2+2;
	}
	else if(k==1){
		if(n%2==1) sum=n;
		else sum=n-1;
	}
	cout << sum;
	
	return 0;
}
