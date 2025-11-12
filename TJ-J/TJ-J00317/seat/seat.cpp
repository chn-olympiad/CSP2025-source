#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[1001],l,pos;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)cin>>a[i];
	l=a[1];
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=1;i--){
		if (a[i]==l){
			pos=n*m-i+1;
			break;
		}
	}
	int p=(pos-1)/m+1,pp;
	if (p%2==1)pp=(pos-1)%m+1;
	else pp=n-(pos-1)%m;
	cout<<p<<' '<<pp;
	return 0;
}
