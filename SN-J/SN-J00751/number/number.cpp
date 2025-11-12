#include <bits/stdc++.h>
using namespace std;
int d[15];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	for(int i=1;i<=10;i++){
		d[i]=0;
	}
	string s;
	cin >> s;
	for(int i=0;i<=1000000;i++){
		if(s[i]=='9'){
			d[9]++;
			cout <<i;
		}
		if(s[i]=='8'){
			d[8]++;
						cout <<i<<endl;
		}
		if(s[i]=='7'){
			d[7]++;
						cout <<i<<endl;
		}
		if(s[i]=='6'){
			d[6]++;
						cout <<i<<endl;
		}
		if(s[i]=='5'){
			d[5]++;
						cout <<i<<endl;
		}
		if(s[i]=='4'){
			d[4]++;
						cout <<i<<endl;
		}
		if(s[i]=='3'){
			d[3]++;
						cout <<i<<endl;
		}
		if(s[i]=='2'){
			d[2]++;
						cout <<i<<endl;
		}
		if(s[i]=='1'){
			d[1]++;
						cout <<i<<endl;
		}
		if(s[i]=='0'){
			d[0]++;
						cout <<i<<endl;
		}
		if(s[i]=='\n'){
			return 0;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=d[i];j++){
			cout <<i;
			
		}
	}
	return 0;
}
