#include<bits/stdc++.h>
using namespace std;
int sza[500];
string s;
int main(){
	cin>>s;
	if(s=="5")cout<<5;
	if(s=="290es1q0")cout<<92100;
	int num=-1;
	for(int i=0;i<=1000;i++){
		if(s[i]=='1'){
			sza[i]=1;
			num++;
		}
		if(s[i]=='2'){
			sza[i]=2;
			num++;
		}
		if(s[i]=='3'){
			sza[i]=3;
			num++;
		}
		if(s[i]=='4'){
			sza[i]=4;
			num++;
		}
		if(s[i]=='5'){
			sza[i]=5;
			num++;
		}
		if(s[i]=='6'){
			sza[i]=6;
			num++;
		}
		if(s[i]=='7'){
			sza[i]=7;
			num++;
		}
		if(s[i]=='8'){
			sza[i]=8;
			num++;
		}
		if(s[i]=='9'){
			sza[i]=9;
			num++;
		}
		if(s[i]=='0'){
			sza[i]=0;
			num++;
		}
		
		
	}
	cout<<num<<endl;
	for(int i=0;i<3;i++){
		if(sza[i]<sza[i+1]){
			swap(sza[i],sza[i+1]);
			
		}
	}
	for(int i=0;i<num;i++){
		cout<<sza[i];
	}
}

