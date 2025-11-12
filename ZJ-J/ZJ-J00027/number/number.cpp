#include<bits/stdc++.h>
using namespace std;

int num[10];
string s;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	int k=0;
	
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			printf("%d", i);
		}
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
	
}

