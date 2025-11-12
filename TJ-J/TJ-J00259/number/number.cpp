#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin >> s;
    int n[100001]={0};
	int a = 1;
	for (int i = 0;i<s.length();i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
			n[a] = s[i]-'0';
			a+=1;
		}
	}
	sort(n,n+a);
	for(int i = a-1;i>=1;i--){
		cout << n[i];
	}
	return 0;
}
