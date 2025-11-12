#include<iostream>
#include<string>
using namespace std;
string s;
char n[1000005],b;
int a[1000005],k,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s+='A';
	for(int i=0;i<1000000;i++){
		if(s[i]=='A') break;
		else c++;
	}
	
	for(int i=0;i<c;i++){
		if(s[i]>='0' && s[i]<='9'){
			n[k]=int(s[i]);
			k++;
		}
	}
	for(int j=0;j<k;j++){
		for(int i=0;i<j;i++){
			if(n[j]>=n[i]) {
				b=n[j];
				n[j]=n[i];
				n[i]=b;
			}
		}
	}
	for(int i=0;i<k;i++) cout<<n[i];
	return 0;
} 
