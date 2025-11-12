#include <iostream>
#define int long long
using namespace std;

signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k, N=0;
	cin >> n >> k;
	int a[n+1];
	int X = a[1];
	for(int i=1; i<=n; i++) cin >> a[i];
	if(k==0){
		for(int i=1; i<=n-1; i++){
			
			if(a[i] == a[i+1]){
				N++;
				i++;	
			}
			
		}
	}
	else if(k==1){
		for(int i=1; i<=n-1; i++){
			
			if(a[i] != a[i+1]){
				N++;
				i++;	
			}
			
		}
	}
	

	cout << N;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
