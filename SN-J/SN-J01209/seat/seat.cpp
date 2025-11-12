#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],r,c,sc,pl;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+n*m+1,greater<int> ());
	for (int i=1;i<=n*m;i++){
		if (a[i]==sc) {
			pl=i;break;
		}
	}
	int group=pl/n,extra=pl%n;
	if (group%2==0){
		if (extra==0){
			r=group,c=extra+1;
			cout<<r<<' '<<c;
			return 0;
		}
		else {
			r=group+1,c=extra;
			cout<<r<<' '<<c;
			return 0;
		}
	}
	else if (group%2==1){
		if (extra==0){
			r=group,c=n;
			cout<<r<<' '<<c;
			return 0;
		}
		else{
			r=group+1,c=n-extra+1;
			cout<<r<<' '<<c;
		}
		return 0;
	}
	return 0;
}

