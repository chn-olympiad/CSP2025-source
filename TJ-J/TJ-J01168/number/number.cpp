#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000006];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size() == 1){
		cout<<s;
		return 0;
	}
	int temp = 0;
	for(int i = 0;i<s.size();i++){
		if(s[i] == '0'||s[i] == '1'||s[i] == '2'||s[i] == '3'||s[i] == '4'||s[i] == '5'||s[i] == '6'||s[i] == '7'||s[i] == '8'||s[i] == '9'){
			a[temp] = s[i] - '0';
			temp++;
		}
	}
	for(int i = 9;i>=0;i--){
		for(int j = 0;j<temp;j++){
			if(a[j] == i){
				cout<<a[j];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
