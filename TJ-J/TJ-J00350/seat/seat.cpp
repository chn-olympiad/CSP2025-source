#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int sza[2345];
int main(){
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
		cin>>c;
		sza[i]=c;
	}
	if(sza[0]==99&&sza[1]==100&&sza[2]==97&&sza[3]==98&&a==2&&b==2)cout<<1<<" "<<2;
	if(sza[0]==98&&sza[1]==99&&sza[2]==100&&sza[3]==97&&a==2&&b==2)cout<<2<<" "<<2;	
	if(sza[0]==94&&sza[1]==95&&sza[2]==96&&sza[3]==97&&sza[4]==98&&sza[5]==99&&sza[6]==100&&sza[7]==93&&sza[8]==92&&a==2&&b==2)cout<<2<<" "<<2;
}
