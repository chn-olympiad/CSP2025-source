#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N*N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int q = a[1];
	sort(a+1, a+(n*m+1));
	int ans = lower_bound(a+1, a+(n*m+1), q)-a;
	cout << m-(ans-1)/n << " "; 
	if((m-(ans-1)/n)%2 == 1){
		cout << n-((ans-1)%n+1)+1;
	}
	else{
		cout << (ans-1) % n+1;
	}
	return 0;
}
