#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, goal;
	cin>>n>>m;
	cin>>goal;
	a[goal]++;
	for(int i=2; i<=m*n; i++){
		int score;
		cin>>score;
		a[score]++;
	}
	int p=0;
	for(int i=100; i>=goal; i--){
		p+=a[i];
		if(i==goal) break;
	}
	int col=(p-1)/n+1;
	int row=p%n;
	if(row==0) row=n;
	if(col%2) cout<<col<<" "<<row;
	else cout<<col<<" "<<n-row+1;
	return 0;
}
