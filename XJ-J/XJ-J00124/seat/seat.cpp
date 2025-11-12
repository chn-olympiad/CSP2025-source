#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105];
	int n,m,c,r,i,num;
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];	
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++){
		if(num==a[i]){
			break;
		}
	}
	c=i%n;
	if(c!=0){
		c=i/n+1;
	}
	else{
		c=i/n;
	}
	if(c%2==0){
		r=n-i/n+1;
	}else if(i%n==0){
		r=n;
	}else{
		r=i%n;
	}
	cout<<c<<" "<<r;
	return 0;
} 
