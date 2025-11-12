//SN-J00919 范任哲 延安市宝塔区高新学校（延安无锡实验学校） 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in",stdin);
	freopen("seat.out",stdout);
	int n,m,a[110],l;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	l=a[0];
	for(int i=0;i<n*m-1;i++){
		for(int j=0;j<n*m-1;j++){
			if(a[j]<a[j+1]){
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==l){
			cout<<(i/n)+1<<' ';
			if(i/n%2==0){
				cout<<(i%n)+1;
			}else{
				if(m==2){
					if(i%2+1==1){
						cout<<2;
					}else{
						cout<<1;
					}
				}else if(m==3){
					if(i%3+1==3){
						cout<<1;
					}else if(i%3+1==2){
						cout<<2;
					}else{
						cout<<3;
					}
				}else if(m==4){
					if(i%4+1==4){
						cout<<1;
					}else if(i%4+1==3){
						cout<<2;
					}else if(i%4+1==2){
						cout<<3;
					}else{
						cout<<4;
					}
				}else if(m==5){
					if(i%5+1==5){
						cout<<1;
					}else if(i%5+1==4){
						cout<<2;
					}else if(i%5+1==3){
						cout<<3;
					}else if(i%5+1==2){
						cout<<4;
					}else{
						cout<<5;
					}
				}else if(m==6){
					if(i%6+1==6){
						cout<<1;
					}else if(i%6+1==5){
						cout<<2;
					}else if(i%6+1==4){
						cout<<3;
					}else if(i%6+1==3){
						cout<<4;
					}else if(i%6+1==2){
						cout<<5;
					}else{
						cout<<6;
					}
				}else if(m==7){
					if(i%7+1==7){
						cout<<1;
					}else if(i%7+1==6){
						cout<<2;
					}else if(i%7+1==5){
						cout<<3;
					}else if(i%7+1==4){
						cout<<4;
					}else if(i%7+1==3){
						cout<<5;
					}else if(i%7+1==2){
						cout<<6;
					}else{
						cout<<7;
					}
				}else if(m==8){
					if(i%8+1==8){
						cout<<1;
					}else if(i%8+1==7){
						cout<<2;
					}else if(i%8+1==6){
						cout<<3;
					}else if(i%8+1==5){
						cout<<4;
					}else if(i%8+1==4){
						cout<<5;
					}else if(i%8+1==3){
						cout<<6;
					}else if(i%8+1==2){
						cout<<7;
					}else{
						cout<<8;
					}
				}else if(m==9){
					if(i%9+1==9){
						cout<<1;
					}else if(i%9+1==8){
						cout<<2;
					}else if(i%9+1==7){
						cout<<3;
					}else if(i%9+1==6){
						cout<<4;
					}else if(i%9+1==5){
						cout<<5;
					}else if(i%9+1==4){
						cout<<6;
					}else if(i%9+1==3){
						cout<<7;
					}else if(i%9+1==2){
						cout<<8;
					}else{
						cout<<9;
					}
				}else{
					if(i%10+1==10){
						cout<<1;
					}else if(i%10+1==9){
						cout<<2;
					}else if(i%10+1==8){
						cout<<3;
					}else if(i%10+1==7){
						cout<<4;
					}else if(i%10+1==6){
						cout<<5;
					}else if(i%10+1==5){
						cout<<6;
					}else if(i%10+1==4){
						cout<<7;
					}else if(i%10+1==3){
						cout<<8;
					}else if(i%10+1==2){
						cout<<9;
					}else{
						cout<<10;
					}
				}
			}
		}
	}
	return 0;
}
