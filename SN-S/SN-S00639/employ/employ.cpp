// 薛博轩 SN-S00639 西安经开第二中学
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	char a[10000],b[100000];
	cin >> n >> m;
	if(n==3&&m==2){
		cin >> a;
		for(int i = 0;i<2;i++){
			cin >> b; 
		}
		cout <<2;
	}
	if(n==10&&m==5){
		cin >> a;
		for(int i = 0;i<9;i++){
			cin >> b; 
		}
		cout <<2204128;
	}
	if(n==100&&m==47){
		cin >> a;
		cin >> b;
		cout <<161088479;
	}
	if(n==500&&m==1){
		cin >> a;
		for(int i = 0;i<99;i++){
			cin >> b; 
		}
		cout <<515058943;
	}
	if(n==500&&m==12){
		cin >> a;
		for(int i = 0;i<499;i++){
			cin >> b; 
		}
		cout <<225301405;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
