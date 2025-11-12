#include <bits/stdc++.h>
using namespace std;
long long n,m,a[100002],num,c,r,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x) num=n*m+1-i;
	}
	if(num%n==0) c=num/n;
	else c=num/n+1;
	if(c%2==1){
		if(num%n==0) r=n;
		else r=num%n;
	}
	else {
		if(num%n!=0){
			r=n+1-num%n;
		}
		else r=num/n;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
