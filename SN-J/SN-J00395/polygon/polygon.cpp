#include<fstream>
std::ifstream cin("polygon.in");
std::ofstream cout("polygon.out");
//#include<bits/stdc++.h>
using namespace std;
int main(){
	int a=0,b=0;
	cin>>a;
	int v[a+5]={};
	for(int i=0;i<a;i++){
		cin>>v[i];
	}
	if(a<2){
		cout<<1;
	}
}
