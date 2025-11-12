#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],num=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a[1];
	for(int i=2;i<=n*m;i++){
		cin >> a[i];
		if(a[i]>a[1])num++;
	}if((num-1)/n%2==0)cout <<(num-1)/n+1<< " " << (num-1)%n+1;
	else cout << (num-1)/n+1 << " " << n-(num-1)%n;
	return 0;
}
