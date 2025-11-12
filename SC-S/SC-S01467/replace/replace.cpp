#include<bits/stdc++.h>
using namespace std;
char b[1000005];
int s,a;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	
	
	for(int i=1;i<=n;i++){
		s=(int)b[i];
		for(int i=1;i<=s/3;i++){
			if(i>=s){
				a=i%s;
			}else{
				a=s%i;
			}
			if(a%3==0){
				cout<<0;
			}
			if(a%3==2){
				cout<<1;
			}
			if(a%3==1){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}