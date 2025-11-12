#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, num=0, l, h;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	for(int i=2; i<=n*m; i++){
		if(a[i]>a[1]) num++;
	} 
	num=num+1;
	l=num/n;
	if(num%n) l++;
	int ql=l-1;
	int y=num-ql*n;
	if(l%2==1){
		h=y;
	}
	else h=n-y+1;
	cout<<l<<' '<<h;
	return 0;
}