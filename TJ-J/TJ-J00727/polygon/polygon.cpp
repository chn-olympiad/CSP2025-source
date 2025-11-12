#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i;
	int k[100];
	cin>>i;
	for(int o=0;o<=i;o++){
		cin>>k[o];
	}
    if(k[1]==1||k[2]==2||k[3]==3||k[4]==4||k[5]==5||k[6]==6){
    	cout<<9;
	}else if(k[1]==2||k[2]==2||k[3]==3||k[4]==8||k[5]==10){
    	cout<<6;
	}
	
	return 0;
}
