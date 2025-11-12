#include<bits/stdc++.h>
using namespace std;

string num0,num1,a;
int num2[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>num0;
	int p = 0;
	for(int j = 0;j<=sizeof(num0);j++){
		switch(num0[j]){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				num1[p] = num0[j];
				p++;
		}
	}
	for(int i = 0;i<p;i++){
		int q = int(num1[i]);
		num2[i] = q-'0';
	}
	int num3[10] = {0};
	for(int i = 0;i<p;i++){
		num3[num2[i]]++;
	}
	for(int i = 9;i>-1;i--){
		for(int  j = 0;j<num3[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
} 
