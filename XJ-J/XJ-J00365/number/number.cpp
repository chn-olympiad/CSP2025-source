#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int c[10];
	for(int i=0;i<=9;i++){
		c[i]=0;
	}
	for(int i=0;i<=10;i++){
		if(a[i]=='0'){
			c[0]++;
		}else if(a[i]=='1'){
			c[1]++;
		}else if(a[i]=='2'){
			c[2]++;
		}else if(a[i]=='3'){
			c[3]++;
		}else if(a[i]=='4'){
			c[4]++;
		}else if(a[i]=='5'){
			c[5]++;
		}else if(a[i]=='6'){
			c[6]++;
		}else if(a[i]=='7'){
			c[7]++;
		}else if(a[i]=='8'){
			c[8]++;
		}else if(a[i]=='9'){
			c[9]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=c[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
