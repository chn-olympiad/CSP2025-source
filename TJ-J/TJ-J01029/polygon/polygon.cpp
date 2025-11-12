#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a;
	cin >> a;
	int s[a];
	for (int i=0;i<=a;i++){
		cin >> s[i];
	}
	int n;
	for(int i=0;i<=a;i++){
		if(s[i]>s[i+1]) n = s[i];
		if(s[i]==s[i+1]) n = s[i];
		if(s[i]<s[i+1]) n = s[i+1];
	}
	cout << n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
