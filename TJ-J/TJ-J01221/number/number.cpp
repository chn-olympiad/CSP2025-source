#include<bits/stdc++.h>
using namespace std;
ifstream fin("number.in");
ofstream fout("number.out");
int main(){
	char s;
	fin>>s;
	int a;
	for(int i=1;i<=s;i++){
		if(s<97){
			a = a+i;
		}
		else{
			a = a;
		}
	}
	fout<<a; 
	return 0;
} 
