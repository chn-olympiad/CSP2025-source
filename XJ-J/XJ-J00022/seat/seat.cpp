#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],r,x,c;
bool tf=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==r)x=i;
	if(x%n!=0){
		c=x/n+1;
		x%=n;
		cout<<c<<" "<<(c%2?x:n-x+1);
	}
	else{
		c=x/n;
		cout<<c<<" "<<(c%2?n:1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
