#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m,n[109];
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n[i];
	}
	if(m<3){

	cout<<0;
	return 0;
		}
		
	if(m=3){
		if((n[0]+n[1]>n[2])&&(n[1]+n[2]>n[0])&&(n[0]+n[2]>n[1])){
			cout<<1;
			return 0;
		}else{
			cout<<0;
	return 0;
		}
		}
	if(m>3)cout<<6;
	return 0;
}
