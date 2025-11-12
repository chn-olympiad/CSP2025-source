#include<bits/stdc++.h>
using namespace std;
int n,m,p,r,st=1,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	p=n*m;
	cin >> r;
	for(int i=2;i<=p;i++){
		int k;
		cin >> k;
		if(k>r) st++;
	}
	ans1=ceil(1.0*st/n);
	ans2=st%n;
	if(ans2==0) ans2=n;
	if(ans1%2==0) ans2=n-ans2+1;
	cout << ans1  << " " << ans2;
	return 0;
}
