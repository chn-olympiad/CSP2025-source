#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	string s="0";
	int n=0;
	for(int i=0;i<1000000;i++) {
		cin>>a;
		s[i]=a;
		if(s[i]=='0') break;
		
	}
	int o[1000000]={}; 
	for(int i=0;i<1000000;i++){
		if(s[i]>=62 && s[i]<=88){
			n+=0;
		}
		else{
			s[i]=o[i];
			n++;
		} 
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(o[i]<o[j]) o[i],o[j]=o[j],o[i];	
		}
	}
	for(int i=0;i<n;i++){
		cout<<o[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
