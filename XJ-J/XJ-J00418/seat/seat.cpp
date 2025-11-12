#include<bits/stdc++.h>
using namespace std;

int n, m;

bool cmp(int a, int b){
	int a = n;
	int b = m;
	if (a > b) return a , b;
}

int main(){
	freopen("seat.in", "r", std(in));
	freopen("seat.out", "w", std(out));
	cin >> n >> m;
	int sum = n*m;
	int num[sum];
	for (int i = 1; i <= n*m; i++){
		cin >> num[i];
	}
	sort(n,m+1,cmp);
	return 0;
}
