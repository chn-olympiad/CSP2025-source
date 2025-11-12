#include <bits/stdc++.h>
using namespace std;
char t;
int i=0,l=0,b[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//
	
	
	scanf("%d",b);

	
	for(int j=0;j<l;j++){
		for(int k=0;k<j;k++){
			if(b[k]<b[k+1]){
				i=b[k];
				b[k]=b[k+1];
				b[k+1]=i;
			}
		}
	}
	for(int j=0;j<l;j++){
		cout<<b[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
