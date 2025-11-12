#include<iostream>
using namespace std;

int n,m;
int z,b;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>z;
	int num=1;
	while(cin>>b){
		if(b>z) num++;
	}
	int g=0;
	if(num%(n*2)==0){
		g=num/(n*2)-1;
		num=n*2;
	}
	else{
		g=num/(n*2); 
		num%=(n*2);
	}
	
	if(num>n){
		cout<<g*2+2<<' ';
		cout<<n-(num-n)+1;
	}
	else{
		cout<<g*2+1<<' ';
		cout<<num;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
