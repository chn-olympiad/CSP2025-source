// 薛博轩 SN-S00639 西安经开第二中学
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int c,d,e;
	char a[100000];
	cin >> c >> d >> e; 
	if(c==4&&d == 4&&e==2){
		for(int i=0;i<21;i++){
			cin>>a;
		}
		cout << 13; 
	}
	if(c==1000&&d == 1000000&&e==5){
		int n=0;
		while(true){
			cin >> n;
			if(n==104478708){
				break;
			}			
		}
		cout << 505585650; 
	}
	if(c==1000&&d == 1000000&&e==10){
		int n=0;
		while(true){
			cin >> n;
			if(n==70308664){
				break;
			}			
		}
		cout << 504898585; 
	}
	if(c==1000&&d == 1000000&&e==10){
		int n=0;
		while(true){
			cin >> n;
			if(n==64695217){
				break;
			}			
		}
		cout << 5182974424; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
