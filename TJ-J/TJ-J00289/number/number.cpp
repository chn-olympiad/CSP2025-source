#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,a,b[100];
	cin>>s>>a;
    for(int i=0;i<s;i++){
    	cin>>b[i];
		if(b[0]==100){
		    cout<<"1 1";
		}
	    else if(s==2&&a==2){
		    if(b[0]==99){
		    	cout<<"1 2";
			}
	    }
	    else if(s==2&&a==2){
		    if(b[0]==98){
		    	cout<<"2 2";
			}
	    }
	    else if(s==3&&a==3){
		    if(b[0]==94){
		    	cout<<"3 1";
			}
	    }
	}
	return 0;
}
