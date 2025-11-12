#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("number3.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int l = s.size();
	char num[l], N=0;
	for(int i=0; i<l; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num[N] = s[i];
			N++;
		}
	}
	for(int i=0; i<N; i++){
		if(num[i]=='9') cout<<num[i];
	}
	for(int i=0; i<N; i++){
		if(num[i]=='8') cout<<num[i];
	}
	for(int i=0; i<N; i++){
		if(num[i]=='7') cout<<num[i];
	}
	for(int i=0; i<N; i++){
		if(num[i]=='6') cout<<num[i];
	}
	for(int i=0; i<N; i++){
		if(num[i]=='5') cout<<num[i];
	}
	for(int i=0; i<N; i++){
		if(num[i]=='4') cout<<num[i];
	}
	for(int i=0; i<N; i++){
		if(num[i]=='3') cout<<num[i];
	}
	for(int i=0; i<N; i++){
		if(num[i]=='2') cout<<num[i];
	}
	for(int i=0; i<N; i++){
		if(num[i]=='1') cout<<num[i];
	}
	for(int i=0; i<N; i++){
		if(num[i]=='0') cout<<num[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
