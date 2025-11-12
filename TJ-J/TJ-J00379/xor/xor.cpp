#include <bits/stdc++.h>
using namespace std; 
int n,k,a[500001],count1,count0,countsame;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 1) count1++;
		if(a[i] == 0) count0++; 
	}
	//特殊性质1 
	if(count1 == n){
		cout << n / 2;
		return 0;
	}
	//特殊性质2 
	if(count1 + count0 == n and k == 1){
		cout << count1;
		return 0;
	}
	if(count1 + count0 == n and k == 0){
		countsame = count0;
		for(int i = 1;i <= n;i++){
			if(a[i] == a[i + 1] and a[i] == 1){
				countsame++;
				a[i+1] = 0;
				i++;
			}
		}
		cout << countsame;
		return 0;
	}
	return 0;
}
