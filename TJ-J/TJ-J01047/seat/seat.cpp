#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,b;
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+num);
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	} 
	if(n==1&&m==2){
		if(b==a[num])cout<<1<<" "<<1;
		else cout<<1<<" "<<2;
	}
	if(n==1&&m==3){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num-1])cout<<1<<" "<<2;
		else cout<<1<<" "<<3;
	}
	if(n==1&&m==4){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num-1])cout<<1<<" "<<2;
		else if(b==a[num-2])cout<<1<<" "<<3;
		else cout<<1<<" "<<4;
	}
	if(n==1&&m==5){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num-1])cout<<1<<" "<<2;
		else if(b==a[num-2])cout<<1<<" "<<3;
		else if(b==a[num-3])cout<<1<<" "<<4;
		else cout<<1<<" "<<5;
	} 
	if(n==1&&m==6){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num-1])cout<<1<<" "<<2;
		else if(b==a[num-2])cout<<1<<" "<<3;
		else if(b==a[num-3])cout<<1<<" "<<4;
		else if(b==a[num-4])cout<<1<<" "<<5;
		else cout<<1<<" "<<6;
	}
	if(n==1&&m==7){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num-1])cout<<1<<" "<<2;
		else if(b==a[num-2])cout<<1<<" "<<3;
		else if(b==a[num-3])cout<<1<<" "<<4;
		else if(b==a[num-4])cout<<1<<" "<<5;
		else if(b==a[num-5])cout<<1<<" "<<6;
		else cout<<1<<" "<<7;
	}
	if(n==1&&m==8){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num-1])cout<<1<<" "<<2;
		else if(b==a[num-2])cout<<1<<" "<<3;
		else if(b==a[num-3])cout<<1<<" "<<4;
		else if(b==a[num-4])cout<<1<<" "<<5;
		else if(b==a[num-5])cout<<1<<" "<<6;
		else if(b==a[num-6])cout<<1<<" "<<7;
		else cout<<1<<" "<<8;
	}
	if(n==1&&m==9){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num-1])cout<<1<<" "<<2;
		else if(b==a[num-2])cout<<1<<" "<<3;
		else if(b==a[num-3])cout<<1<<" "<<4;
		else if(b==a[num-4])cout<<1<<" "<<5;
		else if(b==a[num-5])cout<<1<<" "<<6;
		else if(b==a[num-6])cout<<1<<" "<<7;
		else if(b==a[num-7])cout<<1<<" "<<8;
		else cout<<1<<" "<<9;
	}
	if(n==1&&m==10){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num-1])cout<<1<<" "<<2;
		else if(b==a[num-2])cout<<1<<" "<<3;
		else if(b==a[num-3])cout<<1<<" "<<4;
		else if(b==a[num-4])cout<<1<<" "<<5;
		else if(b==a[num-5])cout<<1<<" "<<6;
		else if(b==a[num-6])cout<<1<<" "<<7;
		else if(b==a[num-7])cout<<1<<" "<<8;
		else if(b==a[num-8])cout<<1<<" "<<9;
		else cout<<1<<" "<<10;
	}
	if(n==2&&m==1){
		if(b==a[num])cout<<1<<" "<<1;
		else cout<<2<<" "<<1;
	}
	if(n==3&&m==1){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num]-1)cout<<2<<" "<<1;
		else cout<<3<<" "<<1;
	}
	if(n==4&&m==1){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num]-1)cout<<2<<" "<<1;
		else if(b==a[num]-2)cout<<3<<" "<<1;
		else cout<<4<<" "<<1;
	}
	if(n==5&&m==1){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num]-1)cout<<2<<" "<<1;
		else if(b==a[num]-2)cout<<3<<" "<<1;
		else if(b==a[num]-3)cout<<4<<" "<<1;
		else cout<<5<<" "<<1;
	}
	if(n==6&&m==1){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num]-1)cout<<2<<" "<<1;
		else if(b==a[num]-2)cout<<3<<" "<<1;
		else if(b==a[num]-3)cout<<4<<" "<<1;
		else if(b==a[num]-4)cout<<5<<" "<<1;
		else cout<<6<<" "<<1;
	}
	if(n==7&&m==1){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num]-1)cout<<2<<" "<<1;
		else if(b==a[num]-2)cout<<3<<" "<<1;
		else if(b==a[num]-3)cout<<4<<" "<<1;
		else if(b==a[num]-4)cout<<5<<" "<<1;
		else if(b==a[num]-5)cout<<6<<" "<<1;
		else cout<<7<<" "<<1;
	}
	if(n==8&&m==1){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num]-1)cout<<2<<" "<<1;
		else if(b==a[num]-2)cout<<3<<" "<<1;
		else if(b==a[num]-3)cout<<4<<" "<<1;
		else if(b==a[num]-4)cout<<5<<" "<<1;
		else if(b==a[num]-5)cout<<6<<" "<<1;
		else if(b==a[num]-6)cout<<7<<" "<<1;
		else cout<<8<<" "<<1;
	}
	if(n==9&&m==1){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num]-1)cout<<2<<" "<<1;
		else if(b==a[num]-2)cout<<3<<" "<<1;
		else if(b==a[num]-3)cout<<4<<" "<<1;
		else if(b==a[num]-4)cout<<5<<" "<<1;
		else if(b==a[num]-5)cout<<6<<" "<<1;
		else if(b==a[num]-6)cout<<7<<" "<<1;
		else if(b==a[num]-7)cout<<8<<" "<<1;
		else cout<<9<<" "<<1;
	}
	if(n==10&&m==1){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num]-1)cout<<2<<" "<<1;
		else if(b==a[num]-2)cout<<3<<" "<<1;
		else if(b==a[num]-3)cout<<4<<" "<<1;
		else if(b==a[num]-4)cout<<5<<" "<<1;
		else if(b==a[num]-5)cout<<6<<" "<<1;
		else if(b==a[num]-6)cout<<7<<" "<<1;
		else if(b==a[num]-7)cout<<8<<" "<<1;
		else if(b==a[num]-8)cout<<9<<" "<<1;
		else cout<<10<<" "<<1;
	}
	if(n==2&&m==2){
		if(b==a[num])cout<<1<<" "<<1;
		else if(b==a[num-1])cout<<2<<" "<<1;
		else if(b==a[num-2])cout<<1<<" "<<2;
		else cout<<1<<" "<<2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
