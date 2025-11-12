#include<bits/stdc++.h>
using namespace std;
int n,m;
int x;
int a[200];
void f(int c){
	int x,y;
	if(c%n==0){
		x=c/n;
	}
	else{
		x=c/n+1;
	}
	if(x%2==0){
		y=n-(c-c/n*n)+1;
	}
	else{
		y=c-c/n*n;
	}
	cout<<x<<" "<<y;
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	a[1]=x;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			f(n*m-i+1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
