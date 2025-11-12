#include<bits\stdc++.h>
using namespace std;
	char s[1000000];
	int a[111111];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int b=strlen(s);
	int k=0;
	for(int i=0;i<b;i++){
		
		if(s[i]<='9'&&s[i]>='1'){
			a[k]=s[i]-48;
			k++;
		}
	}	
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(a[j]<a[j+1]){
				int c=a[j];
				a[j]=a[j+1];
				a[j+1]=c;
			}
			
		}	
	}
	for(int i=0;i<k;i++)cout<<a[i];
	
	return 0;
}
