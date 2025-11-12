#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	char t[100002];
	int l,j=0;
	cin>>s;
	l=s.length();
	for(int i=0;i<l;i++){
		if (s[i]>='0' && s[i]<='9'){
			t[j]=s[i];
			j++;
		}
			
	}
	sort(t,t+j);
	reverse(t,t+j);
	for (int i=0;i<j+1;i++){
		cout<<t[i];
	}
	return 0;
} 
