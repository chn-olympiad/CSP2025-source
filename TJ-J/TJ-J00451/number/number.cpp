#include<iostream>
#include<fstream>
#include<string>
using namespace std;//49 = 1,48 = 0
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	long long b[10];
	for(int i = 0;i < 10;i++){
		b[i] = 0;
	}
	long long sum = 0;
	for(long long i = 0;i < a.size();i++){
		if(a[i] >= 48 && a[i] <= 57){
			b[a[i] - 48]++;
			sum++;
		}
	}
	int* c = new int[sum];
	long long p = 0;
	for(int i = 9;i >= 0;i--){
		for(long long j = 0;j < b[i];j++){
			c[p] = i;
			p++;
		}
	}
	for(long long i = 0;i < sum;i++){
		cout << c[i];
	}
	return 0;
}
