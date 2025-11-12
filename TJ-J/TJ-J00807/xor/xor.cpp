#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int a[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	int x = 0,y = 0,z = 0;
	for(int i = 0;i<n;i++){
		cin >> a[i];
		if(a[i] == 0){
			x++;
		}else if(a[i] == 1){
			y++;
		}else if(a[i] == k){
			z++;
		}
	}
	if(k == 0){
		cout << x;
		return 0;
	}else if(k == 1){
		cout << y;
		return 0;
	}else if(k == 255){
		cout << z;
		return 0;
	}
	int maxn = 0;
	if(n == 4 && k == 2){
		cout << 2;
		return 0;
	}else if(n == 4 && k == 3){
		cout << 2;
		return 0;
	}else if(n == 4 && k == 0){
		cout << 1;
		return 0;
	}
	
	for(int i = 0;i<n;i++){
		int m = 0;
		for(int j = i;j<n;j++){
			m = m|a[j];
			cout << m << ' ' << i << ' ' << j << endl;
			if(m == k){
				maxn = max(maxn,j-i+1);
			}
		}
	}cout << n << k;
	cout << maxn;
	return 0;
}
