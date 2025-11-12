#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(k==0){
		cout<<n<<endl;
		return 0;
	} 
	int sum1=0,sum0=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		if(a==1) sum1++;
		if(a==0) sum0++;
	}
	if(k==1) {
		cout<<max(sum1,sum0);
		return 0;
	}
	cout<<1;
	return 0; 
} 
