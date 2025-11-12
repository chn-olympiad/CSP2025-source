#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+5;
int arr[N];

bool cmp(int x,int y){
	return x > y;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int xb = 0;
	for(int n = 0; n<a.length(); n++) {
		if(a[n] >= '0' && a[n] <= '9') {
			arr[n] = a[n]-'0';
		}
		if(a[n]-'0' == 0){
			xb++;
		}
	}
	sort(arr,arr+a.length(),cmp);
	for(int n = 0;n<a.length();n++){
		if(arr[n] == 0){
			if(xb >= 1){
				xb--;
				cout << arr[n];
			}
		}else{
			cout << arr[n];
		}
	}
	return 0;
}

