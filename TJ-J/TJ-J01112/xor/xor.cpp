#include<iostream>
using namespace std;
int s[1000000];
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int a,t,l,n=0,sum=0;
    cin>>a>>t;
    for(int i = 1;i<=a;i++){
    	cin>>s[i];
	}
	for(int i = 1;i<=a;i++){
		for(int j = i;j<=a;j++){
			if(i == j){
				if(s[i] == t){
					sum+=1;
					cout<<t<<' '<<s[i]<<"the example1"<<endl;
					cout<<i<<' '<<j<<"answer1"<<endl;
				}
			}
			else{
				for(int k = i ;k<j;k++){
					n = n ^ s[k];
					
				}
				
				if(n==t){
					sum+=1;
					cout<<n<<"the example 2"<<endl;
					cout<<i<<' '<<j<<"answer2"<<endl;
				}
			}
			n = 0;
		}
	}
	cout<<sum;
	return 0;
}

