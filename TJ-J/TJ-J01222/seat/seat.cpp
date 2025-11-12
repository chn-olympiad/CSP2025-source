#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

int n,m,s;
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n * m;i++) cin >> a[i];
	s = a[0];sort(a,a + n * m);
	int q = n * m - 1;
	for(int i = 1;i <= m;i++){
		if(i % 2){
			for(int j = 1;j <= n;j++){
				if(a[q--] == s){
					cout << i << ' ' << j;return 0;
				}
			}
		}
		else{
			for(int j = n;j >= 1;j--){
				if(a[q--] == s){
					cout << i << ' ' << j;return 0;
				}
			}
		}
	}
	return 0;
}
