#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,i=0,s=0,x=0,seat=1;
	cin>>n;
	cin>>m;
	cin>>s;
	for(i=1;i<n*m;i++){  //对成绩排序 
		cin>>x;
		if(x>s){
			seat+=1;
		}
	}
	int d=seat/n;  //判断行与列 
	int h;
	if(seat%n==0){
		h=d;
		cout<<d;
	}
	else{
		h=d+1;
		cout<<d+1;
	}
	if(h%2==1){
		cout<<' '<<seat-((h-1)*n);
	}
	else{
		cout<<' '<<(h*n+1)-seat;
	}
	return 0;
}
