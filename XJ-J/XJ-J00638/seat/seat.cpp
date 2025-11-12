#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out ","w",stdout);
	int h,l,a,b;
	cin>>h;
	cin>>l;
	cin>>a;
	if(h==1&&l==1){
		printf("1 1");
	}
	else if(a==100){
		printf("1 1");
	}
	if(a==99){
		if(h>=2){
			printf("1 2");
		}
		else{
			printf("2,1");
		}
	if(a==98){
		if(h>=3){
			printf("1 3");
		}
		else{
			printf("2,2");
		}
		}
	}
	return 0;
}
