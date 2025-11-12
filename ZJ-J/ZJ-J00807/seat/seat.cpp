#include<bits/stdc++.h>
using namespace std;
int n,m,ar[110],k,p,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> ar[i];
	}
	k=ar[1];
	sort(ar+1,ar+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(ar[i]==k){
			p=n*m-i+1;
		}
	}
	l=(p+n-1)/n;
	cout << l << ' ';
	if(l%2){
		cout << p-l*n+n;
	}else{
		cout << l*n-p+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
