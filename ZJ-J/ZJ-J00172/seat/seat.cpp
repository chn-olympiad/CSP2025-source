#include<bits/stdc++.h>
using namespace std;

int n,m,i,t,q,a[10010],s;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=m*n;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+1+m*n);
	for(i=m*n;i>=1;i--)
		if(a[i]>=t)s++;
		else break;
	q=(s-1)%(2*n)+1;
	if(q<=n)cout<<s/(2*n)*2+1<<" "<<q;
	else cout<<s/(2*n)*2+2<<" "<<n-(q-n)+1;
	return 0;
}
/*


4 5
 2 1 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3

3 3
94 95 96 97 98 99 100 93 92

*/
