#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	long long cnt = 0;
	cin>>n>>m;
	long long a[n*m];
	for(int i = 0;i<n*m;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n*m;i++){
		if(a[i]>a[0]){
			
			cnt++;
		}
	}
	long long x;
	long long y;
	if((cnt/n + 1) % 2 == 0){
		x = cnt/n + 1;
		y = n - cnt % n;
	}
	else{
		x = cnt/n + 1;
		y = cnt % n + 1;
		
	}
	
	cout<<x<<" "<<y;
	return 0;
}

