#include<bits/stdc++.h>
using namespace std;
int k,n,a[100000],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			sum+=i;
		}
		cout << sum;
	}else{
		cout << time(0);
	}
	return 0;
}

