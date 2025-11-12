#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n;cin >>n;
	vector<int>a(n);
	long long sum = 0;
	long long max = 0;
	for(int i = 0;i <n;i++) {
		cin >>a[i];
		sum += a[i];
		if(a[i] > max)max = a[i];
	}
	if(n <= 3){
		if(n <3){
			cout << 0;
			return 0;
		}
		else {
			if(sum > 2*max){
				cout <<1;
				return 0;
			}
			else{
				cout << 0;
				return 0;
			} 
		}
	}
	cout << 0;
	return 0;
} 
