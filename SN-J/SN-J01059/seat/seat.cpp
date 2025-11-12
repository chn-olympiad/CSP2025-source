#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[105] = {0};
	int a1;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	a1 = a[1];
	sort(a+1,a+n*m+1);
	int t;
	for(int i = n*m;i >= 1;i--){
		if(a[i]==a1) t = n*m-i+1;
	}
	int k = 0;
	for(int i = 1;i <= m;i++){
		if(i%2!=0){
			k+=n;
			if(k>=t){
				cout << i << " " << n-k+t << endl;
				break;
			}
		}else if(i%2==0){
			k+=n;
			if(k>=t){
				cout << i << " " << k-t+1 << endl;
				break;
			}
		}
	}
	return 0;
} 
