#include<bits/stdc++.h>
using namespace std;
int main(){
	//rfresh("number.in","r",stdin);
	//rfresh("number.out","w",stdout);
	string s,num,n;
	char m;
	num="1234567890";
	int lenth=0,k=0;
	cin>>s;
	do{
		lenth++;
	}while(s[lenth]!='\0');
	
	for(int i=0;i<=lenth-1;i++){
		for(int j=0;j<=9;j++){
			if(s[i]==num[j]){
				n+=s[i];
			}
		}
	}
	cout<<n<<endl;
	lenth=0;
	do{
		lenth++;
	}while(n[lenth]!='\0');
	for(int i=0;i<=lenth-1;i++){
		k=0;
		while(k<=lenth-1){
			if(int(n[k])<int(n[k+1])){
				m=n[k+1];
				n[k+1]=n[k];
				n[k]=m;
			}
			k++;
		}		
	}
	cout<<n;
	
	
	//rclose(stdin);
	//rclose(stdout);
	return 0;
} 
