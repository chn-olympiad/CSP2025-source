#include <iostream>
using namespace std;
string x,y,z;
char a;
int m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i]<='9' && x[i]>='0'){
			y+=x[i];
		}
	}
	for(int i=0;i<y.size();i++){
		a=y[i];
		for(int j=0;j<y.size();j++){
			if(y[j]>=a){
				a=y[j];
				m=j;
			}
		}
		y[m]='0';
		z+=a;
	}
	cout<<z;
	return 0;
}
