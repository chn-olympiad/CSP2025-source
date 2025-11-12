#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[1000];
	int j=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
			b[j]=a[i];
			j++;
		}
	}
		
		

	while(1){
		int k=1;
		for(int i=0;i<j-1;i++){
			if(b[i]<b[i+1]){
				int d=b[i];
				b[i]=b[i+1];
				b[i+1]=d;
				k=0;
			}
		}
		if(k==1){
			break;
		}
		
	}
	for(int i=0;i<j;i++){
		cout<<b[i];
	}
	
	
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
