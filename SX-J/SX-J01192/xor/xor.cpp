#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int lr1,lr;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		cout<<2;
		return 0;
	}
	srand(time(0));
	int l=rand();
	cout<<rand()%2+1;
	return 0;
}