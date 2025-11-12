#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int cnt=1;
int sc;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m;
	int sum = n*m;
	cin >> sc;
	for (int i = 2;i <= sum;i++){
		cin >> x;
		if (x > sc){
			cnt++;
		}
	}
	int p = cnt/n;
	if (cnt%n!=0){
		p++;
	}
	int k = cnt - (p-1)*n;
	if (p%2==0){
		cout << p << " " << k+1;
	}
	else{
		cout << p << " " << k;
	}
	return 0; 
}
