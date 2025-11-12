#include<bits/stdc++.h>
using namespace std;

struct area{
	long long l,r;
}arr[500005];

long long n,k;
long long a[500005];

bool cmp(area cmp_x,area cmp_y) {
	return cmp_x.r < cmp_y.r;
} 
 
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	long long res = 0;
	long long t = 0;
	for(long long l = 1; l <= n; ++l) {
		res = 0;
		for(long long r = l; r <= n; ++r) {
			res = res ^ a[r];
			if(res == k) {
				++t;
				arr[t].l = l;
				arr[t].r = r;
				break; 
			}
		}
	}
	sort(arr + 1, arr + 1 + t,cmp);
	long long r = 0;
	long long cnt = 0;
	for(long long i = 1; i <= t; ++i) {
		if(arr[i].l > r) {
			++cnt;
			r = arr[i].r;
		}
	}
	cout << cnt;
	return 0;

}
