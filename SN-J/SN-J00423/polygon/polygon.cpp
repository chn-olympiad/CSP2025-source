#include <bits/stdc++.h>
using namespace std;
long long dengcha(int n){
	long long num;
	num=(1+n)*n/2;
	return num;
}
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	int n;
	int num[5005];
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >> num[i];
	}
	int sum=0;
	if (n==3){
		if(num[1]+num[2]+num[3]>num[3]) sum++;
	} 
	else{
		sum = dengcha(n-2);
	}
	
	cout << sum;
	
	return 0;
}
