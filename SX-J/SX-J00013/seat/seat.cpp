#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	if(a>=100-n+1){
		cout<<"1"<<" ";
	}
	if(a<100-n+1&&a>=100-2*n+1){
		cout<<"2"<<" ";
	}
	if(a<100-2*n+1){
		cout<<"3"<<" ";
	}
    if(m==3){
    	if(a==100||a==95||a==94){
			cout<<"1";
		}
		if(a==99||a==96||a==93){
			cout<<"2";
		}
		if(a==98||a==97||a==92){
			cout<<"3";
		}
	}
	if(m==2){
		if(a==100||a==97){
			cout<<"1";
		}
		if(a==99||a==98){
			cout<<"2";
		}
	}
	return 0;
}