#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,b,c;
	cin >> n >> m;
	long long a[n * m + 5];
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	b = a[1];
	sort(a + n + m + 1,a + 1);
	for(int i = 1;i <= n * m;i++){
		if(i % 2 == 0){
			for(int j = m * n;j >= 1;j--){
				if(b == a[j]){
					cout << n << ' ' << m << endl;
					return 0;
				}
			}
		}
		else{
			for(int j = 1;j <= m * n;j++){
				if(b == a[j]){
					cout << n << ' ' << m << endl;
					return 0;
				}
			}
		}
	}
}
