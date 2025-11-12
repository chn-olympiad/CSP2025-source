#include<bits/stdc++.h>
using namespace std;
const int N = 1000+5;
int n,k;
int a[N],sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] == 0){
			sum++;
		} 
	}
	cout << sum;
	return 0;
}
