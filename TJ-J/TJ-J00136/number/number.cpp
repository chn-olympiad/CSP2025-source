#include <bits/stdc++.h>
using namespace std;
char s[1000];
int a[15];
int b[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int i=0;
	while(true){ 
		if(s[i] == '0'){
			a[0]++;
//			cout << 0;
		}
		else if(s[i] =='1'){
			a[1]++;	
//			cout << 1;
		}
		else if(s[i] =='2'){
			a[2]++;	
//			cout << 2;
		}
		else if(s[i] =='3'){
			a[3]++;
//			cout <<3;	
		}
		else if(s[i]=='4'){
			a[4]++;	
//			cout << 4;
		}
		else if(s[i] =='5'){
			a[5]++;	
//			cout << 5;
		}
		else if(s[i] =='6'){
			a[6]++;	
//			cout << 6;
		}
		else if(s[i] =='7'){
			a[7]++;
//			cout << 7;	
		}
		else if(s[i] =='8'){
			a[8]++;	
//			cout << 8;
		}
		else if(s[i] =='9'){
			a[9]++;	
//			cout <<9;
		}
		else break;
		i++; 
	}
	int c = 0;
	for(int j=9;j>=0;j--){
		while(a[j] != 0){
			c++;
			b[c] = j;
			a[j]--;
		}
	}
	for(int i=1;i<=c;i++){
		cout << b[i];
	}
	return 0;
}
