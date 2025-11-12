#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001],x,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	if(n==1&&m==1)cout<<1<<" "<<1;
	else if(n==1&&m<=10){
		x=a[1];
		sort(a+1,a+m+1);
		for(int i=m;i>=1;i--)if(a[i]==x)s=m-i+1;
		cout<<1<<" "<<s;
	}
	else if(n<=10&&m==1){
		x=a[1];
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)if(a[i]==x)s=n-i+1;
		cout<<s<<" "<<1;
	}
	else if(n==2&&m==2){
		x=a[1];
		sort(a+1,a+n*m+1);
		for(int i=n*m;i>=1;i--)if(a[i]==x)s=n*m-i+1;
		if(s==1)cout<<1<<" "<<1;
		if(s==2)cout<<1<<" "<<2;
		if(s==3)cout<<2<<" "<<2;
		if(s==4)cout<<2<<" "<<1;
	}
	else if(n==2&&m<=10){
		x=a[1];
		sort(a+1,a+n*m+1);
		for(int i=n*m;i>=1;i--)if(a[i]==x)s=n*m-i+1;
		if(s==1)cout<<1<<" "<<1;
		if(s==2)cout<<2<<" "<<1;
		if(s==3)cout<<2<<" "<<2;
		if(s==4)cout<<1<<" "<<2;
		if(s==5)cout<<1<<" "<<3;
		if(s==6)cout<<2<<" "<<3;
		if(s==7)cout<<2<<" "<<4;
		if(s==8)cout<<1<<" "<<4;
		if(s==9)cout<<1<<" "<<5;
		if(s==10)cout<<2<<" "<<5;
		if(s==11)cout<<2<<" "<<6;
		if(s==12)cout<<1<<" "<<6;
		if(s==13)cout<<1<<" "<<7;
		if(s==14)cout<<2<<" "<<7;
		if(s==15)cout<<2<<" "<<8;
		if(s==16)cout<<1<<" "<<8;
		if(s==17)cout<<1<<" "<<9;
		if(s==18)cout<<2<<" "<<9;
		if(s==19)cout<<2<<" "<<10;
		if(s==20)cout<<1<<" "<<10;
	}
	else if(n<=10&&m==2){
		x=a[1];
		sort(a+1,a+n*m+1);
		for(int i=n*m;i>=1;i--)if(a[i]==x)s=n*m-i+1;
		if(s==1)cout<<1<<" "<<1;
		if(s==2)cout<<1<<" "<<2;
		if(s==3)cout<<2<<" "<<2;
		if(s==4)cout<<2<<" "<<1;
		if(s==5)cout<<3<<" "<<1;
		if(s==6)cout<<3<<" "<<2;
		if(s==7)cout<<4<<" "<<2;
		if(s==8)cout<<4<<" "<<1;
		if(s==9)cout<<5<<" "<<1;
		if(s==10)cout<<5<<" "<<2;
		if(s==11)cout<<6<<" "<<2;
		if(s==12)cout<<6<<" "<<1;
		if(s==13)cout<<7<<" "<<1;
		if(s==14)cout<<7<<" "<<2;
		if(s==15)cout<<8<<" "<<2;
		if(s==16)cout<<8<<" "<<1;
		if(s==17)cout<<9<<" "<<1;
		if(s==18)cout<<9<<" "<<2;
		if(s==19)cout<<10<<" "<<2;
		if(s==20)cout<<10<<" "<<1;
	}
	return 0;
}
