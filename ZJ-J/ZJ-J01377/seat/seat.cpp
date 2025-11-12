#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],z;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	int p=a[1],l=0;
	for(int q=2;q<=n*m;q++)cin>>a[q];
	sort(a+1,a+n*m+1,cmp);
	for(int q=1;q<=n*m;q++){
		if(a[q]==p){
			l=q;
			break;
		}
	}
	if(l%n==0)z=(l/n)-1;
	else z=l/n;
	cout<<z+1<<' ';
	if(z%2==0){
		if(l%n==0)cout<<n;
		else cout<<l%n;
	}
	else {
		if(l%n==0)cout<<n;
		else cout<<n-(l%n)+1;
	}
	return 0;
}
