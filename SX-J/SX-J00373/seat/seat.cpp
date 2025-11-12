#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int a[110], b[15][15], cnt = 1, m, n, c, r, maxn = 101, minn = -1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n*m; i++){
		cin >> a[i];
		if(a[i] > a[0])
			cnt++;
	}
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++){
			if(cnt-i*n > 0 && cnt-i*n <= n){
				if((i+1) % 2 == 1){
					r = cnt-i*n;
					c = i+1;
				}
				else{
					r = n-(cnt-i*n-1);
					c = i+1;
				}
			}
		}
	cout << c << " " << r;
	return 0;
}