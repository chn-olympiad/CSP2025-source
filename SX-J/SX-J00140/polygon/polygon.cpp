#include<bits/stdc++.h>
using namespace std;
long long a,b[100000],ma,e=4,js,m=3;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;

	for(int i=1;i<=a;i++){
		cin>>b[i];
		if(ma<b[i]){
			ma=b[i];
		}
	}
	if(a<3){
		cout<<0;
	}
	if(a==3){
		if(b[1]+b[2]+b[3]>ma*2){
			cout<<1;
		}
		else
		cout<<0;
	}
	if(a>3){
	for(int i=1;i<=a;){
		if(e==a){
			break;
		}
		ma=0;
		for(int j=1;j<e;j++){
			if(ma<b[j]){
				ma=b[j];
			}
		}
		e++;

	}
	cout<<js;
	}

	return 0;
}