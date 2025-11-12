#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n,sum;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum++;	
		}
	}
	for(int i=1;i<n;i--){
		for(int j=1;j<n;j--){
			if(i==0){
				sum--;
			} 
		}
	}
	cout<<n<<endl;
	return 0;
}
