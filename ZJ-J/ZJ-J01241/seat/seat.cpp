#include<bits/stdc++.h>
using namespace std;
long long ansx,ansy,n,m,a[100000],shunxu=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		if(a[i]>a[1]){
			shunxu++;
		}
	}
	shunxu--;
	ansy=shunxu/n+1;
	shunxu%=n;
	shunxu++;
	if(ansy%2==1){
		ansx=shunxu;
	}
	else{
		ansx=n-shunxu+1;
	}
	cout << ansy << " " << ansx << endl;
	return 0;
}