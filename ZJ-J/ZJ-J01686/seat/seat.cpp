#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],bh,t,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1; i<=n*m; i++){
		if(a[i]==t){
			bh=i;
			break;
		}
	}l=bh/n;
	if(bh%n==0)l--;
	l++;
	h=bh%n;
	if(h==0)h=n;
	if(l%2==0)h=n-h+1;
	cout<<l<<" "<<h;
}