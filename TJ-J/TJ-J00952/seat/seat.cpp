#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long p = -1;
long long h = 0;
long long arr[1005];
long long brr[105][105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for(long long i = 1; i <= n * m; i++){
		cin>>arr[i];
	}
	h = arr[1];
	sort(arr + 1, arr + n * m + 1);
	for(long long j = 1; j <= n * m; j++){
		long long i = n * m - j;
		if(arr[i] == h){
			long long u, w;
			if(i % m != 0){
				u = i / m + 1;
			}else{
				u = i / m;
			}
			if(i % (2 * n) == 0){
				w = 1;
			}else if(i % n == 0){
				w = m;
			}else if(i % (2 * n) < m){
				w = i % (2 * n);
			}else{
				w = i % (2 * n);
			}
			cout<<u - 1<<" "<<w - 1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
