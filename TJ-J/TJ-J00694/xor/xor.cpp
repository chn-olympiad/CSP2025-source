#include <bits/stdc++.h> 
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	int j = 0;
	int z = 0;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 0){
			j++;
		}else{
			z++;
		}
	}
	if(k == 0){
		cout << j;
	}else if(k == 1){
		cout << z;
	}
}
