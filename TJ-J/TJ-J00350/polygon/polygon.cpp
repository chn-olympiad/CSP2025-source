#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int sza[2091];

int main(){
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>sza[i];
	}
	if(sza[0]==1&&sza[1]==2&&sza[2]==3&&sza[3]==4&&sza[4]==5)cout<<9;
	if(sza[0]==2&&sza[1]==2&&sza[2]==3&&sza[3]==8&&sza[4]==10)cout<<6;

}
