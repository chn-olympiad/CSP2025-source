#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10000],sum,x,c,r;
	cin>>n>>m;
	int y=n+1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			x=i;
			break;
		}
	}
	if(x%n==0){
		c=x/n;
	}
	if(x%n!=0){
		c=x/n+1;
	}
	if(c%2!=0){
		if(x%n==0){
			r=n;
		}else{
			r=x%n;
		}
		
	}
	if(c%2==0){
		if(x%n==0){
			r=1;
		}
		else{
			r=y-(x%n);
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
