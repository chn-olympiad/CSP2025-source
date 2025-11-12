#include<iostream>
using namespace std;
int t,n,x;
int a[100001] = {};
int b[100001] = {};
int c[100001] = {};
int p[100001] = {};
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);

	cin >> t;
	
	
	
	while (t >= 1){
		t-=1;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		
		
		
		for(int i = 1;i <= n;i++){
			if (a[i] >= b[i] && a[i]>= c[i]){
				p[i] = a[i];
			}else if (b[i] >= a[i] && b[i]>= c[i]){
				p[i] = a[i];
			}else if (c[i]>= b[i] && c[i] >= a[i]){
				p[i] = a[i];
			}
		}
	}
	
	
	
	
	
	for(int i = 1;i <= n;i++){
		if(a[i] + b[i] + c[i] > n / 2){
			break;
		}
	}
	for(int i = 1;i <= n;i++){
		cout << p[i];
	}
	return 0;
}
