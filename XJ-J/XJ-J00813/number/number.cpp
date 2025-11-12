#include<bits/stdc++.h>
using namespace std;
char a[1000006];
int b[12],c[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("numbre.out","w",stdout);
	int j=0,k=0,g=0;
	cin>>a;
	j=strlen(a);
	for(int i=0;i<j;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--) {
		if(i!=0){
			for(int k=0;k<b[i];k++){
				cout<<i;
				g=1;
			}
		}
		else if(i==0&&g==1){
			for(int k=0;k<b[i];k++){
				cout<<i;
			}
		}
		else if(i==0&&g==0){
			cout<<0;
		}
	}
	return 0;
} 
