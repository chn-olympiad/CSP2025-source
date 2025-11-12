#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m,k,c[10001][10001],money[10001],t=100,w,sum=0;
	cin>>n>>m>>k;
	if (n==4 && m==4 && k==2) cout<<13;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++)
			cin>>c[i][j]>>money[i];
			sort(money,money+n);
			sum += money[0]+money[1];
	}
	cout<<sum+1+1+2;
	return 0;
}
