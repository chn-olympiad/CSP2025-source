#include<bits/stdc++.h>
using namespace std;
const int N=12;
int biao[N][N],n,m;
int gr[N*N],gr1;
int solve1(int g,int h){
	g=g-h;
	if(g==1){
		return h;
	}
	if(g==2){
		return h-1; 
	}
	if(g==3){
		return h-2; 
	}
	if(g==4){
		return h-3; 
	}
	if(g==5){
		return h-4; 
	}
	if(g==6){
		return h-5; 
	}
	if(g==7){
		return h-6; 
	}
	if(g==8){
		return h-7; 
	}
	if(g==9){
		return h-8; 
	}
	if(g==10){
		return h-9; 
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>gr1;
	for(int i=1;i<=n*m-1;i++){
		cin>>gr[i];
	}
	int number=0;
	for(int i=1;i<=n*m-1;i++){
		if(gr[i]>gr1){
			number++;
		}
	}
	number+=1;
	if(number<=n){
		cout<<1<<" "<<number;
		return 0;
	}
	if(number>n && number<n*2+1){
		cout<<2<<" "<<solve1(number,n);
		return 0;
	}
	if(number>n*2 && number<n*3+1){
		cout<<3<<" "<<number-(n*2);
		return 0;
	}
	if(number>n*3 && number<n*4+1){
		cout<<4<<" "<<solve1(number-n*3,n);
		return 0;
	}
	if(number>n*4 && number<n*5+1){
		cout<<5<<" "<<number-(n*4);
		return 0;
	}
	if(number>n*5 && number<n*6+1){
		cout<<6<<" "<<solve1(number-n*5,n);
		return 0;
	}
	if(number>n*6 && number<n*7+1){
		cout<<7<<" "<<number-(n*6);
		return 0;
	}
	if(number>n*7 && number<n*8+1){
		cout<<8<<" "<<solve1(number-n*7,n);
		return 0;
	}
	if(number>n*8 && number<n*9+1){
		cout<<9<<" "<<number-(n*8);
		return 0;
	}
	if(number>n*9 && number<n*10+1){
		cout<<10<<" "<<solve1(number-n*9,n);
		return 0;
	}
	return 0;
} 
