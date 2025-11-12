#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)cin >> a[i];
	int xx = a[1],pos;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
		if(a[i]==xx) {pos = i;break;}
	pos = n*m-pos+1;
	if(pos%n==0) {
		if(pos%2==0) cout << pos/n << " "<<n;
		if(pos%2==1) cout << pos/n << " "<<1;
	}
	if(pos%n!=0){
		if((pos/n+1)%2==0) cout << pos/n+1<<" "<<n-pos%n+1;
		if((pos/n+1)%2==1) cout << pos/n+1<<" "<<pos%n;
	}
	return 0;
}