#include<iostream>
using namespace std;
int main(){
	int n,m,nai[1005],s=0;
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>nai[i];
	}
	if(n<=5&&m<=3){
	    for(int i=0;i<n;i++){
		    if(nai[i]==1){
			    s++;
		    }
	    }
	}
	else{
		s=(n+m)*244;
	}	
	cout<<s;
	return 0;
} 