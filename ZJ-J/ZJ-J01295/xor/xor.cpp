#include<bits/stdc++.h>

using namespace std;

const int N = 5e6+10;

long long a[N];

int ix[N][2];

int as[30];
int bs[30];
int xor1(int a,int b){
	if(a == 0){
		return b;
	}
	if(b == 0){
		return a;
	}
	if(a == b){
		return 0;
	}
	int i = 30;
	while(a > 0){
		as[i] = a % 2;
		a = (a - as[i]) / 2;
		i--;
	}
	i = 30;
	while(b > 0){
		bs[i] = b % 2;
		b = (b - bs[i]) / 2;
		i--;
	}
	int sum = 0;
	for(int i = 30;i >= 1;i--){
		if(as[i] != bs[i]){
			sum += pow(2,30-i);
		}
	}
	for(int i = 1;i <= 30;i++){
		as[i] = 0;
		bs[i] = 0;
	}
	return sum;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int sum = 0;
	int sumix = 1;
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			int cnt = 0;
			if(i == j){
				cnt = a[i];
			} else {
				cnt = xor1(a[i],a[i+1]);
				for(int h = i+2;h <= j;h++){
					cnt = xor1(cnt,a[h]);
				}
			}
			if(cnt == k){
				sum++;
				ix[sumix][1] = i;
				ix[sumix][2] = j;
				sumix++;
				break;
			}
		}
	}
	for(int i = 1;i < sumix;i++){
		for(int j = i+1;j <= sumix;j++){
			if(ix[i][1] == ix[j][1]){
				sum--;
//				cout << i << " " << j << endl;
			}
			if(ix[i][2] == ix[j][2]){
				sum--;
//				cout << i << " " << j << endl;
			}
			if(ix[i][1] > ix[j][1] && ix[i][2] < ix[j][2] || ix[i][1] < ix[j][1] && ix[i][2] > ix[j][2]){
				sum--;
//				cout << i << " " << j << endl;
			}
		}
	}
	cout << sum;
	return 0;
}
