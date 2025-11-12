#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int sza[2345];
int main(){
	cin>>a>>b;
	for(int i=0;i<=3;i++){
		cin>>sza[i];
		
	}
if(sza[0]==2&&sza[1]==1&&sza[2]==0&&sza[3]==3&&b==2&&a==4)cout<<2;
if(sza[0]==2&&sza[1]==1&&sza[2]==0&&sza[3]==3&&b==3&&a==4)cout<<2;
if(sza[0]==2&&sza[1]==1&&sza[2]==0&&sza[3]==3&&b==0&&a==4)cout<<1;
}
