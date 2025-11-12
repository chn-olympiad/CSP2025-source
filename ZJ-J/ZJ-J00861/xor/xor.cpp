#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int n, k, cnt, l_edge = 1;
int sum_xor(int l, int r){
	int s = a[l];
	for (int i = l + 1;i <= r;i++){
		s = (s ^ a[i]);
	}return s;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}for (int r = 1;r <= n;r++){
		for (int l = l_edge;l <= r;l ++){
			int S = sum_xor(l, r);
			if (S == k){
				cnt ++;
				l_edge = r + 1;
				break;	
			}
		}
	}cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
