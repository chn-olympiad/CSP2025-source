#include<bits/stdc++.h>
using namespace std;
int a[105],k,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			l=i;
		}
	}
	int x,y;
	if(l%n==0){
		y=l/n;
	}
	else y=l/n+1;
	if(y%2==1){
		x=n-(l%n+1)+1;
	}
	else x=l%n+1;
	cout<<y<<" "<<x;
	return 0;
}