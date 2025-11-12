#include <bits/stdc++.h>
using namespace std;
const int maxn=200;
int n,m,i,k,mo,md,a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	for(i=2;i<=n*m;i++)
		if(a[i]>a[1]) k++;
	k++;
	mo=k%n;md=k/n+1;
	if(!mo) md--,mo=n;
	if(md&1) cout<<md<<" "<<mo;
	else cout<<md<<" "<<n-mo+1;
	return 0;
}