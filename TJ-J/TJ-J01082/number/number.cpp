#include<bits/stdc++.h>
using namespace std;
int main(){
//	freomon("number.in",'r');
//	freomon("number.out",'w');
	int max,i=0,c=0,t;
	string(s);
	cin>>s;
	s=s+'*' ;
	while (s[i]!='*'){
		if ((s[i]=='0')||(s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4')||(s[i]=='5')||(s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9')){
			c+=1;
		}
		i+=1;
	}
	
	int a[c]={0};
	
	i=0;
	while (s[i]!='*'){
		if ((s[i]=='0')||(s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4')||(s[i]=='5')||(s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9')){
			
			a[i]=(int(s[i])-48);
		}
		i+=1;
	}
	
	for(int x=0;x<c;x++){
		for (int j=x+1;j<c+1;j++){
			if (a[j]<a[x]){
				t=a[j];
				a[j]=a[x];
				a[x]=t;
			}
		}
	}
	
	for(int x=0;x<c;x++){
		cout<<a[x];
	}
	return 0;
}
