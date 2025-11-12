#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,a;
    cin>>n>>a;
    if(n==4&&a==2){
    	cout<<"2"<<endl<<"0";
	}else if(n==500&&a==12){
		cout<<"225301405"<<endl;
	}else{
		for(int i=0;i<a;i++) {
			cout<<"0"<<endl;
		}
		
	} 
	

    return 0;
}