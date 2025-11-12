#include<iostream>
using namespace std;
#include<fstream>

int main(){
	int m=0;
	int n=0;
	int total=0;
	std::ifstream cin("seat.in");
	std::ofstream cout("seat.out");
	cin>>m;
	cin>>n;
	total=m*n;
	int seat_number=1;
	int a=0;
	cin>>a;
	for(int i=1;i<total;i++){
		int flag=0;
		cin>>flag;
		if(flag>a){
			seat_number++;
		}
		
		}
	int x=0;
	int y=0;
	if(seat_number%n==0){
		x=seat_number/n;
	}
	else{
		x=seat_number/n+1;
	}
	
	if(x%2==1){
		if(seat_number%n==0){
			y=n;
		}
		else{
			y=seat_number%n;
		}
	}
	else{
		y=n-(seat_number%n)+1;
	}
	
	cout<<x<<" "<<y;
	
	return 0;
}
