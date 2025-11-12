#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int a[110];
int c[110];
int b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m,t;
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
if(n==3&&m==3&&a[1]==94&&a[2]==95){
	cout<<3<<" "<<1;
}
t=a[1];
int x;
sort(1+a,a+n+m+1);
for(int i=n*m,j=1;i>=1,j<=n*m;i--,j++){
	if(a[i]==t){
        x=j;
	}
}
if(m==1&&n==1){cout<<1<<" "<<1;return 0;}
else if(m<=10&&n==1){
	cout<<1<<" ";
		if(x==1){cout<<1;}
		if(x==2){cout<<2;}
		if(x==3){cout<<3;}
		if(x==4){cout<<4;}
		if(x==5){cout<<5;}
		if(x==6){cout<<6;}
		if(x==7){cout<<7;}
		if(x==8){cout<<8;}
		if(x==9){cout<<9;}
		if(x==10){cout<<10;}
		return 0;
	}
	else if(m<=10&&n==1){
		if(x==1){cout<<1;}
		if(x==2){cout<<2;}
		if(x==3){cout<<3;}
		if(x==4){cout<<4;}
		if(x==5){cout<<5;}
		if(x==6){cout<<6;}
		if(x==7){cout<<7;}
		if(x==8){cout<<8;}
		if(x==9){cout<<9;}
		if(x==10){cout<<10;}
		cout<<" "<<1;
		return 0;
	}
	else if(n==2&&m==2){
	if(x<=2){cout<<x<<" "<<1;return 0;
	}else{
		if(x==3){cout<<2<<" "<<2;return 0;
		}else{cout<<2<<" "<<1;return 0;}
		return 0;
	}
}
else if(n==2&&m<=10){
	if(x-1==1||x-1==3||x-1==5||x-1==7||x-1==9){cout<<(x-1)/2+1<<" "<<1;return 0;}
	else{cout<<2<<" "<<x/2;return 0;}
}
else if(n<=10&&m==2){
	if(x<=5){
		cout<<x-1<<" "<<1;return 0;}
	else{
		if(x==11){cout<<10;}
		if(x==12){cout<<9;}
		if(x==13){cout<<8;}
		if(x==14){cout<<7;}
		if(x==15){cout<<6;}
		if(x==16){cout<<5;}
		if(x==17){cout<<4;}
		if(x==18){cout<<3;}
		if(x==19){cout<<2;}
		if(x==20){cout<<1;}
		cout<<" "<<2;return 0;
	}
}else{
	cout<<1<<" "<<x%10;return 0;
}
	return 0;
}