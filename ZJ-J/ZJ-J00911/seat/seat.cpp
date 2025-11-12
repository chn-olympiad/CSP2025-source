#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for (int i=1; i<=n*m; i++) cin>>a[i];
	int t=a[1];
	sort(a+1, a+1+n*m, cmp);
	int temp;
	for (int i=1; i<=n*m; i++){
		if (a[i]==t){
			temp=i;
			break;
		}
	}
	int c, r;
	if ((temp/n)%2==0){
		if (temp%n!=0) c=temp/n+1;
		else c=temp/n;
		if (temp%n!=0) r=temp%n;
		else r=1;
	}
	else{
		if (temp%n!=0) c=temp/n+1;
		else c=temp/n;
		if (temp%n!=0) r=n-(temp%n)+1;
		else r=n;
	}
	cout<<c<<' '<<r;
	return 0;
}